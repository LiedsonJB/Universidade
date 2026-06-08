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
void escreveVector(int v[ ], int tamanho){

    int i;

    for(i = 0; i < tamanho; i++){

        printf("%d ", v[i]);

    }
}

void main(){

    int v[NUMELEMS];

    leVector(v, NUMELEMS);
    escreveVector(v, NUMELEMS);
}
