#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int i=1;
	int soma=0;
	
	while(i<75){
		i++;
		if(i%2==0){
			soma=soma+i;
		}
		else{
			continue;
		}
	}
	printf("\nA soma de numeros pares de 1 a 75= %d", soma);
	
	return 0;
}