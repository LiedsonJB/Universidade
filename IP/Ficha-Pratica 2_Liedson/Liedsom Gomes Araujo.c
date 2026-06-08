#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float calcularValorproduto(int quantidade, float precoUnitario, float desconto){

    return quantidade * precoUnitario - desconto;

}
float calculaTotalFatura(int nProdutos){

    int quantidade, i = 1;
    float precoUnitario, desconto;
    float soma = 0, x;

     while(nProdutos != 0){

        printf("%d Produto\n\n", i);

        printf("Quantidade: ");
        scanf("%d", &quantidade);

        printf("\nPreco Unitario: ");
        scanf("%f", &precoUnitario);

        printf("\nDesconto: ");
        scanf("%f", &desconto);

        system("cls");

        x = calcularValorproduto(quantidade,precoUnitario,desconto);

        soma += x;

        nProdutos--;
        i++;
    }

    return soma;
}

void main(){

   int n;

   printf("Quantos Produtos: ");
   scanf("%d",&n);

   system("cls");

   float x = calculaTotalFatura(n);

   system("cls");
   printf("Por favor espere...\nCarregando dado\n");
   sleep(1);

   system("cls");

   printf("Total a pagar: %.2f\n", x);
}
