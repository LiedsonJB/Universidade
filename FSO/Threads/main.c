#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *show(void *sms){
    char *s = (char *) sms;
    printf("%s\n", s);
}

int main(){

    pthread_t threads1;
    pthread_t threads2;

    if(pthread_create(&threads1 , NULL, show, (void *)"Hello") != 0){
        perror("Nao foi possivel criar a tarefa");
        exit(EXIT_FAILURE);
    }

    if(pthread_create(&threads2 , NULL, show, (void *)"Word") != 0){
        perror("Nao foi possivel criar a tarefa");
        exit(EXIT_FAILURE);
    }

    if(pthread_join(threads1, NULL) == 0){
        printf("threads1 terminado");
    }else
        perror("Erro");

    if(pthread_join(threads2, NULL) == 0){
        printf("threads1 terminado");
    }else
        perror("Erro");

    return 0;
}