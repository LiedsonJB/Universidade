#include "biblioteca.h"

Lista inserir(Lista raiz, int item){
    Lista novo, atual, anterior;

    novo = (Lista) malloc(sizeof(struct node));
    if(novo == NULL){
        printf("Erro ao alocar espaco\n");
        exit(EXIT_FAILURE);
    }

    novo->dir = NULL;
    novo->esq = NULL;
    novo->Valor = item;

    if(raiz == NULL)
        return novo;

    atual = raiz;
   anterior = NULL;

    while(atual != NULL){
        if(atual->Valor > item){
            anterior = atual;
            atual = atual->esq;
        }else{
            anterior = atual;
            atual = atual->dir;
        }
    }
    if(anterior->Valor > item)
      anterior->esq = novo;
   else
      anterior->dir = novo;
    atual = novo;

    return raiz;
}

int procura(Lista raiz, int item){
    Lista atual = raiz;

    while(atual != NULL){
        if(atual->Valor == item)
            return 1;       //retornar 1 se foi encontrado
        else if(atual->Valor > item)        //procurar se ta a esquerda
            atual=atual->esq;
        else         //caso que nao esteja a esquerda para ir para direita
            atual=atual->dir;
    }
    return 0;       //retornar 0 se nao foi encontrado
}

void ImprimirEmOrdem(Lista Raiz){

    if (Raiz == NULL)
    return;

    ImprimirEmOrdem(Raiz->esq);
    printf("\n\tRaiz: %d\n",Raiz->Valor);
    ImprimirEmOrdem(Raiz->dir);
}

void ImprimirEmPosOrdem(Lista raiz){
    if(raiz == NULL)
        return;

    ImprimirEmPosOrdem(raiz->esq);
    ImprimirEmPosOrdem(raiz->dir);
    printf("\n\tRaiz: %d\n",raiz->Valor);

}

void preOrdem(Lista raiz){
    if(raiz == NULL)
        return;

    printf("\n\tRaiz: %d\n", raiz->Valor);
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
}

int menu(){
    int op;

    do{
        printf("----------------- Menu Inicial -----------------\n\n");
        printf("\t1. Adicionar elemento \n\t2. Procurar\n\t3. Imprimir em ordem\n\t4. Imprimir pos ordem\n\t5. Imprimir pre ordem\n\t6. Maior Elemento\n\t7. Menor Elemento\n\t0. Sair\n\n");
        printf("Escolha: ");
        scanf("%d", &op);

        system ("cls");
        printf("Analisando a resposta por favor aguarda!!!!");
        sleep(1);
        if(op < 0 || op > 7){
            printf("\n\n\aErro: Opcao invalida por favor introduza Novamente\n\n");
            system("pause");
            system("cls");
        }else{

            printf("\n\nResposta aceita\n\n");
            system("pause");
            system("cls");

        }

    }while(op < 0 || op > 7);

    return op;
}


int maiorElemento(Lista raiz){

    Lista atual, ant;
    atual = raiz;
    ant = NULL;

    while(atual != NULL){
        ant = atual;
        atual=atual->dir;
    }
    return ant->Valor;
}

int menorElemento(Lista raiz){
    Lista atual, ant;
    atual = raiz;
    ant = NULL;

    while(atual != NULL){
        ant = atual;
        atual=atual->esq;
    }
    return ant->Valor;
}

int menorElementoRecursivo(Lista raiz){
    if(raiz->esq != NULL)
        return raiz->Valor;
    else
        return menorElementoRecursivo(raiz->esq);
}

int maiorElementoRecursivo(Lista raiz){
    if(raiz->dir != NULL)
        return raiz->Valor;
    else
        return menorElementoRecursivo(raiz->dir);
}
