#include "inverso.h"
#include <stdio.h>

void inverso(int n, int dig, int in){

    if(n > 0){

        dig = n % 10;
        in =in * 10 + dig;
        n/=10;
        inverso(n, dig, in);
    }else
        printf("O inverso do numero: %d", in);
}
