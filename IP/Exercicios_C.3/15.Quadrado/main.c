#include <stdio.h>
#include <stdlib.h>


int main() {
	int N, j=0, i;
	system("color a");
	do{	
	printf("Introduva um valor maior ou igual a dois: ");
	scanf("%d", &N);
	}while(N<2);
	
	for(i=1; i<=N; i++){
		printf("\n");
		for(j=j+i; j<=N+1;j++){
			printf("%d ", j);
		}	
	}
	
	
	
	return 0;
}