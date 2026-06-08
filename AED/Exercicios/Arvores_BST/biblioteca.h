#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int Valor;
    struct node *dir;
    struct node *esq;
} *PLista;
typedef PLista Lista;

Lista inserir(Lista raiz, int item);
int procura(Lista raiz, int item);
void ImprimirEmOrdem(Lista Raiz);
void preOrdem(Lista raiz);
void ImprimirEmPosOrdem(Lista raiz);
int menu();
int menorElemento(Lista raiz);
int maiorElemento(Lista raiz);

#endif // BIBLIOTECA_H_INCLUDED
