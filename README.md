# projeto-biblioteca

Sistema de gerenciamento de biblioteca em C para a disciplina de Estrutura de Dados.



\# Objetivo



Desenvolver um sistema de gerenciamento de livros utilizando uma Árvore Binária de Busca (BST) e uma estrutura de dados linear do tipo Fila.



\## Funcionalidades



\### Árvore Binária de Busca (BST)

\- Cadastrar livros com ID, título, autor e ano.

\- Buscar livros pelo ID.

\- Remover livros cadastrados.

\- Listar livros em ordem crescente de ID.

\- Impedir o cadastro de IDs repetidos.



\### Fila

\- Inserir IDs na fila.

\- Remover IDs seguindo a ordem FIFO (primeiro a entrar, primeiro a sair).

\- Exibir os IDs armazenados.

\- Permitir IDs repetidos.

\- Informar quando a fila estiver vazia.



\## Organização dos arquivos



\- `include/`: arquivos de cabeçalho (.h).

\- `src/`: arquivos de implementação (.c), incluindo o programa principal.

\- `tests/`: diretório destinado aos testes do projeto.



\## Como compilar



Com o compilador GCC instalado, execute na pasta principal do projeto:



```bash

gcc -Iinclude src/main.c src/bst.c src/fila.c -o biblioteca.exe

```



\## Como executar



No terminal, execute:



```bash

./biblioteca.exe

```



\## Estruturas de dados



A BST organiza os livros de acordo com seus IDs, permitindo operações de inserção, busca, remoção e listagem em ordem.



A fila armazena IDs de forma independente da árvore, seguindo a política FIFO.



\## Testes



Foram realizados testes de cadastro, busca, remoção de livros, listagem em ordem, inserção e remoção de IDs na fila, incluindo fila vazia e IDs repetidos.



\## Ferramentas utilizadas



\- Linguagem C.

\- Compilador GCC.

\- Git e GitHub para versionamento.

\- Code::Blocks para edição e desenvolvimento.



