#include "Ackermann.h"

int Ackermann(int n, int m){

    if(m == 0)
        return n + 1;
    else if(n == 0)
        return Ackermann(m - 1, 1);
    else if(n > 0 && m > 0)
        return Ackermann(m - 1, Ackermann(m, n - 1));
}
