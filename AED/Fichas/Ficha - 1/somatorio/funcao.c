#include "somatorio.h"

long int somatorio(int n){

    if(n == 1)
        return 1;
    else
        return n + somatorio(n - 1);

}
