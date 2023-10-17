#ifndef FUNCS_HPP
#define FUNCS_HPP

#include <string>

// Funções gerais
void listarSand();
void listarSucos();
void salvarSands();
void salvarSucos();
void lerSands();
void lerSucos();

// Funções do cliente
float calcularValor(std::string nome);
void escolherSand(std::string nome);
void escolherSuco(std::string nome);
void verCarrinho();
float valorLanche();
void excluirLanche(std::string nome);
void menuCliente();

// Funções do gerente
void cadastrarSand(std::string nome, float preco);
void cadastrarSuco(std::string nome, float preco);
void excluirSand(std::string nome);
void excluirSuco(std::string nome);
void menuGerente();

#endif