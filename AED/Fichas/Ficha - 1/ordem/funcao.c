#include "ordem.h"

void ordem(int n){

    if(n >= 0){
        printf("%d\n", n);
        ordem(n - 1);
    }

}
