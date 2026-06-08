#include "funcao.h"

int main(){
    int op, controlo;
    link head;
    char aux[50], *txt;
    controlo = 0;
    while(1){

        do{


            printf("\tBem Vindo\n\n");
            op = Menu();

            if(op < 1 || op > 6)
                printf("\nPor favor introduza um correspondente as opcoes dadas\n");

        }while(op < 1 || op > 6);

        switch(op){
            case 1:
                if(controlo == 0)
                    printf("\nDesculpa mas nao tens nenhuma informacao\n");
                else
                    mostrar(head);
            break;

            case 2:
                criar(&head);
                printf("Lista criada");
                controlo++;
            break;

            case 3:
                op = submenu();

                printf("Qual nome desejas adicionar: ");
                fflush(stdin);
                fgets(aux, 50, stdin);
                txt = (char *) malloc(strlen(aux)*sizeof(char)+1);
                strcpy(txt, aux);

                if(op == 1)
                    head = insertBegin(head, txt);
                else
                    head = insertEnd(head, txt);
            break;

            case 4:
                printf("Qual nome desejas remover: ");
                fflush(stdin);
                fgets(aux, 50, stdin);
                txt = (char *) malloc(strlen(aux)*sizeof(char)+1);
                strcpy(txt, aux);
                head = Remover(head, txt);
                controlo--;
            break;

            case 5:
                printf("Obrigado volte sempre!!!!\n\n");
                return 0;
            break;
        }
    }
        return 0;
    }
