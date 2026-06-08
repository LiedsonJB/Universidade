#include <stdio.h>
#include <stdlib.h>


int main() {
	int salario, sal_min;
	
	printf("Introduza o seu salario: ");
	scanf("%d", &salario);
	printf("\nQual o salario minimo?: ");
	scanf("%d", &sal_min);
	
	printf("\n\nPossuis %d salarios minimos!", salario/sal_min);
	
	return 0;
}