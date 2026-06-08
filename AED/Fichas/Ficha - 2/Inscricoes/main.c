#include <stdio.h>
#include <stdlib.h>
#include "inscricao.h"

int main(){
    int n;
    inscrever *insc;

    printf("Numero de Inscritos: ");
    scanf("%d", &n);

    insc = lerInscricoes(n);

    escrever(insc, n);
    libertar(insc);

    return 0;
}
