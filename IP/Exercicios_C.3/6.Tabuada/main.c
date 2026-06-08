#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int n, i=0;
	
	printf("Entre com um numero entre 1 e 100: ");
	scanf("%d", &n);
	

		while (n<1 || n>100){
			printf("\n\nErro!---------");
			printf("\nEntre com um numero entre 1 e 100: ");
			scanf("%d", &n);	
		}
		
		while(i<=10){
			printf("\n%d x %d = %d", n, i, n*i);
			i++;
		}
		
	return 0;
}