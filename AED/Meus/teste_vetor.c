#include <stdio.h>

void escrever(int v[], int TAM){

    TAM--;

    if(TAM == 0)
        printf("%d elemento: %d\n", TAM + 1, v[TAM]);
    else{
        printf("%d elemento: %d\n", TAM + 1, v[TAM]);
        escrever(v, TAM);
    }

}
void ler(int v[], int t){

    printf("Introduza seus %d numeros\n", t);

    for(int i = 0; i < t; i++){

        printf("%d Numero: ", i+1);

        scanf("%d", &v[i]);

    }
}
int main(){

    int v[100], n;

    printf("Seu tamanho: ");
    scanf("%d", &n);

    ler(v, n);
    printf("\n");
    escrever(v, n);

    return 0;

}
