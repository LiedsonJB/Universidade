#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct{

    int Naluno;
    char *codD;

}inscricao;

inscricao * lerInscricoes(int n){
    inscricao *INSCR;
    char s[MAX];

    INSCR = (inscricao *) malloc(n*sizeof(inscricao));

    for(int i=0; i<n; i++){

        printf("Num: ");
        scanf("%d", &INSCR[i].Naluno);

        fflush(stdin);

        printf("cod: ");
        fgets(s, MAX, stdin);

        INSCR[i].codD = (char *) malloc(strlen(s)*sizeof(char)+1);
        strcpy(INSCR[i].codD, s);

    }
    return INSCR;
}

void main(){
    int n, i;
    inscricao *INS;

    printf("NUM Aluno: ");
    scanf("%d", &n);

    INS = lerInscricoes(n);


    for(i=0;i<n;i++)
        printf("\n\n NUM: %d \n\n\n COD: %s", INS[i].Naluno, INS[i].codD);


}
