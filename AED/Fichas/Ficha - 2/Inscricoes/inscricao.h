#ifndef INSCRICAO_H_INCLUDED
#define INSCRICAO_H_INCLUDED

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 11

typedef struct {

    int nAluno;
    char * cod;

}inscrever;

inscrever * lerInscricoes(int n);
void escrever(inscrever *v, int n);
void libertar(inscrever *v);

#endif // INSCRICAO_H_INCLUDED
