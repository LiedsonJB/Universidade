#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float potencia(int x, int n){

    if(n == 0)
        return 1;
    else if(n > 0)
        return potencia(x, n-1)*x;
    else if(n < 0)
        return potencia(x, n+1)/x;

}

void main(){

    int n, x;

    printf("Base: ");
    scanf("%d",&x);

    printf("Exp: ");
    scanf("%d",&n);

    printf("\nResult: %.2f", potencia(x,n));
}
