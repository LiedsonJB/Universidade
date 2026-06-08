#include <stdio.h>
#include "escrever.h"

/*void escrever(int v[], int TAM){

    TAM--;

    if(TAM == 0)
        printf("%d elemento: %d\n", TAM + 1, v[TAM]);
    else{
        printf("%d elemento: %d\n", TAM + 1, v[TAM]);
        escrever(v, TAM);
    }

}*/

void escrever(int v[], int TAM, int i){

    if(i < TAM){
        printf("%d elemento: %d\n",i+1, v[i]);
        escrever(v, TAM, i+1);
    }

}
