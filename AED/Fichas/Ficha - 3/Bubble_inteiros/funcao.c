#include "funcao.h"

int binaria(int *v, int n, int A){
    int inicio = 0, fim = n - 1;

    while(inicio <= fim){
        int meio = (inicio + fim) / 2;
        if(A == v[meio])
            return meio;
        else{
            if(A > v[meio])
                inicio = meio + 1;
            else
                fim = meio - 1;
        }
   }
    return -1;
}

int *realocar(int *v, int n){

    v = (int *) realloc(v, sizeof(int) * n);
    return v;
}

void linear(int *v, int n){
    int op, x, m, i;

    do{
        printf("-------------- Pesquisa linear de elementos --------------\n\n");
        printf("\t1. Maior\n\t2. Menor\n\t3. Aleatorio na tabela\n\t4. Voltar ao menu anterior\n\t5. Sair do programa");
        printf("\n\nEscolha: ");
        scanf("%d", &op);

        switch (op){

            case 1:
                m = v[0];
                for(i = 0; i < n; i++){
                    if(v[i] > m){
                        m = v[i];
                        x = i;
                    }
                }
                printf("O maior elemento: %d\n\nEncontra-se na posicao: %d", m, x+1);
            break;

            case 2:
                m = v[0];
                for(i = 0; i < n; i++){
                    if(v[i] < m){
                        m = v[i];
                        x = i;
                    }
                }
                printf("O menor elemento: %d\nEncontra-se na posicao: %d", m, x+1);
            break;

            case 3:
                printf("Seu Elemento a procura: ");
                scanf("%d", &x);

                for(i = 0; i < n; i++){
                    if(v[i] == x){
                        printf("Elemento encontrado na posicao %d", i+1);
                        break;
                    }
                }
                if(n == i)
                    printf("\nEsse elemento nao existe");
            break;

            case 4:
                system("cls");
                subMenu2(v, n);
            break;

            case 5:
                system("cls");
                printf("\nObrigado volte sempre\n");
                return;
            break;

            default:
                printf("\nErro: Numero invalido\n\n");
            break;

        }
    }while(op < 1 || op > 5);
}

void menu_inicial(int *v, int n){
    system("color 9");
    int op, op1;

    do{
        printf("-------------- Menu Prinical --------------\n\n");
        printf("\t1. Ordenacao de dados\n\t2. Pesquisar dados\n\t3. Mostrar tabela com os valores\n\t4. Realocar novo espaco(Altera a tabela)\n\t5. Gerar novos dados\n\t6. Sair do programa");
        printf("\n\nEscolha: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                system("cls");
                subMenu1(v, n);
            break;

            case 2:
                system("cls");
                subMenu2(v, n);
            break;

            case 3:
                mostrar(v, n);
                printf("\n\n------------------------------\n\n");

                do{
                    printf("1. Voltar ao menu anterior\n2. sair do programa");
                    printf("\n\nEscolha: ");
                    scanf("%d", &op1);
                    if(op1 == 1){
                        system("cls");
                        menu_inicial(v, n);
                    }else if(op1 == 2){
                        system("cls");
                        printf("\nObrigado volte sempre\n");
                        break;
                    }else
                        printf("\nErro: Numero invalido\n\n");
                }while(op1 < 1 || op1 > 2);

            break;

            case 6:
                system("cls");
                printf("\nObrigado volte sempre\n");
                return;
            break;

            case 5:
                ler(v, n);
                printf("Novos dados gerados!!!");
                printf("\n\n------------------------------\n\n");

                do{
                    printf("1. Voltar ao menu anterior\n2. sair do programa");
                    printf("\n\nEscolha: ");
                    scanf("%d", &op1);
                    if(op1 == 1){
                        system("cls");
                        menu_inicial(v, n);
                    }else if(op1 == 2){
                        system("cls");
                        printf("\nObrigado volte sempre\n");
                        return;
                        break;
                    }else
                        printf("\nErro: Numero invalido\n\n");
                }while(op1 < 1 || op1 > 2);
            break;

            case 4:
                system("cls");
                printf("Analisando se e possivel");
                sleep(2);
                system("cls");
                printf("Quantos elementos queres: ");
                scanf("%d", &n);

                v = realocar(v, n);
                 if(v != NULL){
                    system("cls");
                    printf("Alocacao feita com sucesso!!!!\nPrime alguma tecla para continuar\n");

                    system("pause");
                    system("cls");

                    ler(v, n);
                    printf("Tabela alterada com sucesso com os %d campos solicitados", n);

                }else{
                    system("cls");
                    printf("\nErro: Impossivel alocar espaco");
                    return;
                }

                do{
                    printf("\n\n------------------------------\n\n");
                    printf("1. Voltar ao menu anterior\n2. sair do programa");
                    printf("\n\nEscolha: ");
                    scanf("%d", &op1);
                    if(op1 == 1){
                        system("cls");
                        menu_inicial(v, n);
                    }else if(op1 == 2){
                        system("cls");
                        printf("\nObrigado volte sempre\n");
                        break;
                    }else
                        printf("\nErro: Numero invalido\n\n");
                }while(op1 < 1 || op1 > 2);
            break;

            default:
                printf("\nErro: Numero invalido\n\n");
            break;
        }

    }while(op < 1 || op > 4);

}

void subMenu1(int *v, int n){
    int op, op1;

    do{
        printf("-------------- Menu de Ordenacao --------------\n\n");
        printf("\t1. bubble\n\t2. selection\n\t3. insertion\n\t4. Heap\n\t5. Quick\n\t6. Merge\n\t7. Voltar ao menu anterior\n\t8. sair do programa");
        printf("\n\nEscolha: ");
        scanf("%d", &op);

        switch(op){

            case 1:
                bubble1(v, n);
                printf("\nElementos ordenados pelo bubble\n");
                mostrar(v, n);

                do{
                    printf("\n\n------------------------------\n\n");
                    printf("1. Voltar ao menu anterior\n2. sair do programa");
                    printf("\n\nEscolha: ");
                    scanf("%d", &op1);
                    if(op1 == 1){
                        system("cls");
                        subMenu1(v, n);
                    }else if(op1 == 2){
                        system("cls");
                        printf("\nObrigado volte sempre\n");
                        break;
                    }else
                        printf("\nErro 12: Numero invalido\n\n");
                }while(op1 < 1 || op1 > 2);
            break;

            case 2:
                selection(v, 0,n);
                printf("\nElementos ordenados pelo selection\n");
                mostrar(v, n);

                do{
                    printf("\n\n------------------------------\n\n");
                    printf("1. Voltar ao menu anterior\n2. sair do programa");
                    printf("\n\nEscolha: ");
                    scanf("%d", &op1);
                    if(op1 == 1){
                        system("cls");
                        subMenu1(v, n);
                    }else if(op1 == 2){
                        system("cls");
                        printf("\nObrigado volte sempre\n");
                        break;
                    }else
                        printf("\nErro 12: Numero invalido\n\n");
                }while(op1 < 1 || op1 > 2);
            break;

            case 3:
                insertion(v, 0,n);
                printf("\nElementos ordenados pelo insertion\n");
                mostrar(v, n);
                do{
                    printf("\n\n------------------------------\n\n");
                    printf("1. Voltar ao menu anterior\n2. sair do programa");
                    printf("\n\nEscolha: ");
                    scanf("%d", &op1);
                    if(op1 == 1){
                        system("cls");
                        subMenu1(v, n);
                    }else if(op1 == 2){
                        system("cls");
                        printf("\nObrigado volte sempre\n");
                        break;
                    }else
                        printf("\nErro 12: Numero invalido\n\n");
                }while(op1 < 1 || op1 > 2);
            break;

            case 4:
                heapsort(v, n);
                printf("\nElementos ordenados pelo heap\n");
                mostrar(v, n);
                do{
                    printf("\n\n------------------------------\n\n");
                    printf("1. Voltar ao menu anterior\n2. sair do programa");
                    printf("\n\nEscolha: ");
                    scanf("%d", &op1);
                    if(op1 == 1){
                        system("cls");
                        subMenu1(v, n);
                    }else if(op1 == 2){
                        system("cls");
                        printf("\nObrigado volte sempre\n");
                        break;
                    }else
                        printf("\nErro 12: Numero invalido\n\n");
                }while(op1 < 1 || op1 > 2);
            break;

            case 5:
                quicksort(v, 0,n);
                printf("\nElementos ordenados pelo quick\n");
                mostrar(v, n);
                do{
                    printf("\n\n------------------------------\n\n");
                    printf("1. Voltar ao menu anterior\n2. sair do programa");
                    printf("\n\nEscolha: ");
                    scanf("%d", &op1);
                    if(op1 == 1){
                        system("cls");
                        subMenu1(v, n);
                    }else if(op1 == 2){
                        system("cls");
                        printf("\nObrigado volte sempre\n");
                        break;
                    }else
                        printf("\nErro 12: Numero invalido\n\n");
                }while(op1 < 1 || op1 > 2);
            break;

            case 6:
                mergesort(v, 0, n);
                printf("\n\nElementos ordenados pelo Merge\n");
                mostrar(v, n);

                do{
                    printf("\n\n------------------------------\n\n");
                    printf("1. Voltar ao menu anterior\n2. sair do programa");
                    printf("\n\nEscolha: ");
                    scanf("%d", &op1);
                    if(op1 == 1){
                        system("cls");
                        subMenu1(v, n);
                    }else if(op1 == 2){
                        system("cls");
                        printf("\nObrigado volte sempre\n");
                        break;
                    }else
                        printf("\nErro 12: Numero invalido\n\n");
                }while(op1 < 1 || op1 > 2);
            break;

             case 7:
                system("cls");
                menu_inicial(v, n);
            break;

             case 8:
                system("cls");
                printf("\nObrigado volte sempre\n");
                return;
            break;

            default:
                printf("\nErro!!- Numero invalido\n");
            break;
        }

    }while(op < 1 || op > 6);

}

void subMenu2(int *v, int n){
    int op, op1, x, k;

    do{
        printf("-------------- Menu Pesquisa de dados --------------\n\n");
        printf("\t1. Pesquisa Linear\n\t2. Pesquisa Binaria\n\t3. Voltar ao menu anterior\n\t4. Sair do programa");
        printf("\n\nEscolha: ");
        scanf("%d", &op);

        switch(op){

            case 1:
                linear(v, n);
                printf("\n\n------------------------------\n\n");
                 do{
                    printf("1. Voltar ao menu anterior\n2. sair do programa");
                    printf("\n\nEscolha: ");
                    scanf("%d", &op1);
                    if(op1 == 1){
                        system("cls");
                        menu_inicial(v, n);
                    }else if(op1 == 2){
                        system("cls");
                        printf("\nObrigado volte sempre\n");
                        break;
                    }else
                        printf("\nErro 12: Numero invalido\n\n");
                }while(op1 < 1 || op1 > 2);
            break;

            case 2:
                quicksort(v, 0, n);
                printf("Qual elemento procuras: ");
                scanf("%d", &x);
                printf("\n\n------------------------------\n\n");
                k = binaria(v, n, x);

                if(k == -1)
                    printf("\nNao foi enontrado");
                else
                    printf("\nElemento encontrado na %d posicao\n", k+1);

                 do{
                    printf("\n\n------------------------------\n\n");
                    printf("1. Voltar ao menu anterior\n2. sair do programa");
                    printf("\n\nEscolha: ");
                    scanf("%d", &op1);
                    if(op1 == 1){
                        system("cls");
                        menu_inicial(v, n);
                    }else if(op1 == 2){
                        system("cls");
                        printf("\nObrigado volte sempre\n");
                        return;
                        break;
                    }else
                        printf("\nErro 12: Numero invalido\n\n");
                }while(op1 < 1 || op1 > 2);
            break;

            case 3:
                system("cls");
                menu_inicial(v, n);
            break;

             case 4:
                system("cls");
                printf("\nObrigado volte sempre\n");
                return;
            break;

            default:
                printf("\nErro 12: Numero invalido\n\n");
            break;
        }

    }while(op < 1 || op > 4);

}

void bubble1(int *v, int T){

    for(int i=0; i<T; i++){
        for(int j=0; j<T-i; j++){
            compexch(v[j], v[j+1]);
        }
    }
}

int *alocar(int *v, int n){

    v = (int *) malloc(n * sizeof(int));

    return v;
}

void ler(int *v, int n){
    srand (time(NULL));

    for(int i=0; i<n; i++)
        v[i] = rand()%100 + 1;

}

void mostrar(int *v, int n){
    printf("Valores na tabela\n---------------------------------\n");
    for(int i=0; i<n; i++){
        printf("\t%d valor: %d\n----------------------------\n", i+1, v[i]);
    }
}

void selection(int a[], int l, int r){
    int i, j, min;

    for (i = l; i < r; i++) {
        min = i;
        for (j = i+1; j <= r; j++)
            if (less(a[j], a[min]))
                min = j;
        exch(a[i], a[min]);
    }
}

void insertion(int a[], int l, int r){
    int i;

    /* Coloca menor elemento na primeira posicao */
    for (i = l+1; i <= r; i++)
        compexch(a[l], a[i]);

    for (i = l+2; i <= r; i++) {
        int j = i;

    /* Variavel auxiliar para guardar o valor a[i] */
        int v = a[i];

    /* Enquanto v < a[j] puxar os valores para a direita */
    /* Como o primeiro elemento e' o menor podemos omitir a condicao j>=l */
        while (less(v, a[j-1])) {
            a[j] = a[j-1];
            j--;
        }

    /* Guardar o valor originalmente na posicao i na posicao libertada */
        a[j] = v;
    }
}

int partition(int a[], int l, int r) {
  int i = l-1;
  int j = r;

  /* a[r] 'e o pivot. */
  int v = a[r];

  /* Enquanto o iterador da esquerda for menor que o iterador da direita. */
    while (i < j) {

    /* Enquanto a[i]<v avanca com o i para a direita. */
        while (less(a[++i], v));

            /* Enquanto v<a[j] avanca com o j para a esquerda. */
        while (less(v, a[--j]))
            if (j == l) /* O elemento onde se faz a particao pode ser o primeiro! */
                break;

        /* Trocar, se for o caso! */
        if (i < j)
        exch(a[i], a[j]);
    }

    /* Colocar o pivot na posicao i. */
    exch(a[i], a[r]);

    /* Retorna posicao onde ocorreu a particao. */
    return i;
}

void quicksort(int a[], int l, int r){
    int i;

    if (r <= l)
        return;

    i = partition(a, l, r);
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
}

void FixHeap (int a[], int n, int pos){
    int temp, son;

    if(n <= 1)
        return;

    temp = a[pos];

    for (; pos*2+1 < n; pos = son)
    {
        son = 2*pos+1;
        if (son < n-1 && a[son] < a[son+1])
            son++;

        if (a[son] > temp)
            a[pos] = a[son];
        else
            break;
    }
    a[pos] = temp;
}

void buildheap(Item a[], int n){
  int i;
  for (i = n/2-1; i>=0; i--)
    FixHeap (a, n, i);
}

void heapsort(Item a[], int n){
    int i = n-1;

    buildheap(a,n);

    while (i > 0) {
        exch(a[i], a[0]);
        FixHeap (a, i, 0);
        i--;
    }
}

void merge1(Item a[], int l, int m, int r){
    int *aux = alocar(aux, r);
    int i, j, k;
    for (i = m+1; i > l; i--)
        aux[i-1] = a[i-1];
    for (j = m; j < r; j++)
        aux[r+m-j] = a[j+1];
    for (k = l; k <= r; k++){
        if (less(aux[j], aux[i]))
            a[k] = aux[j--];
        else
            a[k] = aux[i++];
    }
}

void mergesort(Item a[], int l, int r){
    int m = (r+l)/2;

    if (r <= l)
        return;

    mergesort(a, l, m);
    mergesort(a, m+1, r);
    merge1(a, l, m, r);
}
