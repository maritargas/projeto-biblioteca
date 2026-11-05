#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void inicializarPilha(Pilha *pilha) {
    pilha->topo = NULL;
    pilha->quantidade = 0;
}

void push(Pilha *pilha, char acao[]) {
    NoPilha *novo = malloc(sizeof(NoPilha));

    if (novo == NULL) {
        printf("Erro ao reservar memoria!\n");
        return;
    }

    strcpy(novo->acao, acao);

    novo->proximo = pilha->topo;
    pilha->topo = novo;

    pilha->quantidade++;
}

void pop(Pilha *pilha) {
    if (pilha->topo == NULL) {
        printf("\nPilha vazia!\n");
        return;
    }

    NoPilha *removido = pilha->topo;

    pilha->topo = removido->proximo;

    free(removido);

    pilha->quantidade--;

    printf("\nUltima acao removida!\n");
}

void peek(Pilha *pilha) {
    if (pilha->topo == NULL) {
        printf("\nPilha vazia!\n");
        return;
    }

    printf("\nUltima acao: %s\n", pilha->topo->acao);
}

void mostrarHistorico(Pilha *pilha) {
    NoPilha *atual = pilha->topo;
    int contador = 0;

    if (atual == NULL) {
        printf("\nHistorico vazio!\n");
        return;
    }

    printf("\n===== ULTIMAS ACOES =====\n");

    while (atual != NULL && contador < 5) {
        printf("%s\n", atual->acao);

        atual = atual->proximo;
        contador++;
    }
}

void liberarPilha(Pilha *pilha) {
    while (pilha->topo != NULL) {
        NoPilha *removido = pilha->topo;
        pilha->topo = removido->proximo;
        free(removido);
    }

    pilha->quantidade = 0;
}