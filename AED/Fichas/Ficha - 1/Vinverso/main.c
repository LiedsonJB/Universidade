#include <stdio.h>
#include <stdlib.h>
#include "escrever.h"
#include "ler.h"

int main(){
    int n, v[10];

    do{
        printf("Tens quantos elementos(ate 0 < n < 10): ");
        scanf("%d", &n);

        if(n < 10 && n > 0){

            printf("ERRO.....\nRespeita as condicoes\n");

            system("cls");
        }

    }while(n >= 10 && n <= 0);

        lerVetor(v, n, 0);
        escrever(v, n, 0);

    return 0;
}
