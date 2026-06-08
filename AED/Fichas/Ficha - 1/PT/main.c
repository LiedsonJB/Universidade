#include <stdio.h>
#include <stdlib.h>
#include "pt.h"

int main(){
    int b,  E;

    printf("Base: ");
    scanf("%d", &b);

    printf("\nExpoente: ");
    scanf("%d",&E);

    printf("\nResultado: %.2f\n", potencia(b,E));

    return 0;
}
