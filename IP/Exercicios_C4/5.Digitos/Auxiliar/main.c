#include <stdio.h>
#include <stdlib.h>


void soma_dig(int n){
	int cont = 0, dig, soma = 0, num = n;
	
	while(num != 0){
		num = num / 10;	
		cont ++; 
	}
	
	while(cont != 0){
		dig = n / pow(10, cont - 1);
		printf("\nDig. %d", dig);
		soma = soma + dig;
		n = n - (dig * pow(10, cont - 1));
		cont--;
	}
	printf("\n\nSoma dos digitos.: %d", soma);
}


int main() {
	int num;
	
	do{
		printf("Numero natural positivo: ");	
		scanf("%d", &num);
	}while(num < 0);
	
	soma_dig(num);
	
	return 0;
}