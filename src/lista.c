#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inserirFim(No **inicio, Livro livro) {
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao reservar memoria!\n");
        return;
    }

    novo->livro = livro;
    novo->proximo = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        No *atual = *inicio;

        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }

        atual->proximo = novo;
    }
}

void listarLivros(No *inicio) {
    No *atual = inicio;

    if (atual == NULL) {
        printf("\nNenhum livro cadastrado.\n");
        return;
    }

    while (atual != NULL) {
        printf("\nID: %d", atual->livro.id);
        printf("\nTitulo: %s", atual->livro.titulo);
        printf("\nAutor: %s", atual->livro.autor);
        printf("\nAno: %d\n", atual->livro.ano);

        atual = atual->proximo;
    }
}

No *buscarLivro(No *inicio, int id) {
    No *atual = inicio;

    while (atual != NULL) {
        if (atual->livro.id == id) {
            return atual;
        }

        atual = atual->proximo;
    }

    return NULL;
}

void removerLivro(No **inicio, int id) {
    No *atual = *inicio;
    No *anterior = NULL;

    while (atual != NULL && atual->livro.id != id) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("\nLivro nao encontrado!\n");
        return;
    }

    if (anterior == NULL) {
        *inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);

    printf("\nLivro removido com sucesso!\n");
}

void liberarLista(No **inicio) {
    No *atual = *inicio;

    while (atual != NULL) {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    *inicio = NULL;
}
