#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void inicializarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int filaVazia(Fila *fila) {
    return fila->inicio == NULL;
}

void enfileirar(Fila *fila, int id) {
    NoFila *novo = malloc(sizeof(NoFila));

    if (novo == NULL) {
        printf("Erro ao reservar memoria!\n");
        return;
    }

    novo->id = id;
    novo->proximo = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
}

int desenfileirar(Fila *fila) {
    if (filaVazia(fila)) {
        return -1;
    }

    NoFila *removido = fila->inicio;
    int id = removido->id;

    fila->inicio = removido->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(removido);

    return id;
}

void liberarFila(Fila *fila) {
    while (!filaVazia(fila)) {
        desenfileirar(fila);
    }
}