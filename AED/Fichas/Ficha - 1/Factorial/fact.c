#include "fact.h"

long int fact_r(int n){

    if(n == 1 || n == 0)
        return 1;
    else
        return n * fact_r(n - 1);
}
