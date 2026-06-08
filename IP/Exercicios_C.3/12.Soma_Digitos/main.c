#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int n, soma=0, d;
	
	printf("Insira um numero inteiro positivo: ");
	scanf("%d", &n);
		
	while(n>0){
		d=n%10;
		soma=soma + d;
		n=n/10;
		
	}
	printf("\nA soma dos digitos e: %d", soma);
	
	return 0;
}