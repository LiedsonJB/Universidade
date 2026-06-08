#include "biblioteca.h"

int main(){
    Lista Raiz = NULL;
    int op;
    int valor;

    while(1){

        op = menu();

        switch(op){

            case 1:
                printf("Qual e o valor para ser introduzido: ");
                scanf("%d", &valor);

                Raiz = inserir(Raiz, valor);

                printf("\nValor introduzido\n");
                system("pause");
                system("cls");
            break;

            case 2:
                if(Raiz == NULL){
                    printf("Lista vazia!!!\n\n");
                }else{
                    int valorProcura;
                    printf("Procurar qual valor: ");
                    scanf("%d", &valorProcura);
                    int resultadoBusca  = procura(Raiz, valorProcura);
                    printf("----------------------------\n");
                    if(resultadoBusca == 0){
                        printf("\nEste valor %d, nao se encontra na lista!!!\n", valorProcura);
                    }else{
                        printf("\nEste valor %d, se encontra disponivel na lista!!!\n", valorProcura);
                    }
                }
                system("pause");
                system("cls");

            break;

            case 3:
                if(Raiz == NULL){
                    printf("Lista vazia!!!\n\n");
                }else{
                    printf("Valores em ordem\n");
                    printf("----------------------------\n");
                    ImprimirEmOrdem(Raiz);
                    printf("\n----------------------------\n");
                }
                system("pause");
                system("cls");

            break;

            case 4:
                if(Raiz == NULL){
                    printf("Lista vazia!!!\n\n");
                }else{
                    printf("Valores em pos ordem\n");
                    printf("----------------------------\n");
                    ImprimirEmPosOrdem(Raiz);
                    printf("\n----------------------------\n");
                }
                system("pause");
                system("cls");

            break;

            case 5:
                if(Raiz == NULL){
                    printf("Lista vazia!!!\n\n");
                }else{
                    printf("Valores em pre ordem\n");
                    printf("----------------------------\n");
                    preOrdem(Raiz);
                    printf("\n----------------------------\n");
                }
                system("pause");
                system("cls");
            break;

             case 6:
                if(Raiz == NULL){
                    printf("Lista vazia!!!\n\n");
                }else{
                    int maior = maiorElemento(Raiz);
                    printf("Maior Elemento: %d\n", maior);
                    printf("----------------------------\n");
                }
                system("pause");
                system("cls");
            break;

            case 7:
                if(Raiz == NULL){
                    printf("Lista vazia!!!\n\n");
                }else{
                    int menor = menorElemento(Raiz);
                    printf("Menor Elemento: %d\n", menor);
                    printf("----------------------------\n");
                }
                system("pause");
                system("cls");
            break;

            case 0:
                system("cls");
                printf("Obrigado volte sempre!!!\n--------------------------------------\n\n");
                return 0;
            break;
        }
    }


}
