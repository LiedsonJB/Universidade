#include <stdio.h>
#include <stdlib.h>


void soma_dig(int n){
	int dig;
	while(n != 0){
		dig = n % 10;
		n = n / 10;	
		printf("\nDig.: %d", dig);
	}
	
	
}


int main() {
	int num;
	
	do{
			printf("Numero natural positivo: ");	
	scanf("%d", &num);
	}while(num < 0);
	
	soma_dig(num);
	
	return 0;
}