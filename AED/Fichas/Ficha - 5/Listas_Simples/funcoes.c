#include "biblioteca.h"

char *newName(char *name){

    char *copia;

    copia = (char *) malloc(strlen(name)*sizeof(char)+1);

    if(copia == NULL){
        printf("\nErro de alocacao");
        free(copia);

        exit(EXIT_FAILURE);
    }

    strcpy(copia, name);

    return copia;

}

void show_student(int number, char *name){

    printf("\tEstudante: %s\n\t\tNumero de estudante: %d\n", name, number);
}

int itemCompare(char *name1, char *name2){
    if(strcmp(name1, name2) == 0)
        return 0;
    else if(strcmp(name1, name2) > 0)
        return 1;
    else
        return -1;
}

PALUNO insertStudentSorted(PALUNO head, char *name, int number){

   PALUNO novoA = (PALUNO) malloc(sizeof(Aluno));


   if(novoA == NULL){
        printf("\nErro de alocacao");
        free(novoA);

        exit(EXIT_FAILURE);
   }

   novoA->numero = number;
   novoA->nome = newName(name);

   if(head == NULL || itemCompare(name, head->nome) < 0){
        novoA->next = head;
        return novoA;
   }

   PALUNO atual = head;
   PALUNO anterior = NULL;

   while(atual != NULL && itemCompare(name, atual->nome) > 0){
        anterior = atual;
        atual = atual->next;
   }

   anterior->next = novoA;
   novoA->next = atual;

   return head;
}
/*
void show(PALUNO head){

    for(PALUNO i = head; i != NULL; i = i->next)
        show_student(i->numero, i->nome, i->curso, i->ano);

}*/

int searchByname(PALUNO head, char *name){

    for(PALUNO i = head; i != NULL; i = i->next)
        if(itemCompare(i->nome, name) == 0)
            return 1;

    return 0;

}

int searchBynumber(PALUNO head, int number){

    for(PALUNO i = head; i != NULL; i = i->next)
        if(number == i->numero)
            return 1;

    return 0;

}

PALUNO deleteStudent(PALUNO head, char *name){
    PALUNO atual =  head;
    PALUNO anterior = NULL;

    if((atual->next == NULL && itemCompare(name, atual->nome) == 0) || itemCompare(name, atual->nome) == 0){
        head = atual->next;
        free(atual->nome);

        free(atual);

        printf("Este nome %s foi eliminado com sucesso!!!\n\n", name);

        return head;

    }else{

        for(atual = head, anterior = NULL; atual != NULL; anterior = atual, atual = atual->next)
            if(itemCompare(atual->nome, name) == 0)
                break;

        if(atual == NULL)
            printf("Este nome %s nao existe na lista entao nao e possivel eliminado\n\n", name);
        else{
            anterior->next = atual->next;
            free(atual->nome);
            free(atual);
            printf("\nEste nome %s foi eliminado com sucesso!!!\n\n", name);
        }
    }

    system("pause");
    system("cls");

    return head;
}

void print_Lista(PALUNO head){
    printf("Lista dos alunos da - UTA -");
    printf("\n---------------------------------\n");
    for(PALUNO i = head; i != NULL; i=i->next){
        show_student(i->numero, i->nome);
        printf("\n---------------------------------\n");
    }
    printf("Fim da lista\n\n");
}

int menu(){
    int op;

    do{
        printf("----------------- Menu Inicial -----------------\n\n");
        printf("\t1. Adicionar elemento a lista\n\t2. Remover elemento da lista\n\t3. Procuar numero na lista\n\t4. Procurar nome na lista\n\t5. Imprimir lista\n\t6. Sair\n\n");
        printf("Escolha: ");
        scanf("%d", &op);

        system ("cls");
        printf("Analisando a resposta por favor aguarda!!!!");
        sleep(2);
        if(op < 1 || op > 6){
            printf("\n\n\aErro: Opcao invalida por favor introduza Novamente\n\n");
            system("pause");
        }else{

            printf("\n\nResposta aceita\n\n");
            system("pause");
            system("cls");

        }

    }while(op < 1 || op > 6);

    return op;
}

char *Lernome(){

    char aux[50], *nome;

    printf("Nome do estudante: ");
    fgets(aux, 50, stdin);

    aux[strcspn(aux, "\n")] = 0;//remover o '\n'

    nome = (char *) malloc(strlen(aux)*sizeof(char)+1);

    if(nome == NULL){
        printf("\nErro de alocacao");
        free(nome);

        exit(EXIT_FAILURE);
   }

    strcpy(nome, aux);

    return nome;
}
