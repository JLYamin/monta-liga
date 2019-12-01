#include "tabelas.hpp"

// Tabela de símbolos, uso e definições
vector<SymbolRow> symbolTable;
vector<UseRow>    useTable;
vector<DefineRow> defineTable;

// Construtor da linha da tabela de definições
DefineRow::DefineRow(string s, int a) {
  symbol = s;
  address = a;
}

//Funções para a tabela de uso
// Encapsula a tabela de usos e adiciona um símbolo PUBLIC à ela
void addDefine(string s) {
  DefineRow row(s, 0);
  defineTable.push_back(row);
}

// Atualiza o valor do símbolo público
void updateDefine(string s, int a) {
  for (size_t i = 0; i < defineTable.size(); i++) {
    if (defineTable[i].symbol == s) {
      defineTable[i].address = a;
      return;
    }
  }
  cout << "Não existe esse símbolo na tabela de definições!!" << endl;
}

// Construtor da linha da tabela de usos
UseRow::UseRow(string s, int a) {
  symbol = s;
  address = a;
}

//Funções para a tabela de uso
// Encapsula a tabela de usos e adiciona um símbolo à ela
void addUse(string s, int a) {
  UseRow row(s, a);
  useTable.push_back(row);
}

// Construtores da linha da tabela de símbolos
SymbolRow::SymbolRow(string s, int a, bool d, bool e) {
  symbol = s;
  address = a;
  is_defined = d;
  is_extern = e;
  pendencies.push(-1);
}

// Método para ser chamado quando a função for definida
stack<int> SymbolRow::defineSymbol(int a) {
  try
  {
    if (is_defined)
    {
      throw 1;
    }
    else
    {
      is_defined = true;
      address = a;
      cout << "O endereço do símbolo '" << symbol << "' foi definido como " << address << endl;
      return pendencies;
    }
  }
  catch (int error)
  {
    cerr << "[ERRO] SymbolRow::defineSymbol: O símbolo '" << symbol << "' já está definido.\n";
    return pendencies;
  }
}

// Marca o símbolo como externo
void SymbolRow::makeExtern() {
  is_extern = true;
  address = 0;
}

// Adiciona uma nova pendência à lista
void SymbolRow::newPendency(int p) {
  pendencies.push(p);
}

// Retira da lista uma pendência e retorna a mesma
int SymbolRow::removePendency() {
  int return_value = 0;
  try
  {
    if (pendencies.empty())
    {
      throw 1;
    }
    else
    {
      return_value = pendencies.top();
      pendencies.pop();
      return return_value;
    }
  }
  catch (int error)
  {
    cerr << "[ERRO] SymbolRow::removePendency: A pilha do símbolo '" << symbol << "' está vazia.\n";
    return return_value;
  }
}

// Encapsula a tabela de símbolos e adiciona um símbolo à ela
void addSymbol(string s, int a, bool d, bool e) {
  if (checkSymbol(s)) {
    cerr << "[ERRO] addSymbol: Símbolo " << s << " já existe na tabela de símbolos" << endl;
  } else {
    SymbolRow symbol(s, a, d, e);
    symbolTable.push_back(symbol);
    cout << "Adicionado o símbolo '" << s << "' na tabela de símbolos" << endl;
  }
}

// Retira a pendência do topo a partir do nome do símbolo e retorna o endereço da mesma
int resolvePendency(string name) {

  for (size_t i = 0; i < symbolTable.size(); i++) {
    if (symbolTable[i].symbol == name) {
      return symbolTable[i].removePendency();
    }
  }

  try {
    throw 1;
  } catch(int error) {
    cerr << "[ERRO] resolvePendency: Não foi encontrado o símbolo '" << name << "' na tabela de símbolos" << endl;
  }

  return -1;
}

// Adiciona uma pendência do endereço value no símbolo name escolhido
void addPendency(string name, int value) {
  for (size_t i = 0; i < symbolTable.size(); i++) {
    if (symbolTable[i].symbol == name) {
      symbolTable[i].newPendency(value);
      return;
    }
  }

  try {
    throw 1;
  } catch (int error) {
    cerr << "[ERRO] addPendency: Não foi encontrado o símbolo '" << name << "' na tabela de símbolos" << endl;
  }
}

// Verifica se o símbolo já existe na tabela de símbolos
bool checkSymbol(string name) {
  for (size_t i = 0; i < symbolTable.size(); i++) {
    if (symbolTable[i].symbol == name) {
      return true;
    }
  }
  return false;
}

// [??] Atualiza o endereço do símbolo na tabela de símbolos
void updateSymbol(string name, int value) {
  for (size_t i = 0; i < symbolTable.size(); i++) {
    if (symbolTable[i].symbol == name) {
      symbolTable[i].defineSymbol(value);
      return;
    }
  }

  try {
    throw 1;
  } catch (int error) {
    cerr << "[ERRO] updateSymbol: Não foi encontrado o símbolo '" << name << "' na tabela de símbolos" << endl;
  }
}

// Torna o símbolo uma variável externa
void externalizeSymbol(string name) {
  for (size_t i = 0; i < symbolTable.size(); i++) {
    if (symbolTable[i].symbol == name) {
      symbolTable[i].makeExtern();
      return;
    }
  }

  try {
    throw 1;
  } catch (int error) {
    cerr << "[ERRO] externalizeSymbol: Não foi encontrado o símbolo '" << name << "' na tabela de símbolos" << endl;
  }
}

// Verifica se o símbolo é externo
bool isSymbolExternal(string name) {
  for (size_t i = 0; i < symbolTable.size(); i++) {
    if (symbolTable[i].symbol == name) {
      return symbolTable[i].is_extern;
    }
  }
  return false;
}

// Atualiza a tabela de definições tendo como base a tabela de símbolos
void updateTables() {
  string name;
  for(size_t i = 0; i < defineTable.size(); i++) {
    name = defineTable[i].symbol;
    for (size_t j = 0; j < symbolTable.size(); j++) {
      if (symbolTable[j].symbol == name) {
        defineTable[i].address = symbolTable[j].address;
        cout << "Símbolo " << name << " da tabela de definições atualizado para " << defineTable[i].address << endl;
      }
    }
  }
}
