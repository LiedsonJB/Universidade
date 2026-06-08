#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void retangle(int L, int C){
	int i, j, num = 10000;
	
	for(i = 0; i < L ; i++){
		printf("\n");
		for(j = 0 ; j < C ; j++){
			if(num % 3 == 0){
				printf("%d ", num);
			}else{
				while(num%3 != 0 ){
					num++;
				}printf("%d ", num);
			}num ++;
					
		}
	}
	
}

int main() {
	int L, C;

	printf("Insira a largura: ");
	scanf("%d", &L);
	printf("Insira o comprimento: ");
	scanf("%d", &C);
	
	retangle(L, C);
	
	return 0;
}