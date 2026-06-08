#include <stdio.h>
#include <stdlib.h>
#include "mdc.h"

int main(){
    int m, n;

    printf("1- valor: ");
    scanf("%d",&m);

    printf("\n2- valor: ");
    scanf("%d",&n);

    printf("MDC entre %d e %d: %d\n", m, n, mdc(m,n));

    return 0;
}
