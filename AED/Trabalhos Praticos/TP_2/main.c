#include "Biblioteca.h"

int main(){
    setlocale(LC_ALL,"PORTUGUESE");
   //   system("Color 1");

    Lista head = NULL;
    int op, quant;
    char *NomeGelado;

    while(1){
        op = menu();

        switch(op){
            case 1:
                printf("Introduzir um dado gelado\n");
                printf("-----------------------------\n\n");

                fflush(stdin);
                NomeGelado = ler();
                do{
                    printf("\n\tA sua quantidade: ");
                    scanf("%d", &quant);

                    printf("\nAnalisando o valor da quantidade por favor aguarda!!!!\n\n");
                    sleep(2);

                    if(quant < 0){
                        printf("Opa a quantidade nao pode ser negativa\n");
                        system("pause");
                        continue;
                    }

                }while(quant < 0);

                printf("Resposta aceita\n");
                system("pause");
                system ("cls");

                head = insere_Gelado(head, NomeGelado, quant);

                printf("Novo gelado introduzido com sucesso\n\n");
                system("pause");
                system ("cls");
            break;

            case 2:
                if(head == NULL){
                    printf("Lista vazia\n\n");
                    system("pause");
                    system("cls");
                    continue;
                }
                printf("Atualizar quantidade de um dado gelado\n");
                printf("---------------------------------------\n\n");

                fflush(stdin);
                NomeGelado = ler();

                do{
                    printf("\n\tA sua quantidade: ");
                    scanf("%d", &quant);

                    printf("\nAnalisando o valor da quantidade por favor aguarda!!!!\n\n");
                    sleep(2);

                    if(quant < 0){
                        printf("Opa a quantidade nao pode ser negativa\n");
                        system("pause");
                        continue;
                    }

                }while(quant < 0);
                printf("Resposta aceita\n");
                system("pause");
                system ("cls");

                op = atualizar(head, quant, NomeGelado);
                if(op == 1)
                    printf("Atualizacao bem sucedida\n");
                else
                    printf("Nao foi possivel atualizar por nao existir na lista\n");

                system("pause");
                system("cls");
            break;

            case 4:
                if(head == NULL){
                    printf("Lista vazia\n\n");
                    system("pause");
                    system("cls");
                    continue;
                }
                printf("Deletar um dado gelado\n");
                printf("--------------------------\n\n");

                fflush(stdin);
                NomeGelado = ler();
                head = deletar(head, NomeGelado);
                system("pause");
                system ("cls");
            break;

            case 5:
               if(head == NULL){
                    printf("Lista vazia\n\n");
                    system("pause");
                    system("cls");
                    continue;
                }
                mostrar(head);
                system("pause");
                system("cls");
            break;

            case 3:
                if(head == NULL){
                    printf("Lista vazia\n\n");
                    system("pause");
                    system("cls");
                    continue;
                }

                printf("Detetar gelados abaixo do limite\n");
                printf("----------------------------------\n\n");
                printf("\tQual e o limite: ");
                scanf("%d", &quant);
                lista_sabores_em_falta(head, quant);
                system("pause");
                system ("cls");
            break;

            case 6:
                printf("Obrigado Volte sempre\n\n");
                system("pause");
                fclose(stdout);
                //return 0;
            break;
        }
    }
}
