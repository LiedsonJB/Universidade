#include "mdc.h"

int mdc(int m, int n){

    if(n == 0)
        return m;
    else if(n > 0)
        return mdc(n, m % n);

}
