#include <stdio.h>
#include "vetor_10.h"

int main(){


    int v[100], n;

    printf("Seu tamanho: ");
    scanf("%d", &n);

    ler(v, n);
    printf("\n");
    printf("Este sao os elementos:\n");
    escrever(v, n);

    return 0;

}
