#include "biblioteca.h"

lista insere_gelado(lista head, char *gelad, unsigned int quantidade){
   lista novo = (lista) malloc(sizeof(struct node));//alocar espaco para a estrutura

   if(novo == NULL){
        printf("\nErro de alocacao de espaco");
        free(novo);
        exit(EXIT_FAILURE);//sair se nao conseguir alocar
   }

   strcpy(novo->gelado, gelad);//copiar para gelado o nome do gelado
   novo->quant = quantidade;//copiar a quantidade

   if(head == NULL || strcmp(gelad, head->gelado) < 0){
        novo->next = head;//caso primeiro elemento for menor de todos
        return novo;//retornar o novo
   }

   lista atual = head;
   lista anterior = NULL;

   while(atual != NULL && strcmp(gelad, atual->gelado) > 0){//encontrar o logar certo
        anterior = atual;
        atual = atual->next;
   }

   anterior->next = novo;
   novo->next = atual;

   return head;
}

   /*lista atual = head;
   lista anterior = NULL;

   if(head == NULL){
        strcpy(novo->gelado, gelad);
        novo->quant = quantidade;
        novo->next = head;
        return novo;
   }

   while(atual != NULL){
        if(strcmp(gelad, atual->gelado) == 0)
            atual->quant = quantidade;

        else if( strcmp(gelad, atual->gelado) > 0){
            strcpy(novo->gelado, gelad);
            novo->quant = quantidade;
            novo->next = atual;
        }else{
            strcpy(novo->gelado, gelad);
            novo->quant = quantidade;
            novo->next = atual;
        }

        anterior = atual;
        atual = atual->next;
   }

   return head;*/
//}

void lista_sabores_em_falta(lista head, int limite){//imprimir inferior ao limite
    lista i;
    printf("\n\nMenor do limite %d\n\n", limite);
    for(i=head; i!=NULL; i=i->next){
        if(limite > i->quant)
            printf("%s - %d\n\n", i->gelado, i->quant);
    }
}

void imprimir(lista head){//imprimir a lista
    printf("Lista\n\n");
    for(lista i=head; i!=NULL; i=i->next)
        printf("%s  -  %d\n\n", i->gelado, i->quant);

}
