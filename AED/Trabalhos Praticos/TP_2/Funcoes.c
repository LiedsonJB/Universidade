#include "Biblioteca.h"

int menu(){
    int op;

    do{

        printf("------------------------ Menu Inicial ------------------------\n\n");
        printf("\t1. Introduzir um novo sabor\n\t2. Atualizar quantidade de um sabor\n\t3. Detetar quantidade abaixo do limite\n\t4. Remover algum sabor\n\t5. Ver a lista\n\t6. Sair\n\nEscolha: ");
        scanf("%d", &op);

        system ("cls");
        printf("Analisando a resposta por favor aguarda!!!!\n\n");
        sleep(2);

        if(op < 1 || op > 6){
            printf("Opcao errada!!!!\nEscolha novamente\n");
            system("pause");
            system("cls");
    }

    }while(op < 1 || op > 6);

    printf("Resposta aceita\n");
    system("pause");
    system ("cls");

    return op;
}

char *ler(){
    char *nome, aux[50];

    printf("\tNome do gelado: ");
    fgets(aux, 50, stdin);
    aux[strcspn(aux, "\n")] = 0;

    nome = malloc(strlen(aux)*sizeof(char)+1);
    if(nome == NULL){
        printf("\nErro de alocacao");
        free(nome);

        exit(EXIT_FAILURE);
   }
    strcpy(nome, aux);

    return nome;
}

int compare(char *Nome1, char *Nome2){

    if(strcmp(Nome1, Nome2) == 0)
        return 0;
    else if(strcmp(Nome1, Nome2) > 0)
        return 1;
    else
        return -1;
}

Lista insere_Gelado(Lista head, char *nome, int quant){
    Lista atual, anterior, Novo;

    if(head == NULL || compare(nome, head->Nome) <= 0){
        if(head != NULL){
            if(compare(nome, head->Nome) == 0){
                head->quantidade += quant;
                return head;
            }else{
                Novo = (Lista) malloc(sizeof(struct node));
                if(Novo == NULL){
                    printf("Erro de alocacao");
                    free(Novo);
                    exit(EXIT_FAILURE);
                }

                Novo->quantidade = quant;
                Novo->Nome = (char *) malloc(strlen(nome)*sizeof(char)+1);
                if(Novo->Nome == NULL){
                    printf("Erro de alocacao");
                    free(Novo->Nome);
                    free(Novo);
                    exit(EXIT_FAILURE);
                }
                strcpy(Novo->Nome, nome);
                return Novo;
            }
        }else{
            Novo = (Lista) malloc(sizeof(struct node));
            if(Novo == NULL){
                printf("Erro de alocacao");
                free(Novo);
                exit(EXIT_FAILURE);
            }

            Novo->Nome = (char *) malloc(strlen(nome)*sizeof(char)+1);

            if(Novo->Nome == NULL){
                printf("Erro de alocacao");
                free(Novo->Nome);
                free(Novo);
                exit(EXIT_FAILURE);
            }

            strcpy(Novo->Nome, nome);
            Novo->quantidade = quant;
            Novo->next = head;
            return Novo;
        }
    }

    atual = head;
    anterior = NULL;

    while(atual != NULL && compare(nome, atual->Nome) >= 0){
         if(compare(nome, atual->Nome) == 0){
          atual->quantidade = atual->quantidade + quant;
            return head;
        }

        anterior = atual;
        atual = atual->next;
    }

    Novo = (Lista) malloc(sizeof(struct node));
    if(Novo == NULL){
        printf("Erro de alocacao");
        free(Novo);
        exit(EXIT_FAILURE);
    }

    Novo->Nome = (char *) malloc(strlen(nome)*sizeof(char)+1);
    if(Novo->Nome == NULL){
        printf("Erro de alocacao");
        free(Novo->Nome);
        free(Novo);
        exit(EXIT_FAILURE);
    }
    strcpy(Novo->Nome, nome);
    Novo->quantidade = quant;

    anterior->next = Novo;
    Novo->next = atual;

    return head;
}

void mostrar(Lista head){

    printf("Lista de gelados desponiveis\n");
    printf("---------------------------------\n");

    for(Lista i = head; i != NULL; i = i->next){
        printf("\tSabor: %s\n\tQuantidade disponivel: %d\n", i->Nome, i->quantidade);
        printf("---------------------------------\n");
    }
}

void lista_sabores_em_falta(Lista head, int limite){

    printf("Lista de gelados abaixo do Limite: %d\n", limite);
    printf("--------------------------------------\n");

     for(Lista i = head; i != NULL; i = i->next){
        if(i->quantidade <= limite)
            printf("\tEste sabor: %s com a quantidade de: %d\n", i->Nome, i->quantidade);
     }
     printf("--------------------------------------\n");
}

int atualizar(Lista head, int quant, char *gelado){

    for(Lista i = head; i != NULL; i = i->next){
        if(compare(i->Nome, gelado) == 0){
            i->quantidade +=quant ;
            return 1;
        }
    }
    return 0;
}

Lista deletar(Lista head, char *name){

    Lista atual =  head;
    Lista anterior = NULL;

    if((atual->next == NULL && compare(name, atual->Nome) == 0) || compare(name, atual->Nome) == 0){
        head = atual->next;
        free(atual->Nome);

        free(atual);
        printf("Eliminacao bem sucedida\n\n");

        return head;

    }else{
        for(atual = head, anterior = NULL; atual != NULL; anterior = atual, atual = atual->next)
            if(compare(atual->Nome, name) == 0)
                break;

        if(atual == NULL)
            printf("Impossivel eliminar por nao pertencer aos dados\n\n");
        else{
            anterior->next = atual->next;
            free(atual->Nome);
            free(atual);
            printf("Eliminacao bem sucedida\n\n");
        }
    }

    system("pause");
    system("cls");

    return head;
}
