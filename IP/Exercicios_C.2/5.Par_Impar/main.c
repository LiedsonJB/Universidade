#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int num;
	
	printf("Insira o numero: ");
	scanf("%d", &num);
	
	if(num%2==0)
	printf("\n%d e par!\n\n", num);
	else
	printf("\n%d e impar!\n\n", num);
	
	
	return 0;
}