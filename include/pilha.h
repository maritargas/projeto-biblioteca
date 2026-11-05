#ifndef PILHA_H
#define PILHA_H

typedef struct NoPilha {
    char acao[120];
    struct NoPilha *proximo;
} NoPilha;

typedef struct {
    NoPilha *topo;
    int quantidade;
} Pilha;

void inicializarPilha(Pilha *pilha);
void push(Pilha *pilha, char acao[]);
void pop(Pilha *pilha);
void peek(Pilha *pilha);
void mostrarHistorico(Pilha *pilha);
void liberarPilha(Pilha *pilha);

#endif