#include "escritor.hpp"
#include "tabelas.hpp"

extern vector<UseRow> useTable;
extern vector<DefineRow> defineTable;

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
void createFileObj(string code, string filename, int size) {
  size_t index = filename.find_last_of(".");
  string rawname = filename.substr(0, index);
  string objname = rawname + ".obj";

  ofstream objfile;
  objfile.open(objname);
  objfile << "N: " << rawname << endl;
  objfile << "S: " << size << endl;
  objfile << generateTableString() << endl;
  objfile << "T: ";
  objfile << code;
  objfile.close();
}

// Gera as informações das tabelas na forma de texto
string generateTableString() {
  string useString = "U: ", defineString = "D: ";

  for (size_t i = 0; i < useTable.size(); i++) {
    useString += useTable[i].symbol + " " + to_string(useTable[i].address);
    if (i != useTable.size() - 1) {
      useString += " ";
    }
  }

  for (size_t i = 0; i < defineTable.size(); i++) {
    defineString += defineTable[i].symbol + " " + to_string(defineTable[i].address);
    if (i != defineTable.size() - 1) {
      defineString += " ";
    }
  }

  return useString + "\n" + defineString;
}
