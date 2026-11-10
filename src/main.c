#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "pilha.h"
#include "bst.h"

int main() {
    No *inicio = NULL;
    NoArvore *raiz = NULL;

    Pilha historico;
    inicializarPilha(&historico);

    int opcao;
    int id;

    do {
        printf("\n===== BIBLIOTECA =====\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Listar livros\n");
        printf("3 - Buscar livro\n");
        printf("4 - Remover livro\n");
        printf("5 - Mostrar historico\n");
        printf("6 - Consultar ultima acao (Peek)\n");
        printf("7 - Remover ultima acao (Pop)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            Livro novo;

            printf("\nID do livro: ");
            scanf("%d", &novo.id);
            getchar();

            printf("Titulo: ");
            fgets(novo.titulo, 100, stdin);
            novo.titulo[strcspn(novo.titulo, "\n")] = '\0';

            printf("Autor: ");
            fgets(novo.autor, 100, stdin);
            novo.autor[strcspn(novo.autor, "\n")] = '\0';

            printf("Ano: ");
            scanf("%d", &novo.ano);
            getchar();

            // Verificando se o ID existe
            if (buscarBST(raiz, novo.id) != NULL) {
                printf("\nJa existe um livro com esse ID!\n");
            }
            else {

                //Inserindo o livro na arvore
                if (inserirBST(&raiz, novo) == 1) {

                    //Inserindo o livro na lista
                    inserirFim(&inicio, novo);

                    push(&historico, "Cadastro de livro");

                    printf("\nLivro cadastrado com sucesso!\n");
                }
                else {
                    printf("\nErro ao cadastrar o livro!\n");
                }
            }
        }
        else if (opcao == 2) {
            listarLivros(inicio);
        }
        else if (opcao == 3) {
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
        else if (opcao == 4) {
            printf("\nDigite o ID do livro que deseja remover: ");
            scanf("%d", &id);

            if (buscarBST(raiz, id) != NULL) {
            removerLivro(&inicio, id);
            removerBST(&raiz, id);

            push(&historico, "Remocao de livro");
        }
            else {
            printf("\nLivro nao encontrado!\n");
            }
        }
        else if (opcao == 5) {
            mostrarHistorico(&historico);
        }
        else if (opcao == 6) {
            peek(&historico);
        }
        else if (opcao == 7) {
            pop(&historico);
        }
        else if (opcao != 0) {
            printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    mostrarHistorico(&historico);
    liberarPilha(&historico);
    liberarLista(&inicio);
    liberarBST(&raiz);

    printf("\nPrograma encerrado!\n");

    return 0;
}
