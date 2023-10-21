#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include "gerais.hpp"

using namespace std;

map <string, float> sands; // map que vai guardar o nome e o preço do sanduiche
map <string, float> sucos; // map que vai guardar o nome e o preço do suco
map <string, pedidos> carrinho; // map que vai guardar o nome e o preço dos lanches no carrinho

void listarSand(){ // Função que lista todos os sanduíches cadastrados.

  for (auto it=sands.begin(); it != sands.end(); it++){
    cout << "Sanduiche: " << it->first << endl;
    cout << "Preço: " << it->second << endl;
  }
}

void listarSucos(){ // Função que lista todos os sucos cadastrados.

  for (auto it=sucos.begin(); it != sucos.end(); it++){
    cout << "Suco: " << it->first << endl;
    cout << "Preço: " << it->second << endl;
  }
}

void salvarSands(){ // Função que salva os sanduíches no arquivo sands.txt.
  
  fstream arquivo;
  arquivo.open("sands.txt", ios::out);

  for (auto it = sands.begin(); it != sands.end(); it++){

    arquivo << it->first << endl;
    arquivo << it->second << endl;
  }
  arquivo.close();
}

void salvarSucos(){ // Função que salva os sucos no arquivo sucos.txt.
  
  fstream arquivo;
  arquivo.open("sucos.txt", ios::out);

  for (auto it = sucos.begin(); it != sucos.end(); it++){

    arquivo << it->first << endl;
    arquivo << it->second << endl;
  }
  arquivo.close();
}

void lerSands(){ // Função que ler os sanduíches salvos em sands.txt ao iniciar o programa.

  vector<string> linhas;
  fstream arquivo;
  arquivo.open("sands.txt", ios::in);
  string temp;
  while (getline(arquivo,temp)){
    linhas.push_back(temp);
  }
  arquivo.close();
  if (linhas.empty())
    cout << "Arquivo vazio!" << endl;
  else {
    for (int i = 0; i < linhas.size(); i+=2){
      sands[linhas[i]] = stof(linhas[i+1]);
    }
  }
}

void lerSucos(){ // Função que ler os sucos salvos em sucos.txt ao iniciar o programa.

  vector<string> linhas;
  fstream arquivo;
  arquivo.open("sucos.txt", ios::in);
  string temp;
  while (getline(arquivo,temp)){
    linhas.push_back(temp);
  }
  arquivo.close();
  if (linhas.empty())
    cout << "Arquivo vazio!" << endl;
  else {
    for (int i = 0; i < linhas.size(); i+=2){
      sucos[linhas[i]] = stof(linhas[i+1]);
    }
  }
}