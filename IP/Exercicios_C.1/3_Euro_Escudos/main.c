#include <stdio.h>
#include <stdlib.h>

//Este programa converte euro para escudos Cabo-Verdianos

int main() {
	
	float EUR, CVE;
	
	printf("Euros: ");
	scanf("%f", &EUR);
	
	CVE= EUR * 110.265;
	
	printf("\n4%0.3f EUR equivale a %0.3f CVE", EUR, CVE);
	
	
	return 0;
}