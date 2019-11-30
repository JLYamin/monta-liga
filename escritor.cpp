#include "escritor.hpp"


// Ao passar a string de código e o nome do arquivo original, cria um arquivo .pre
void createFilePre(string code, string filename) {
  size_t index = filename.find_last_of(".");
  string rawname = filename.substr(0, index);
  string prename = rawname + ".pre";

  ofstream prefile;
  prefile.open(prename);
  prefile << code;
  prefile.close();
}

// Ao passar a string de código e o nome do arquivo original, cria um arquivo .obj
void createFileObj(string code, string filename) {
  size_t index = filename.find_last_of(".");
  string rawname = filename.substr(0, index);
  string objname = rawname + ".obj";

  ofstream objfile;
  objfile.open(objname);
  objfile << code;
  objfile.close();
}
