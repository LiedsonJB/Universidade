#include <stdio.h>

int arck(int m , int n){
    if(m == 0)
        return n+1;
    else if(n == 0)
        return arck(m-1, 1);
    else if(n > 0 && m > 0)
        return arck(m-1, arck(m, n-1));
}

void main(){

    int m, n;

    printf("1 Num: ");
    scanf("%d",&m);

    printf("\n2 Num: ");
    scanf("%d",&n);


    printf("\nResult: %d", arck(m, n));
}
