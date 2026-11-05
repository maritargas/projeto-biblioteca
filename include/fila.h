#ifndef FILA_H
#define FILA_H

typedef struct NoFila {
    int id;
    struct NoFila *proximo;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
} Fila;

void inicializarFila(Fila *fila);
int filaVazia(Fila *fila);
void enfileirar(Fila *fila, int id);
int desenfileirar(Fila *fila);
void liberarFila(Fila *fila);

#endif