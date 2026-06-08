#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fact.h"

int main(){

    int n;

    do{

        printf("Num Positivo: ");
        scanf("%d",&n);

        system("cls");
        printf("Analisando o numero.....\nPor favor aguarde");
        sleep(2);
        system("cls");

        if(n < 0){
            printf("Erro: Numero nao positivo!!!");
            system("cls");
        }else
            printf("\nO numero foi aceito\nClica em uma tecla para continuar.....\n");

    }while(n < 0);

    system("pause");
    system("cls");

    printf("\nResultado %d! = %d", n, fact_r(n));

    return 0;
}
