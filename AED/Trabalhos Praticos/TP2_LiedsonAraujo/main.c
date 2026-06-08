#include "biblioteca.h"

int main(){
    lista head = NULL;

    head = insere_gelado(head, "Uva", 15);
    head = insere_gelado(head, "pistacio", 40);
    head = insere_gelado(head, "morango", 10);
    head = insere_gelado(head, "framboesa", 60);
    head = insere_gelado(head, "caramelo", 35);
    head = insere_gelado(head, "banana", 40);

    imprimir(head);

    lista_sabores_em_falta(head, 35);

    return 0;
}
