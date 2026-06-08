#include <stdio.h>
#include <stdlib.h>


int main() {
	
	int n, i, j, k;
	
	do{
	printf("Valor maior ou igual a 2: ");
	scanf("%d", &n);		
	}while(n<2);
	
	for(i=1; i<=n; i++){
		printf("\n");
		for(j=1;j<i;j++){
			printf("%d", j);
			for(k=j;k>1;k--){
				printf("%d", k);
			}
		}
	}
	
	return 0;
} 