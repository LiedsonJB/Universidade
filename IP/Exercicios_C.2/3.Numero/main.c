#include <stdio.h>
#include <stdlib.h>



int main() {
	float num;
	
	printf("Insira um numero: ");
	scanf("%f", &num);
	
	if(num>0)
	printf("\n%.1f - positivo.\n", num);
	else if(num==0)
	printf("\n%.1f - igual a 0.\n", num);
	else	
	printf("\n%.1f - negativo.\n", num);
	
	system ("pause");
	return 0;
}