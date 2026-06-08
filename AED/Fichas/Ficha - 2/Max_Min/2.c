#include <stdio.h>

void mm(int v[], int * max, int * min, int t){

    *max=v[0];
    *min=v[0];

    for(int i=1;i<t;i++){
        if(*max < v[i])
            *max = v[i];
        else
            *min = v[i];    
    
    }

}

int main(){
    int *v, x, max, min;

    printf("Quantos elementos: ");
    scanf("%d",&x);
    
    v = (int*) malloc(sizeof(int)*x);
    
    for(int i=0;i<x;i++){
        printf("%d Elemento: ",i+1);
        scanf("%d", &v[i]);
    }
    
    mm(v, &max, &min, x);
    
    printf("\n%d max, %d min", max, min);
    
    return 0;
}