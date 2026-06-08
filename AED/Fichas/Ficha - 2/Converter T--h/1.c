#include <stdio.h>
#include <stdlib.h>

void hm(int *h, int *m, int t){

    *h = t / 60;
    *m = t % 60;

}

int main(){

    int t, h, m;
    
    printf("Tempo: ");
    scanf("%d", &t);
    
    hm(&h,&m, t);
    
    printf("%dH%d", h,m);
    

    return 0;
}