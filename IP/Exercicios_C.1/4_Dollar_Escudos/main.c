#include <stdio.h>
#include <stdlib.h>

//Este programa converte dollars para escudos Cabo-Verdianos

int main() {
	
	float USD, CVE;
	
	printf("Dollars: ");
	scanf("%f", &USD);
	
	CVE= USD * 104.703;
	
	printf("\n%0.3f USD equivale a %0.3f CVE", USD, CVE);
	
	
	return 0;
}