#ifndef BST_H
#define BST_H

#include "livro.h"

typedef struct NoArvore {
    Livro livro;
    struct NoArvore *esquerda;
    struct NoArvore *direita;
} NoArvore;

int inserirBST(NoArvore **raiz, Livro livro);
NoArvore *buscarBST(NoArvore *raiz, int id);
int removerBST(NoArvore **raiz, int id);
void listarEmOrdem(NoArvore *raiz);
NoArvore *menorNo(NoArvore *raiz);
NoArvore *maiorNo(NoArvore *raiz);
void liberarBST(NoArvore **raiz);

#endif
