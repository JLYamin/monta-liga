#include "erros.hpp"

void ErrorPrinter::addError(int line, int type, string message)
{
  
  switch (type)
  {
  case 1:
    result += "Erro léxico: " + message;
    result += "\n";
    break;

  case 2:
    result += "Erro sintático: " + message;
    result += "\n";
    break;

  case 3:
    result += "Erro semântico: " + message;
    result += "\n";
    break;
  }
}
void ErrorPrinter::printError() {
  cout << result;
}