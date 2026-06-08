#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>

float **alocar(int n, int m){
    float **v;
    int i;

    v = (float **) malloc(n*sizeof(float *));

    if(v == NULL){
        printf("Erro 3.6: nao foi possivel alocar espaco\n-----------------------------------\n");
        exit(-1);
    }

    for(i = 0;i < n; i++){
        v[i] = (float *) malloc(m*sizeof(float));

        if(v[i] == NULL){
            for(int j = i; j >= 0; j--){
                free (v[j]);
                printf("\Erro 3.6.1: Nao foi possivel alocar todo espaco\n---------------------------------------------\n");
            }
            exit(1);
        }
    }

    return v;
}

void ler(float **v, int a, int s){

    for(int i = 0; i < a; i++){
        printf("%d Atleta\n----------------------------------------\n", i+1);

        for(int j = 0; j < s; j++){
            printf("%d sessao: ", j+1);
            scanf("%f", &v[i][j]);
            printf("\n---------------------------------------------\n");
        }
    }

}

void escrever(float **v, int a, int s){
    printf("\nEstes sao os dados introduzidos\n");

    for(int i = 0; i < a; i++){
        printf("%d Atleta\n----------------------------------------\n", i+1);

        for(int j = 0; j < s; j++){
            printf("%d sessao: %.2f\n", j+1, v[i][j]);
            printf("\n--------------------------------------\n");
        }
    }
}

void mediaC(float **v, int a, int s){
    float media = 0, soma = 0;

    printf("\nEstas sao as medias de cada atleta\n");

    for(int i = 0; i < s; i++){
        for(int j = 0; j < a; j++){
            soma += v[j][i];
        }
        media = soma / a;
        printf("\nMedia da %d sessao: %.2f\n", i+1, media);
    }
}

void miniLinas(float **v, int a, int s){
    float mini = v[0][0];

    printf("\nMenor tempo de cada sesssao");

    for(int i = 0; i < a; i++){
        printf("Tempo do %d atleta\n--------------------------------------\n", i+1);
        for(int j = 0; j < s; j++){
            if(mini > v[i][j])
                mini = v[i][j];
        }
        printf("\nSeu menor tempo: %.2f\n", mini);
        printf("\n--------------------------------------\n");
    }
}

void libertar(float **v, int a, int s){

    for(int i = 0; i < s; i++){

            free(v[i]);
        }
        free(v);


}
