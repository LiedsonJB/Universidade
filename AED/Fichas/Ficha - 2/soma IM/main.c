#include <stdio.h>
#include <stdlib.h>
#include "soma.h"

int main(){

    img x, y, r;

    ler(&x, &y);

    r = soma(x, y);

    printf("Resultado:  %d%c%d", r.real, r.im<0?'+':NULL, r.im);

    return 0;
}
