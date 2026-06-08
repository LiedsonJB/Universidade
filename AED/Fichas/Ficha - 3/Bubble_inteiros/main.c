#include "funcao.h"

int main(){
    system("color b");

    int *v = NULL; //criar ponteiro v e pontar para null
    int n;

    printf("Quantos elementos queres: ");
    scanf("%d", &n);

    if(n < 0)
        n *= -1; //caso o utilizador introduzir um numero negativo transforma em positivo

    v = alocar(v, n);

    system("cls");
    system("color A");
    printf("Tentando alocar espaco!!!!!\nPor favor aguarde");
    sleep(2);
    system("cls");

    if(v != NULL){
        printf("Alocacao feita com sucesso!!!!\nPrime alguma tecla para continuar\n");

        system("pause");
        system("cls");

        ler(v, n);

        menu_inicial(v, n);
        free(v);


    }else{
        system("color 0");
        printf("\nErro 1: Impossivel alocar espaco");
        return -1;
    }

    return 0;
}
