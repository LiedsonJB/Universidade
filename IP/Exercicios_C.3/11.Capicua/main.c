#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, ncpia, inverso=0, dgito;
	
	printf("Entre com um numero inteiro: ");
	scanf("%d", &n);
	
	ncpia = n;
	
	while(ncpia!=0){
		dgito = ncpia % 10;
		inverso= (inverso * 10)+ dgito;
		ncpia = ncpia/10;
		
	}
	
	if( n == inverso){
		printf("\n\nO numero %d e capicua.", inverso);
	}else{
		printf("\n\nO numero nao e capicua.");
	}
	
	
	return 0;
}