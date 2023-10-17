#include <iostream>
#include "funcs.hpp"

using namespace std;

int main() {

  lerSands();
  lerSucos();

  int op;
  cout << "Qual menu você deseja entrar: " << endl;
  cout << "1- Menu do cliente" << endl;
  cout << "2- Menu do gerente" << endl;
  cin >> op;

  if (op == 1)
    menuCliente();
  else if (op == 2)
    menuGerente();
  
}