#include <stdio.h>
#include <stdlib.h>

void quadrado(int n){
	
	for(int i = 0 ; i < n ; i++ ){
		printf("\n");
		for(int j = 0 ; j < n ; j++ ){
			
			if(i % 2){
				if(j % 2){
					printf("X ");
				}else{
					printf("O ");
				}	
			}else{
				if(j % 2){
					printf("O ");
				}else{
					printf("X ");
				}	
			}	
		}
	}	
}

int main() {
	int num;
	do{
		printf("Entre com um valor maior que 2: ");
		scanf("%d", &num);
	}while(num < 2);
	
	quadrado(num);
	
	return 0;
}