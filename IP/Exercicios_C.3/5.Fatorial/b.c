#include <stdio.h>
#include <stdlib.h>



int main() {
	
	int n, fat=1;
	
	printf("Entre com o numero: ");
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++){
	fat= fat*i;	
	}
	
	printf("\n\nO fatorial de %d = %d.", n, fat);
	return 0;
}