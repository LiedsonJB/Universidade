#include "inscricao.h"

inscrever * lerInscricoes(int n){
    int i;
    char v[MAX];
    inscrever *str;

   str = (inscrever*) malloc(n*sizeof(inscrever));

    if(str == NULL){
        printf("ERRO 1.1: Nao foi possivel alocar a memoria");
        exit(1);
    }

    for(i = 0; i < n; i++){

        printf("%d Aluno\n------------------------------\n", i+1);
        printf("Seu numero: ");
        scanf("%d", &str[i].nAluno);
        fflush(stdin);
        printf("\nCodigo da disciplina: ");
        fgets(v, MAX, stdin);

        str[i].cod = (char *) malloc(strlen(v)*sizeof(char)+1);
        strcpy(str[i].cod, v);

        printf("\n----------------------------------\n");

    }
    return str;
}

void escrever(inscrever *v, int n){

    for(int i = 0; i < n; i++){

        printf("%d Aluno\n------------------------\n", i+1);
        printf("Seu Numero: %d\nSeu codigo %s\n", v[i].nAluno, v[i].cod);
    }
}

void libertar(inscrever *v){

    free(v);

}
