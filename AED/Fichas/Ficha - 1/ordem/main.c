#include <stdio.h>
#include <stdlib.h>
#include "ordem.h"

int main(){
    int n;

    printf("Seu numero: ");
    scanf("%d", &n);

    system("cls");
    printf("Processando...");
    sleep(2);
    system("cls");

    printf("Decomposicao de %d ate 0:\n ", n);
    ordem(n);

    return 0;
}
