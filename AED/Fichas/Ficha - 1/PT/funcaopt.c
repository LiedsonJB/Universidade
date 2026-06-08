#include "pt.h"
#include <stdio.h>

float potencia(int x, int n){
    if(n == 0){
        return 1;
    }else if(n > 0){
        return potencia(x, n - 1) * x;
    }else if(n < 0){
        return potencia(x, n + 1) / x;
    }
}
