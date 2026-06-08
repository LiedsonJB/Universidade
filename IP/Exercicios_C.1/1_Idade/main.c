#include <stdio.h>
#include <stdlib.h>

//Quantos anos tem o usoário

int main() {
	
	int ano_nasc, idade;
	
	printf("Que ano nasceste?: ");
	scanf("%d", &ano_nasc);
	
	idade= 2023-ano_nasc;
	
		printf("\nTens %d anos!", idade);
	
	return 0;
}