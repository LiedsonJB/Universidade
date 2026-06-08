#include <stdio.h>
#include <stdlib.h>
#include "somatorio.h"

int main(){
    int n;

    printf("Num: ");
    scanf("%d",&n);

    printf("Resultado: %ld", somatorio(n));

    return 0;
}
