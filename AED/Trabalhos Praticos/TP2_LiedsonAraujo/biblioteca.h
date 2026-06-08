#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {

    char gelado[20];
    unsigned int quant;
    struct node* next;

};

typedef struct node Plista;
typedef Plista *lista;

lista insere_gelado(lista head, char *gelad, unsigned int quantidade);
void lista_sabores_em_falta(lista head, int limite);
void imprimir(lista head);

#endif // BIBLIOTECA_H_INCLUDED
