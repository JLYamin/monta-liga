#ifndef PREPROCESSADOR_H
#define PREPROCESSADOR_H

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <string>
#include <sstream>

using namespace std;

// COMO UTILIZAR: Basta chamar a função ifProcessor e passar para ela o arquivo em forma de string. Ela retornará, também em forma de string, o arquivo pré-processado
string ifProcessor (string stringFile, int numArgs);
// ifProcessor dividido em partes:
vector<string> ifUppercase(vector<string> vec);                         // Procura e pega as labels verificadas pelo IF
vector<string> ifLowercase(vector<string> vec, vector<string> labels);  // Procura e pega as labels verificadas pelo if

// Verifica as labels e decide se as linhas se manterão ou não
vector<string> ifDecider(vector<string> code, vector<string> labels);
// Procura o valor correspondente à label solicitada
int findLabelValue(vector<string> code, string label);

// Transforma o vetor em string novamente
string vectorToString (vector<string>);

// Tratamento da string, para transformá-la em vector
vector<string> fileToVector (string file);
vector<string> split(const string &s);

#endif