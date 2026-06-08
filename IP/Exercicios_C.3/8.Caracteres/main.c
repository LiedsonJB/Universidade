#include <stdio.h>
#include <stdlib.h>

int main() {
	
	char car;
	
	printf("Entre com caracteres: ");
	
	while((car = getchar()) !='\n'){
		if(car>='a' && car<='z'){
			car=car-('a'-'A');
		//	car=car-32; 
		}
		
		printf("%c", car);
	}

	//printf("\n\n%d, %d", 'A', 'a');
	return 0;
}