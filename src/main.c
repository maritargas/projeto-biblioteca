#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main() {
    No *inicio = NULL;
    int opcao;
    int id;

    do {
        printf("\n===== BIBLIOTECA =====\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Listar livros\n");
        printf("3 - Buscar livro\n");
        printf("4 - Remover livro\n");
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

            inserirFim(&inicio, novo);

            printf("\nLivro cadastrado!\n");
        }
        else if (opcao == 2) {
            listarLivros(inicio);
        }
        else if (opcao == 3) {
            printf("\nDigite o ID do livro: ");
            scanf("%d", &id);

            No *resultado = buscarLivro(inicio, id);

            if (resultado != NULL) {
                printf("\nLivro encontrado!");
                printf("\nTitulo: %s", resultado->livro.titulo);
                printf("\nAutor: %s", resultado->livro.autor);
                printf("\nAno: %d\n", resultado->livro.ano);
            } else {
                printf("\nLivro nao encontrado!\n");
            }
        }
        else if (opcao == 4) {
            printf("\nDigite o ID do livro que deseja remover: ");
            scanf("%d", &id);

            removerLivro(&inicio, id);
        }
        else if (opcao != 0) {
            printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    liberarLista(&inicio);

    printf("\nPrograma encerrado!\n");

    return 0;
}
