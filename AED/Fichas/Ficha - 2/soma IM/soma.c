#include "soma.h"
#include <stdio.h>

void ler(img *x, img *y){

    printf("P.real: ");
    scanf("%d", &x->real);

    printf("P.Img: ");
    scanf("%d", &x->real);

}
img soma(img x, img y){

    img resultado;

    resultado.real = x.real + y.real;

    resultado.im = x.im + y.im;

    return resultado;

}
