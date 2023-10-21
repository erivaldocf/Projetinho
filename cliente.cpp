#include <iostream>
#include <map>
#include "gerais.hpp"
using namespace std;


void escolherSand(string nome){ // Função que escolhe o sanduiche e adiciona ao carrinho.

  if (carrinho.find(nome) != carrinho.end()){
    carrinho[nome].quant++;
  }
  carrinho[nome].preco = sands[nome];
}

void escolherSuco(string nome){ // Função que escolhe o suco e adiciona ao carrinho.
  if (carrinho.find(nome) != carrinho.end()){
    carrinho[nome].quant++;
  }
  carrinho[nome].preco = sucos[nome];
}
void excluirLanche(string nome){ // Função que exclui um lanche do carrinho.
  
  if (carrinho[nome].quant == 1){
    carrinho.erase(nome);
  } else {
    carrinho[nome].quant = carrinho[nome].quant - 1;
  }
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
    preco += it->second.preco * it->second.quant;
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