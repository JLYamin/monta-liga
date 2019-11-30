/* Módulo criado para encapsular funções de leitura e escrita

*/

#include "leitor.hpp"

string Leitor::carrega_texto(string caminho_do_arquivo_completo = "entradas_asm/bin.asm")
{
  ifstream infile (caminho_do_arquivo_completo);
  string data, linha;

  if (infile.is_open()) {
    
    while( getline (infile, linha) )
    {
      data += linha + "\n";  
    }

    transform(data.begin(), data.end(), data.begin(), ::toupper);

    regex multiplos_espacos_comeco_linha("\n([\t ]+)");
    regex multiplos_espacos("([\t ]+)");
    regex multiplos_saltos_linha("(\n+)");
    data = regex_replace(data, multiplos_espacos, " ");
    data = regex_replace(data, multiplos_espacos_comeco_linha, "\n");
    data = regex_replace(data, multiplos_saltos_linha, "\n");
  } else {
    return "";
    cout << "Problemas ao ler arquivo";
  }
    return data;
}

/*
int main(){
  Leitor leitura;
  cout << leitura.texto_lido;
  return 0;
}
*/