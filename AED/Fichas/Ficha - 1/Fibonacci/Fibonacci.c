#include <stdio.h>

int F(int n){
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else if(n > 1)
        return F(n - 1) + F(n - 2);
}

void main(){

    int n;

    printf("Num: ");
    scanf("%d",&n);

    printf("Result Fibonacci: %d", F(n));
}
