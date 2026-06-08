#include <stdio.h>

int TH(int n){
    if(n < 1)
        return -1;
    else if(n == 1)
        return 1;
    else if(n > 1)
        return TH(n-1)*2 + 1;
}

void main(){

    int n;

    printf("Num: ");
    scanf("%d",&n);

    printf("\nResult TH: %d\n", TH(n));
}
