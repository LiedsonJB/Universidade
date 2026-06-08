#include "potencia.h"

int potencia(int n){

    if(n == 0)
        return 1;
    else
        return potencia(n - 1) * 2;

}
