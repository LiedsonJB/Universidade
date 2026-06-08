#include <stdio.h>
#include "ler.h"

/*void lerVetor(int v[], int TAM){

     TAM--;

    if(TAM == 0){
        printf("%d Elemento: ", TAM + 1);
        scanf("%d", &v[TAM]);
        printf("\n");
    }else{
        printf("%d Elemento: ", TAM + 1);
        scanf("%d", &v[TAM]);
        printf("\n");
        lerVetor(v, TAM);
    }
}*/

void lerVetor(int v[], int TAM, int i){

    if(i < TAM){
        printf("%d Elemento: ", i + 1);
        scanf("%d", &v[i]);
        printf("\n");
        lerVetor(v, TAM, i+1);
    }
}
