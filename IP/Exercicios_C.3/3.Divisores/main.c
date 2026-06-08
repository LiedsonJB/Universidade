#include <stdio.h>

int main() {
	
	int num, i=0;
	
printf("Insira numero: ");
scanf("%d", &num);	

while (i<num){
i++;
		if(num%i==0){
			printf("%d, ", i);
			}
		else{
		continue;
		}
		
	}
printf(" sao divisores de %d.", num);
	return 0;
}