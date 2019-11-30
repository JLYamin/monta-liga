#include "analisador.hpp"



int main(int numero_argumentos, char *argumentos_terminal[])
{
  string nome_arquivo1, nome_arquivo2, nome_pasta, codigo_objeto;
  Assembler* montador = new Assembler();
  nome_pasta = "";

  if (numero_argumentos == 3) {
    nome_arquivo1 = argumentos_terminal[1];
    nome_arquivo2 = argumentos_terminal[2];
    cout << "Recebido os arquivos '" << nome_arquivo1 << "' e '" << nome_arquivo2  << "' como argumentos. Montando..." << endl;
  } else if (numero_argumentos == 2) {
    nome_arquivo1 = argumentos_terminal[1];
    cout << "Recebido o arquivo '" << nome_arquivo1 << "' como argumento. Montando..." << endl;
    codigo_objeto = montador->monta_texto(nome_arquivo1, nome_pasta);
  } else {
    cout << "ERRO: Passe um ou dois arquivos como argumento para o montador" << endl;
    return 0;
  }

  return 0;
}
