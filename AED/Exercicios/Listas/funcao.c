#include "funcao.h"

int Menu(){

    int op;

    printf("----------Menu Inicial----------\n\n");
    printf("\t1. Mostrar conteudo da lista\n\t2. Criar uma Lista\n\t3. Adicionar um novo campo\n\t4. Remover um campo\n\t5. Sair\n");
    printf("\nEscolha: ");
    scanf("%d", &op);
    printf("\n---------------------------\n");

    return op;

}

void criar(link *head){
    *head = NULL;
}

int vazia(link head){
    return (head == NULL);
}

link NEW(char* text){

    link x = (link) malloc(sizeof(struct node));
    x->text = (char*) malloc(sizeof(char)*(strlen(text)+1));
    strcpy(x->text, text);
    x->next = NULL;

    return x;
}

link insertEnd(link head, char* text){
    link x;
    if(head == NULL)
    return NEW(text);
    for(x = head; x->next != NULL; x = x->next)
        ;
    x->next = NEW(text);
    return head;
}

link procura(link head, char* text){
    link t;
    for(t = head; t != NULL; t = t->next)
        if(strcmp(t->text, text) == 0)
            return t;
    return NULL;
}

link Remover(link head, char* text){
    link t, x;
    for(t = head, x = NULL; t != NULL; x = t, t = t->next){
        if(strcmp(t->text, text) == 0){
            if(t == head)
                head = t->next;
            else
                x->next = t->next;
            free(t);
        }
    }
    return head;
}

link insertBegin(link head, char* text){
    link x = NEW(text);
    x->next = head;
    return x;
}

void mostrar(link head){
    int k;
    printf("Elementos na lista \n");
    for(link i=head, k=0; i != NULL; i = i->next, k++){
        printf("%d - %s", k+1, i->text);
    }
}
int submenu(){
    int op;

    printf("1. No inicio\n2. no fim\nescolha: ");
    scanf("%d", &op);

    return op;
}
