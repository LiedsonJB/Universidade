#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int real;
    int im;
}img;

int main(){
    img r;
    char op[5];

    do{
        printf("Parte real: ");
        scanf("%d",&r.real);

        printf("\nParte imaginaria: ");
        scanf("%d",&r.im);

        if(r.real == 0)
            printf("\nResultado: %di", r.im);
        else if(r.im == 0)
            printf("\nResultado: %di", r.real);
        else
            printf("\nResultado: %d%c%di\n\n", r.real, r.im>0?'+':NULL, r.im);

        system("pause");
        fflush(stdin);

        printf("\nRodar novamente(sim/nao): ");
        scanf("%s",op);

    }while(strcmp(op, "sim") == 0);

    system("cls");

    return 0;
}
