#include <stdio.h>

int main() {
	
	int i, x, soma=0;
	
	/*while(i<5){
		printf("Num %d: ", i+1);
		scanf("%d", &x);
		
		soma= soma+x;
		i++;
	}*/
	
	for(i=0; i<5; i++){
	printf("Num %d: ", i+1);
		scanf("%d", &x);
		
		soma= soma+x;	
		
	}
	
	printf("\n\nSoma dos cinco= %d", soma);
	
	return 0;
}