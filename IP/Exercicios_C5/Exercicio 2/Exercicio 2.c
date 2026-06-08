#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMELEMS 10

void leVector(int v[],int tamanho){

    int i;

    for(i = 0;i < tamanho; i++){
        printf("%d Valor: ", i+1);
        scanf("%d", &v[i]);
    }
}
int somaVector(int v[ ], int tamanho){

    int i, soma = 0;

    for(i = 0; i < tamanho; i++){

       soma += v[i];

    }
    return soma;
}

void main(){

    int v[NUMELEMS];

    leVector(v, NUMELEMS);
    printf("Soma: %d ", somaVector(v, NUMELEMS));
}
