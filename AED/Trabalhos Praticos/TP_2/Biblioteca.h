#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

struct node{

    char *Nome;
    unsigned int quantidade;
    struct node *next;

};
typedef struct node Plista;
typedef Plista *Lista;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

int menu();
char *ler();
Lista insere_Gelado(Lista head, char *nome, int quant);
int compare(char *Nome1, char *Nome2);
void mostrar(Lista head);
void lista_sabores_em_falta(Lista head, int limite);
int atualizar(Lista head, int quant, char *gelado);
Lista deletar(Lista head, char *name);

#endif // BIBLIOTECA_H_INCLUDED
