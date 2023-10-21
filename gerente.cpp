#include <iostream>
#include <map>
#include "gerais.hpp"
using namespace std;

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