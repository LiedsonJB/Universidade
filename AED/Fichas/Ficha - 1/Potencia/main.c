#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;

    printf("Programa que calcula potencias de base 2\n------------------------\n");
    printf("Seu expoente: ");
    scanf("%d",&n);

    system("cls");
    printf("Processando...");
    sleep(2);
    system("cls");

    printf("Resultado: %d", potencia(n));

    return 0;
}
