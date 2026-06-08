#include <stdio.h>
#include <stdlib.h>

void inverso(int v[], int n){

    printf("\nOrdem inversa\n----------\n");
    for(int i=n-1;i>=0;i--){
        printf("%d\n", v[i]);
    }
}
void ler(int v[], int n){

    for(int i=0;i<n;i++){
        printf("%d valor: ", i+1);
        scanf("%d",&v[i]);
    }

}

int main(){
    int *v, n;

    printf("Num Elementos: ");
    scanf("%d",&n);
    
    v=(int *) calloc(n,sizeof(int));
    
    ler(v,n);
    
    inverso(v,n);
    
    return 0;
}