#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

//Inserindo livro na arvore
int inserirBST(NoArvore **raiz, Livro livro) {
    NoArvore *novo;
    NoArvore *atual;
    NoArvore *anterior = NULL;

    novo = malloc(sizeof(NoArvore));

    if (novo == NULL) {
        return 0;
    }

    novo->livro = livro;
    novo->esquerda = NULL;
    novo->direita = NULL;

    if (*raiz == NULL) {
        *raiz = novo;
        return 1;
    }

    atual = *raiz;

    while (atual != NULL) {
        anterior = atual;

        if (livro.id < atual->livro.id) {
            atual = atual->esquerda;
        }
        else if (livro.id > atual->livro.id) {
            atual = atual->direita;
        }
        else {
            free(novo);
            return 0;
        }
    }

    if (livro.id < anterior->livro.id) {
        anterior->esquerda = novo;
    }
    else {
        anterior->direita = novo;
    }

    return 1;
}

//Buscando livro pelo ID
//Retorna um ponteiro para o no da arvore
NoArvore *buscarBST(NoArvore *raiz, int id) {
    NoArvore *atual = raiz;

    while (atual != NULL) {

        if (id == atual->livro.id) {
            return atual;
        }

        if (id < atual->livro.id) {
            atual = atual->esquerda;
        }
        else {
            atual = atual->direita;
        }
    }

    return NULL;
}

//Removendo livro da arvore
int removerBST(NoArvore **raiz, int id) {
    NoArvore *atual;
    NoArvore *sucessor;

    if (*raiz == NULL) {
        return 0;
    }

    atual = *raiz;

    //Procurando o livro
    if (id < atual->livro.id) {
        return removerBST(&atual->esquerda, id);
    }
    else if (id > atual->livro.id) {
        return removerBST(&atual->direita, id);
    }

    //Caso 1: no sem filhos ou apenas com filho direito
    if (atual->esquerda == NULL) {
        *raiz = atual->direita;
        free(atual);
        return 1;
    }

    //Caso 2: no com apenas filho esquerdo
    if (atual->direita == NULL) {
        *raiz = atual->esquerda;
        free(atual);
        return 1;
    }

    //Caso 3: no com dois filhos
    sucessor = menorNo(atual->direita);

    atual->livro = sucessor->livro;

    return removerBST(&atual->direita, sucessor->livro.id);
}
//Encontrando o livro com menor ID
NoArvore *menorNo(NoArvore *raiz) {
    NoArvore *atual = raiz;

    if (atual == NULL) {
        return NULL;
    }

    while (atual->esquerda != NULL) {
        atual = atual->esquerda;
    }

    return atual;
}

//Encontrando o livro com maior ID
NoArvore *maiorNo(NoArvore *raiz) {
    NoArvore *atual = raiz;

    if (atual == NULL) {
        return NULL;
    }

    while (atual->direita != NULL) {
        atual = atual->direita;
    }

    return atual;
}
//Livros em ordem crescente de ID
void listarEmOrdem(NoArvore *raiz) {

    if (raiz != NULL) {

        listarEmOrdem(raiz->esquerda);

        printf("\nID: %d", raiz->livro.id);
        printf("\nTitulo: %s", raiz->livro.titulo);
        printf("\nAutor: %s", raiz->livro.autor);
        printf("\nAno: %d\n", raiz->livro.ano);

        listarEmOrdem(raiz->direita);
    }
}
//Para liberar a memoria
void liberarBST(NoArvore **raiz) {

    if (*raiz != NULL) {

        liberarBST(&(*raiz)->esquerda);

        liberarBST(&(*raiz)->direita);

        free(*raiz);

        *raiz = NULL;
    }
}
