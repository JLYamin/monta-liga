#ifndef TABELAS_H
#define TABELAS_H

#include <fstream>
#include <iostream>
#include <algorithm>
#include <regex>
#include <stack>

using namespace std;

// Classe para a linha da tabela de definições


// Classe para a linha da tabela de símbolos
class SymbolRow {
public:
  string symbol;
  int address;
  bool is_defined;
  bool is_extern;
  stack <int> pendencies;

  SymbolRow(string s, int a, bool d, bool e);
  stack<int> defineSymbol(int a);
  void newPendency(int p);
  int removePendency();
};

// Encapsula a tabela de símbolos e adiciona um símbolo à ela
void addSymbol(string s, int a, bool d, bool e);

// Retira a pendência do topo a partir do nome do símbolo e retorna o endereço da mesma
int resolvePendency(string name);

// Adiciona uma pendência do endereço value no símbolo name escolhido
void addPendency(string name, int value);

// Verifica se o símbolo já existe na tabela de símbolos
bool checkSymbol (string name);

// [??] Atualiza o endereço do símbolo na tabela de símbolos
void updateSymbol (string name, int value);

#endif