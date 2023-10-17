#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include "funcs.hpp"

using namespace std;

map <string, float> sands; // map que vai guardar o nome e o preço do sanduiche
map <string, float> sucos; // map que vai guardar o nome e o preço do suco
map <string, float> carrinho; // map que vai guardar o nome e o preço dos lanches no carrinho


// Funções gerais


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


// Funções do cliente


void escolherSand(string nome){ // Função que escolhe o sanduiche e adiciona ao carrinho.
  carrinho[nome] = sands[nome];
}

void escolherSuco(string nome){ // Função que escolhe o suco e adiciona ao carrinho.
  carrinho[nome] = sucos[nome];
}

void excluirLanche(string nome){ // Função que exclui um lanche do carrinho.
  carrinho.erase(nome);
}

void verCarrinho(){ // Função que mostra todos os lanches do carrinho.

  cout << "Lanches no carrinho:" << endl;
  for (auto it=carrinho.begin(); it != carrinho.end(); it++){
    cout << it->first << endl;
  }
}

float valorLanche(){ // Função que calcula o valor total dos lanches no carrinho.

  float preco = 0.0;
  for (auto it = carrinho.begin(); it != carrinho.end(); it++){
    preco += it->second;
  }
  return preco;
}

void menuCliente(){ // Função que mostra o menu do cliente.

  int aux = 0;
  int op;
  string nome;
  float preco;

  do {

    system("cls");
    //system("clear");

    cout << "O que deseja fazer ?" << endl;
    cout << "1- Listar todos os sanduíches cadastrados" << endl;
    cout << "2- Listar todos os sucos cadastrados" << endl;
    cout << "3- Escolher o lanche" << endl;
    cout << "4- Calcular o valor do lanche" << endl;
    cout << "5- Ver carrinho" << endl;
    cout << "6- Excluir item do carinho" << endl;
    cout << "7 - Sair" << endl;

    cin >> op;
    cin.get();
    switch(op){
      case 1:
        listarSand();
        break;
      case 2:
        listarSucos();
        break;
      case 3:
        int temp;
        cout << "O que você vai querer?" << endl;
        cout << "1- Sanduíche" << endl;
        cout << "2- Suco" << endl;
        cout << "3- Sanduíche + Suco" << endl;
        cin >> temp;
        cin.get();
        if (temp == 1){
          listarSand();
          cout << "Qual sanduiche você vai querer? ";
          getline(cin,nome);
          while (sands.find(nome) == sands.end()){
            cout << "Não temos esse sanduíche! Por favor escolher outro: ";
            getline(cin,nome);
          }
          escolherSand(nome);
        } else if (temp == 2){
          listarSucos();
          cout << "Qual suco você vai querer? ";
          getline(cin,nome);
          while (sucos.find(nome) == sucos.end()){
            cout << "Não temos esse suco! Por favor escolher outro: ";
            getline(cin,nome);
          }
          escolherSuco(nome);
        } else {
          listarSand();
          cout << "Qual sanduiche você vai querer? ";
          getline(cin,nome);
          while (sands.find(nome) == sands.end()){
            cout << "Não temos esse sanduíche! Por favor escolher outro: ";
            getline(cin,nome);
          }          
          escolherSand(nome);
          listarSucos();
          cout << "Qual suco você vai querer? ";
          getline(cin,nome);
          while (sucos.find(nome) == sucos.end()){
            cout << "Não temos esse sanduíche! Por favor escolher outro: ";
            getline(cin,nome);
          }
          escolherSuco(nome);
        }
        break;
      case 4:
        cout << "Preço do lanche: " << valorLanche() << endl;
        break;
      case 5:
        verCarrinho();
        break;
      case 6:
        verCarrinho();
        cout << "Qual lanche você deseja excluir do carrinho: ";
        getline(cin,nome);
        excluirLanche(nome);
        break;
      case 7:
        aux = 1;
        break;
      default:
        cout << "Comando invalido!";
    }

    cin.get();
    
  } while (aux == 0);
}


// Funções do gerente 


void cadastrarSand(string nome, float preco){ // Função que cadastra um novo sanduíche.
  sands[nome] = preco;  
}

void cadastrarSuco(string nome, float preco){ // Função que cadastra um novo suco.
  sucos[nome] = preco;
}

void excluirSand(string nome){ // Função que exclui um sanduíche.
  sands.erase(nome);
}

void excluirSuco(string nome){ // Função que exclui um suco.
  sucos.erase(nome);
}

void menuGerente(){ // Função que mostra o menu do gerente.

  string senhaP = "gerente123";
  string senha;
  cout << "Digite a senha: ";
  cin >> senha;

  while (senhaP.compare(senha) != 0){
    cout << "Senha invalida!" << endl << "Tente novamente: ";
    cin >> senha;
  }

  int aux = 0;
  int op;
  string nome;
  float preco;

  do {

    system("cls");
    //system("clear");

    cout << "O que deseja fazer ?" << endl;
    cout << "1- Listar todos os sanduíches cadastrados" << endl;
    cout << "2- Listar todos os sucos cadastrados" << endl;
    cout << "3- Adicionar um novo sanduíche" << endl;
    cout << "4- Adicionar um novo suco" << endl;
    cout << "5- Alterar o preço de um sanduíche" << endl;
    cout << "6- Alterar o preço de um suco" << endl;
    cout << "7- Excluir um sanduíche" << endl;
    cout << "8- Excluir um suco" << endl;
    cout << "9- Sair" << endl;

    cin >> op;
    cin.get();
    switch(op){
      case 1:
        listarSand();
        break;
      case 2:
        listarSucos();
        break;
      case 3:
        cout << "Nome do sanduíche: ";
        getline(cin,nome);
        if (sands.find(nome) != sands.end())
          cout << "Sanduíche já cadastrado!" << endl;
        else {
          cout << "Preço do sanduíche: ";
          cin >> preco;
          cadastrarSand(nome, preco);
        }
        break;
      case 4:
        cout << "Nome do suco: ";
        getline(cin,nome);
        if (sucos.find(nome) != sucos.end())
          cout << "Suco já cadastrado!" << endl;
        else {
          cout << "Preço do suco: ";
          cin >> preco;
          cadastrarSuco(nome, preco);
        }
        break;
      case 5:
        listarSand();
        cout << "Qual sanduíche você quer alterar o preço: ";
        getline(cin,nome);
        if (sands.find(nome) != sands.end()){
          cout << "Novo preço: ";
          cin >> preco;
          cadastrarSand(nome, preco);
        } else {
          cout << "Sanduíche não encontrado!" << endl;
        }
        break;
      case 6:
        listarSucos();
        cout << "Qual suco você quer alterar o preço: ";
        getline(cin,nome);
        if (sucos.find(nome) != sucos.end()){
          cout << "Novo preço: ";
          cin >> preco;
          cadastrarSuco(nome, preco);
        } else {
          cout << "Suco não encontrado!" << endl;
        } 
        break;
      case 7:
        listarSand();
        cout << "Digite o nome do sanduíche pra ser excluído: ";
        getline(cin,nome);
        excluirSand(nome);
        break;
      case 8:
        listarSucos();
        cout << "Digite o nome do suco pra ser excluído: ";
        getline(cin,nome);
        excluirSuco(nome);
        break;
      case 9:
        salvarSands();
        salvarSucos();
        aux = 1;
        break;
      default:
        cout << "Comando invalido!";
    }
    cin.get();
    
  } while (aux == 0);
}