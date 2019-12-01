#include "preprocessador.hpp"

// Executa o pré processamento
string ifProcessor(string stringFile, int numArgs) {
  // Transforma a string em vector
  vector<string> code = fileToVector(stringFile);

  //Usa o vector gerado por ifUppercase para mandar para ifLowercase que completa a lista de labels
  vector<string> labels = ifLowercase(code, ifUppercase(code));
  // Agora que temos um vetor de labels, vamos procurar os valores das mesmas
  vector<string> processedCode = ifDecider(code, labels);

  // Agora temos que deletar o inicio do código onde aparecem os EQU (prof disse que sempre apareceriam no início)
  vector<string>::iterator it = processedCode.begin();
  while (*it != "SECTION") {
    processedCode.erase(it); // Apaga as linhas até aparecer um SECTION
  }
  if (numArgs == 3) {
    processedCode.erase(processedCode.end() - 2);
  }
  return vectorToString(processedCode);
}

// Verifica as labels e decide se as linhas se manterão ou não
vector<string> ifDecider(vector<string> code, vector<string> labels) {
  int value, endline;
  vector<string>::iterator itLabel;
  vector<string>::iterator itCode;
  for (itLabel = labels.begin(); itLabel != labels.end(); ++itLabel) {
    endline = 0;                                         // Redefine a flag
    value = findLabelValue(code, *itLabel);
    if (value == 1) {
      itCode = find(code.begin(), code.end(), *itLabel); // Procura a ocorrência do IF do label
      code.erase(itCode);                                // Apaga a palavra onde ela aparece
      code.erase(itCode);                                // Apaga o endl
      code.erase(itCode - 1);                            // Apaga o IF
    } else {
      itCode = find(code.begin(), code.end(), *itLabel); // Procura a ocorrência do IF do label
      code.erase(itCode);                                // Apaga a palavra onde ela aparece
      code.erase(itCode);                                // Apaga o endl
      code.erase(itCode - 1);                            // Apaga o IF
      itCode--;
      while(endline == 0) {                              // Apaga também a linha que viria depois
        if (*itCode == "\n")
          endline = 1;
        code.erase(itCode);
      }
    }
  }
  return code;
}
// Procura o valor correspondente à label solicitada
int findLabelValue(vector<string> code, string label) {
  string search = label + ":";
  vector<string>::iterator it = find(code.begin(), code.end(), search);
  if (it != code.end()) {
    return stoi(*(it + 2));
  } else {
    cout << "[ADICIONAR COMO ERRO SEMANTICO] Não existe o valor dessa label!";
    return -1;
  }
}

// Verifica as labels posteriores aos ifs maiusculos
vector<string> ifUppercase(vector<string> vec) {
  vector<string> labels;
  vector<string>::iterator it = vec.begin();

  while (it != vec.end()) {
    it = find(it, vec.end(), "IF");
    if (it != vec.end()) {
      it++;
      labels.push_back(*it);
    }
  }

  return labels;
}

// Transforma o vetor em string novamente
string vectorToString(vector<string> code) {
  string result = "";
  vector<string>::iterator it = code.begin();
  for (; it != code.end(); ++it) {
    result += *it;
    if (*it != "\n" && *(it + 1) != "\n")
      result += " ";
  }
  return result;
}

// Verifica e completa as labels posteriores dos ifs com os minusculos
vector<string> ifLowercase(vector<string> vec, vector<string> labels) {
  vector<string>::iterator it = vec.begin();

  while (it != vec.end())
  {
    it = find(it, vec.end(), "if");
    if (it != vec.end())
    {
      it++;
      labels.push_back(*it);
    }
  }

  return labels;
}

vector<string> fileToVector(string file) {
  string s;
  vector<string> result;
  istringstream streamstr(file);
  while (getline(streamstr, s)) {
    vector<string> v = split(s);
    v.push_back("\n");
    result.insert(result.end(), v.begin(), v.end());
  }
  return result;
}

vector<string> split(const string &s) {
  vector<string> ret;
  typedef string::size_type string_size;
  string_size i = 0;

  // invariant: we have processed characters [original value of i, i)
  while (i != s.size())
  {
    // ignore leading blanks
    // invariant: characters in range [original i, current i) are all spaces
    while (i != s.size() && isspace(s[i]))
      ++i;

    // find end of next word
    string_size j = i;
    // invariant: none of the characters in range [original j, current j)is a space
    while (j != s.size() && !isspace(s[j]))
      j++;

    // if we found some nonwhitespace characters

      // copy from s starting at i and taking j - i chars
      ret.push_back(s.substr(i, j - i));
      i = j;

  }
  return ret;
}