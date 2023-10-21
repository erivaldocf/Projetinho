# Projeto LP1

Francisco é o dono de uma lanchonete e deseja criar um sistema de pedidos de
lanches automático. A lanchonete vende sanduíches e sucos.

## 🚀 Funcionamento e Funcionalidades

  O programa inicialmente faz chamada de duas funções que ler os sanduíches e sucos cadastrados previamente em arquivo.txt
  
 O programa tem dois menus, um para o cliente e outro do gerente.
 
 No menu do cliente tem as seguintes funcionalidades:
1. Listar todos os sanduíches cadastrados (Opção que vai listar todos os sanduíches cadastrados no sands.txt previamente)
2. Listar todos os sucos cadastrados (Opção que vai listar todos os sucos cadastrados no arquivo sucos.txt previamente)
3. Escolher o lanche (Vai te dar 3 opções de lanche: apenas um sanduíche, apenas um suco, ou sanduíche + suco, após escolher qualquer uma das opções ele vai listar os sanduíches e sucos cadastrados)
4. Calcular o valor do lanche (Opção que vai somar o preço todos os lanches no carrinho)
5. Ver elementos do carrinho (Opção que vai apenas mostrar todos os lanches do carrinho)
6. Excluir um item do carrinho (Opção que você pode digitar o nome de qualquer item do carrinho pra ser excluido)

Já o menu do gerente, além de possui uma senha para poder acessar, ela possui os seguintes funcionalidades.

1. Listar todos os sanduíches cadastrados (Opção que vai listar todos os sanduíches cadastrados no sands.txt previamente)
2. Listar todos os sucos cadastrados (Opção que vai listar todos os sucos cadastrados no arquivo sucos.txt previamente)
3. Adicionar um novo sanduíche (Opção que você pode adicionar um novo sanduíche passando seu nome e seu preço)
4. Adicionar um novo suco (Opção que você pode adicionar um novo suco passando seu nome e seu preço)
5. Alterar o preço de um sanduíche (Opção que vai alterar o preço de um sanduíche. Obs: a função que altera o preço do sanduíche é a mesma que cadastra, a diferença é que a função que altera o preço faz uma checagem para ver se o sanduíche já está cadastrado para poder alterar seu preço)
6. Alterar o preço de um suco (Opção que vai alterar o preço de um suco. Obs: a função que altera o preço do suco é a mesma que cadastra, a diferença é que a função que altera o preço faz uma checagem para ver se o suco já está cadastrado para poder alterar seu preço)
7. Excluir um sanduíche (Opção para excluir um sanduíche)
8. Excluir um suco (Opção para excluir um suco)

Obs: Após entrar no menu do gerente, qualquer alteração que você fazer vai ser salva no final nos arquivos.txt se você encerrar o programa corretamente. Se você finalizar o programa manualmente as alterações não serão salvas.
