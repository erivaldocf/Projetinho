#ifndef GERAIS_HPP
#define GERAIS_HPP

#include <iostream>
#include <map>

typedef struct {
    float preco;
    int quant = 1;
} pedidos;

extern std::map <std::string, float> sands; // map que vai guardar o nome e o preço do sanduiche
extern std::map <std::string, float> sucos; // map que vai guardar o nome e o preço do suco
extern std::map <std::string, pedidos> carrinho; // map que vai guardar o nome e o preço dos lanches no carrinho

void listarSand();
void listarSucos();
void salvarSands();
void salvarSucos();
void lerSands();
void lerSucos();

#endif