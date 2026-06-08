#include "biblioteca.h"

int main(){
    setlocale(LC_ALL,"PORTUGUESE");

    PALUNO head = NULL;
    int op, numero;
    char *nome;

    while(1){
        op = menu();

        switch(op){

            case 1:
                fflush(stdin);
                nome = Lernome();
                printf("\nO numero do estudante: ");
                scanf("%d", &numero);

                head = insertStudentSorted(head, nome, numero);

                system("cls");
                printf("Estudante introduzido na lista!!!\n\n");
                system("pause");
                system("cls");
            break;

            case 2:
                if(head == NULL){
                    printf("Lista vazia!!!\n\n");
                    system("pause");
                    system("cls");
                }else{
                    fflush(stdin);
                    nome = Lernome();

                    head = deleteStudent(head, nome);
                }
            break;

            case 3:
                if(head == NULL){
                    printf("Lista vazia!!!\n\n");
                    system("pause");
                    system("cls");
                }else{
                    printf("Qual numero estas a procurar: ");
                    scanf("%d", &numero);

                    op = searchBynumber(head, numero);

                    system("cls");
                    printf("Consultando a lista por favor aguarde");
                    sleep(2);
                    system("cls");

                    if(op == 1)
                        printf("Este numero %d, esta na lista\n\n", numero);
                    else
                        printf("Nao foi encontado");

                    system("pause");
                    system("cls");
                }
            break;

            case 4:
                if(head == NULL){
                    printf("Lista vazia!!!\n\n");
                    system("pause");
                    system("cls");
                }else{
                    fflush(stdin);
                    nome = Lernome();
                    op = searchByname(head, nome);

                    system("cls");
                    printf("Consultando a lista por favor aguarde");
                    sleep(2);
                    system("cls");

                    if(op == 1)
                        printf("Este nome %s esta na lista\n", nome);
                    else
                        printf("Este nome %s nao esta na lista\n\n", nome);

                    system("pause");
                    system("cls");
                }
            break;

            case 5:
                if(head == NULL){
                    printf("Lista vazia!!!\n\n");
                    system("pause");
                    system("cls");
                }else{
                    print_Lista(head);
                }
                system("pause");
                system("cls");
            break;

            case 6:
                system("cls");
                printf("Obrigado volte sempre\n");
                return 0;
            break;
        }
    }

    return 0;
}
