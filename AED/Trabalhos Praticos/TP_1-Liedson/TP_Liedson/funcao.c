#include "funcao.h"

int * aloca(int n){

    int *dados;

    dados = (int *) malloc(n * sizeof(int));

    return dados;
}

void ler_seq(int *dados, int n){

    for(int i=0; i < n; i++){
        printf("%d valor: ", i+1);
        scanf("%d", &dados[i]);
    }

}

int remover_zeros(int *dados, int n){
    int cont = 0;

    for(int i=0; i < n; i++){
        if(dados[i] != 0){
            dados[cont] = dados[i];
            cont++;
        }
    }

    return cont;
}

void libertar(int *dados){
    free(dados);
}
