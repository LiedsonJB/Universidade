#include "Biblioteca.h"

int itemCompare(Item i1, Item i2){

    if(strcmp(i1, i2) == 0)
        return 0;
    else if(strcmp(i1, i2) > 0)
        return 1;
    else
        return -1;

}
void showItem(Item i){
    printf(" %s ", i);
}
void deleteItem(Item i){
    free(i);
}
Item newItem (Item i){
    Item *novo = malloc(sizeof(char)*strlen(i)+1);

    if(novo == NULL){
        printf("Erro ao alocar espaco");
        exit(EXIT_FAILURE);
    }

    strcpy(novo, i);

    return novo;
}
lista* create(){
    lista *novo;

    novo = (lista *) malloc(sizeof(lista));

    if(novo == NULL){
        printf("Erro ao alocar espaco");
        exit(EXIT_FAILURE);
    }

    novo->first = NULL;
    novo->last = NULL;

    return novo;
}
void insertBegin(lista* I, Item i){
    link *novo =(link *) malloc(sizeof(struct node));

    if(novo == NULL){
        printf("Erro ao alocar espaco");
        exit(EXIT_FAILURE);
    }

    novo->item = i;
    novo->prev = NULL;
    novo->next = I->first->next;
}
void insertEnd(lista* I, Item i){
    ink *novo =(link *) malloc(sizeof(struct node));

    if(novo == NULL){
        printf("Erro ao alocar espaco");
        exit(EXIT_FAILURE);
    }

    novo->item = i;
    novo->prev = I->last;
    novo->next = NULL;

}
void show(lista* I){
    for(lista j = I->first; j != NULL; j = j->first->next)
        showItem(j->first->item);
}
void removeFirst(lista* I, Item i){
    I->first=I->first->next;
}
