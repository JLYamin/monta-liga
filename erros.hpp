#ifndef ERROS_H
#define ERROS_H

#include <fstream>
#include <iostream>
#include <algorithm>
#include <regex>
#include <stack>

using namespace std;

class ErrorPrinter {
  public:
  string result = "";

  void addError(int line, int type, string message);
  void printError();
};

#endif