
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "fila.h"

// Exibindo os IDs da fila
void exibirFila(Fila *fila) {
    NoFila *atual = fila->inicio;

    if (filaVazia(fila)) {
        printf("\nFila vazia!\n");
        return;
    }

    printf("\nIDs na fila: ");

    while (atual != NULL) {
        printf("%d ", atual->id);
        atual = atual->proximo;
    }

    printf("\n");
}

int main() {
    NoArvore *raiz = NULL;

    Fila fila;
    inicializarFila(&fila);

    int opcao;
    int id;

    do {
        printf("\n===== SISTEMA DE BIBLIOTECA =====\n");
        printf("1 - Cadastrar livro na BST\n");
        printf("2 - Buscar livro por ID\n");
        printf("3 - Remover livro da BST\n");
        printf("4 - Listar livros em ordem\n");
        printf("5 - Inserir ID na fila\n");
        printf("6 - Remover ID da fila\n");
        printf("7 - Exibir fila\n");
        printf("0 - Encerrar\n");
        printf("Escolha: ");

        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            Livro novo;

            printf("\nID do livro: ");
            scanf("%d", &novo.id);
            getchar();

            printf("Titulo: ");
            fgets(novo.titulo, sizeof(novo.titulo), stdin);
            novo.titulo[strcspn(novo.titulo, "\n")] = '\0';

            printf("Autor: ");
            fgets(novo.autor, sizeof(novo.autor), stdin);
            novo.autor[strcspn(novo.autor, "\n")] = '\0';

            printf("Ano: ");
            scanf("%d", &novo.ano);
            getchar();

            if (novo.id <= 0 || novo.ano < 1 || novo.ano > 2026) {
                printf("\nID ou ano invalido!\n");
            }
            else if (buscarBST(raiz, novo.id) != NULL) {
                printf("\nJa existe um livro com esse ID!\n");
            }
            else if (inserirBST(&raiz, novo) == 1) {
                printf("\nLivro cadastrado com sucesso!\n");
            }
            else {
                printf("\nErro ao cadastrar livro!\n");
            }
        }

        else if (opcao == 2) {
            printf("\nDigite o ID do livro: ");
            scanf("%d", &id);

            NoArvore *resultado = buscarBST(raiz, id);

            if (resultado != NULL) {
                printf("\nLivro encontrado!");
                printf("\nTitulo: %s", resultado->livro.titulo);
                printf("\nAutor: %s", resultado->livro.autor);
                printf("\nAno: %d\n", resultado->livro.ano);
            }
            else {
                printf("\nLivro nao encontrado!\n");
            }
        }

        else if (opcao == 3) {
            printf("\nDigite o ID que deseja remover: ");
            scanf("%d", &id);

            if (removerBST(&raiz, id)) {
                printf("\nLivro removido com sucesso!\n");
            }
            else {
                printf("\nLivro nao encontrado!\n");
            }
        }

        else if (opcao == 4) {
            if (raiz == NULL) {
                printf("\nNenhum livro cadastrado!\n");
            }
            else {
                printf("\nLivros em ordem crescente de ID:\n");
                listarEmOrdem(raiz);
            }
        }

        else if (opcao == 5) {
            printf("\nDigite o ID para inserir na fila: ");
            scanf("%d", &id);

            if (id > 0) {
                enfileirar(&fila, id);
                printf("\nID inserido na fila!\n");
            }
            else {
                printf("\nO ID deve ser positivo!\n");
            }
        }

        else if (opcao == 6) {
            if (filaVazia(&fila)) {
                printf("\nFila vazia! Nao ha ID para remover.\n");
            }
            else {
                id = desenfileirar(&fila);
                printf("\nID removido da fila: %d\n", id);
            }
        }

        else if (opcao == 7) {
            exibirFila(&fila);
        }

        else if (opcao != 0) {
            printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    liberarBST(&raiz);
    liberarFila(&fila);

    printf("\nPrograma encerrado!\n");

    return 0;
}
