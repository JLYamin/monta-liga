#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <regex>

using namespace std;

class Leitor
{
    public:
    string carrega_texto(string);

    private:
    string texto_lido;
};