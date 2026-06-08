#include "funcao.h"

int main(){
    int n, *v;

    do{

        printf("Numero inteiro positivo: ");
        scanf("%d", &n);

        if(n < 0){
            printf("\nPor favor respeita a condicao desejada!!!!\n");
            system("pause");
            system("cls");
        }

    }while(n < 0);

    v = aloca(n);
    ler_seq(v, n);
    system("cls");
    printf("\nTrabalhando dados!!!!\nPor favor aguarda\n");
    sleep(1);
    system("cls");

    printf("Novo tamanho: %d\n", remover_zeros(v, n));

    libertar(v);
    printf("\nMemoria libertada!!!!\n");

   return 0;
}
