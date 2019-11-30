#ifndef ESCRITOR_H
#define ESCRITOR_H

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <string>
#include <sstream>

using namespace std;

// Ao passar a string de código e o nome do arquivo original, cria um arquivo .pre
void createFilePre (string code, string filename);


// Ao passar a string de código e o nome do arquivo original, cria um arquivo .obj
void createFileObj (string code, string filename);

#endif