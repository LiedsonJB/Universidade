#include <stdio.h>
#include <stdlib.h>
// float.h , DBL_min e DBL_max;

float media(int q){
	int i=0, s=0, n;
	
	printf("Digite os %d numeros:\n", q);
	while(i<q){
		scanf("%d", &n);
		s=s+n;
		i++;
}	
	return s/q;
}


int main() {
	int quant;
	printf("Quantos numeros pretende introduzir?: ");
	scanf("%d", &quant);
	
	printf("\nA media: %.3f", media(quant));

	return 0;
}