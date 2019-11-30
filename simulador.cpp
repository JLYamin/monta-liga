#include "preprocessador.hpp"
#include "simulador.hpp"

// Variáveis globais porque não quero mexer com ponteiro
vector <string> code;         // Vetor do código
vector<string>::iterator it;  // Vetor do iterador
int jmp;                      // Flag para verificar se foi feito um salto

int main (int numero_argumentos, char* argumentos_terminal[]) {
  ifstream objFile;
  string nome_pasta, nome_arquivo;

  nome_arquivo = argumentos_terminal[1];
  nome_pasta = "";

  objFile.open(nome_pasta+nome_arquivo);

  stringstream strStream;
  strStream << objFile.rdbuf();
  string file = strStream.str();

  codeExecute(file);

  return 0;
}


void codeExecute(string file) {
  code = fileToVector(file);
  int acc, opcode, arg1, arg2;
  it = code.begin();
  while (it != code.end()) {
    jmp = 0;
    opcode = stoi(*it);
    switch (opcode) {
    case 9:
      arg1 = stoi(*(++it));
      arg2 = stoi(*(++it));
      copyInstruc(opcode, arg1, arg2);
      break;
    case 1: case 2: case 3: case 4: case 5: case 6:
    case 7: case 8: case 10: case 11: case 12: case 13:
      arg1 = stoi(*(++it));
      acc = execInstruc(opcode, arg1, acc);
      break;
    case 14:
      cout << "FIM DA EXECUÇÃO" << endl;
      return;
      break;
    default:
      cout << opcode << " não é uma instrução" << endl;
      break;
    }
    if (jmp == 0) {             // Verifica se não foi feito um pulo
      if (it != code.end()) {   // Se não tiver chegado no final do código, executar a próxima instrução
        ++it;
      } else {
        return;
      }
    }
  }
}

int execInstruc(int opcode, int address, int acc) {
  int arg = stoi(code[address]);
  switch (opcode) {
  case 1:
    acc = acc + arg;
    cout << "ADD foi executado e ACC = " << acc << endl;
    break;
  case 2:
    acc = acc - arg;
    cout << "SUB foi executado e ACC = " << acc << endl;
    break;
  case 3:
    acc = acc * arg;
    cout << "MULT foi executado e ACC = " << acc << endl;
    break;
  case 4:
    acc = acc / arg;
    cout << "DIV foi executado e ACC = " << acc << endl;
    break;
  case 5:
    it = code.begin() + arg;
    cout << "JMP foi executado e o valor do acumulador não foi alterado. ACC = " << acc << endl;
    jmp = 1;
    break;
  case 6:
    if (acc < 0) {
      it = code.begin() + arg;
      cout << "JMPN foi executado porque ACC = " << acc << endl;
      jmp = 1;
    } else {
      cout << "JMPN não foi realizado porque ACC = " << acc << endl;
    }
    break;
  case 7:
    if (acc > 0) {
      it = code.begin() + arg;
      cout << "JMPP foi executado porque ACC = " << acc << endl;
      jmp = 1;
    } else {
      cout << "JMPP não foi realizado porque ACC = " << acc << endl;
    }
    break;
  case 8:
    if (acc == 0) {
      it = code.begin() + arg;
      cout << "JMPZ foi executado porque ACC = " << acc << endl;
      jmp = 1;
    } else {
      cout << "JMPZ não foi realizado porque ACC = " << acc << endl;
    }
    break;
  case 10:
    acc = arg;
    cout << "LOAD foi executado e ACC = " << acc << endl;
    break;
  case 11:
    code[address] = to_string(acc);
    cout << "STORE foi executado e o valor do acumulador não foi alterado. ACC = " << acc << endl;
    cout << "O valor no endereço " << address << " foi alterado para " << code[address] << endl;
    break;
  case 12:
    cout << "Favor, inserir um valor númerico: ";
    cin >> code[address];
    cout << "INPUT foi executado e o valor do acumulador não foi alterado. ACC = " << acc << endl;
    cout << "O valor no endereço " << address << " foi alterado para " << code[address] << endl;
    break;
  case 13:
    cout << "O valor de saída é " << code[address] << endl;
    cout << "OUTPUT foi executado e o valor do acumulador não foi alterado. ACC = " << acc << endl;
    break;
  }
  return acc;
}

void copyInstruc(int opcode, int arg1, int arg2) {
  cout << "COPY foi executado e o valor do acumulador não foi alterado." << endl;
  code[arg2] = code[arg1];
  cout << "O valor no endereço " << arg2 << " foi alterado para " << code[arg2] << endl;
}