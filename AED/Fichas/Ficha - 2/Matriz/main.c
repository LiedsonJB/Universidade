#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(){
    int a, s;
    float ** v;

    printf("Num alt: ");
    scanf("%d", &a);

    printf("Num suss: ");
    scanf("%d", &s);

    v = alocar(a, s);

    system("cls");
    printf("Ler dados\n\n\n");
    ler(v, a, s);

    system("cls");
    printf("Mostrar dados\n\n\n");
    escrever(v, a, s);

    printf("Media coluna\n\n\n");
    mediaC(v, a, s);

    printf("Minimo linha\n\n\n");
    miniLinas(v, a, s);

    system("pause");
    libertar(v, a, s);

    system("cls");
    printf("Memoria libertada\n\n----------------------\n\n\n");

    return 0;
}
