#include <stdio.h>
#include <stdlib.h>
#include "Ackermann.h"

int main(){

    int m, n;

    printf("1 Num: ");
    scanf("%d",&m);

    printf("\n2 Num: ");
    scanf("%d",&n);

    printf("\nResult: %d\n", Ackermann(m, n));

    return 0;
}
