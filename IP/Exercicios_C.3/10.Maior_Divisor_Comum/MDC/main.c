#include <stdio.h>
#include <stdlib.h>


int main() {
	
	int a, b, resto;
	
	printf("Entre com dois numeros inteiros positivos: ");
	scanf("%d%d", &a,&b);
	
	
while(b!=0){
	resto= a%b;
	a=b;
	b=resto;
}
printf("\nO maior divisor comum entre eles e %d.", a);
	//printf("\n\n%d", 6%24);
	return 0;
}