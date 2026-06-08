#include <stdio.h>
#include <stdlib.h>


int main() {
	
	int id, FCR, i=55, c=54;
	
	printf("Informe sua idade: ");
	scanf("%d", &id);
	printf("Informe sua FCR: ");
	scanf("%d", &FCR);
	
	printf("\n");
	printf("Intensidade | Frequencia\n------------|------------");
	while(i<95){
		
		printf("\n%d|  %d      | %d ", i-c, i, (((220 - id) - FCR) * i)+ FCR);
		c=c+4;
		i+=5;
		
	}
	
		
	return 0;
}