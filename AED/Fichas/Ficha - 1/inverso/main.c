#include <stdio.h>
#include <stdlib.h>
#include "inverso.h"

int main(){
    int n;

    printf("Numero: ");
    scanf("%d", &n);

    inverso(n, 0, 0);

    return 0;
}
