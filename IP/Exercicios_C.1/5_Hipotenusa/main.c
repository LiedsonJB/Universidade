#include <stdio.h>
#include <stdlib.h>

//Este programa calcula o valor da hipotenusa de um triangulo retangulo

int main() {
	
int co, ca;
float hip;

	printf("Cateto Oposto: ");
	scanf("%d", &co);
	printf("\nCateto Adjacente: ");
	scanf("%d", &ca);
	
	hip= sqrt(pow(co,2)+pow(ca,2));
	
	printf("\nHipotenusa: %f", hip);
	
	return 0;
}