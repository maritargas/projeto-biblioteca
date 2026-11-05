#ifndef LISTA_H
#define LISTA_H

#include "livro.h"

typedef struct No {
    Livro livro;
    struct No *proximo;
} No;

void inserirFim(No **inicio, Livro livro);
void listarLivros(No *inicio);
No *buscarLivro(No *inicio, int id);
void removerLivro(No **inicio, int id);
void liberarLista(No **inicio);

#endif
