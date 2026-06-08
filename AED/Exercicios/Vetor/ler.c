#include "vetor_10.h"
#include <stdio.h>

void ler(int v[], int t){

    printf("Introduza seus %d numeros\n", t);

    for(int i = 0; i < t; i++){

        printf("%d Numero: ", i+1);

        scanf("%d", &v[i]);

    }
}
