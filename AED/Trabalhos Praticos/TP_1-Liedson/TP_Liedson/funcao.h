#ifndef FUNCAO_H_INCLUDED
#define FUNCAO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int * aloca(int n);
void ler_seq(int *dados, int n);
int remover_zeros(int *dados, int n);
void libertar(int *dados);

#endif // FUNCAO_H_INCLUDED
