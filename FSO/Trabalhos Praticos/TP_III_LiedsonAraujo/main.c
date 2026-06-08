#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

typedef struct Filme{
    char *nome; //nome filme
    int NumBl; //numero de bilhtes disponiveis
    float preco; //preco dos filmes
    
}Filme;

int main() {
    srand(time(NULL));

    Filme movies[3]; //vetor de estrutura para armazenar os filmes 
    int somaBV = 0; //var para somar os bilhetes vendidos 
    char *filme[] = {"One Piece: Strong World", "One Piece Film: Z", "One piece: Red"};//meus filmes

    for(int i=0; i<3; i++){
        movies[i].nome = (char *)malloc(sizeof(char)*strlen(filme[i]));//alocar espaco para os filmes
        strcpy(movies[i].nome, filme[i]);//copiar os filmes
        movies[i].NumBl = rand()%4; //gerar um numero aleatorio de 0 ate 3
        movies[i].preco = 10; //preco de cada filme
    }

    return 0;
}