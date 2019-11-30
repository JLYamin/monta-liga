#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include "preprocessador.hpp"

using namespace std;

void codeExecute (string code);                   // Para executar o código objeto
int execInstruc(int opcode, int arg, int acc);    // Para executar instruções de um operando
void copyInstruc(int opcode, int arg1, int arg2); // Para executar instruções de dois operandos (COPY)

#endif