#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int mdc(int m, int n){

    if(n == 0)
        return m;
    else if(n > 0)
        return mdc(n, m%n);
}

void main(){

    int n, x;

    printf("1 num: ");
    scanf("%d",&x);

    printf("2 num: ");
    scanf("%d",&n);

    printf("\nmdc e:: %d", mdc(x,n));
}
