#ifndef FUNCAO_H_INCLUDED
#define FUNCAO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char *text;
    struct node *next;
} *link;

int Menu();
void criar(link *head);
int vazia(link head);
link NEW(char* text);
link insertEnd(link head, char* text);
link Remover(link head, char* text);
link insertBegin(link head, char* text);
void mostrar(link head);
int submenu();

#endif // FUNCAO_H_INCLUDED
