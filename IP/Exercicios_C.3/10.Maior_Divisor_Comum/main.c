#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	int a, b, resto, i;
	
	printf(" ")
	
	do{
		
		resto= a%b;
		a=b;
		b=resto;
		
	}while (b!=0)
	
	printf("\nMDC= %d", a);
	
	
	
/*	do{
	printf("Primeiro numero: ");
	scanf("%d",& a);
	printf("Segundo numero: ");
	scanf("%d", &b);
	
	if(a>b){
		i=b;
		while(i>0){
			if(a%i==0 && b%i==0 ){
				printf("\nO maximo divisor comum entre %d e %d = %d\n\n", a, b, i);
				break;
			}else{
				i--;
			}
		}
	}else if(a<b){
		i=a;
		while(i>0){
			if(a%i==0 && b%i==0 ){
				printf("\nO maximo divisor comum entre %d e %d = %d\n\n", a, b, i);
				break;
			}else{
				i--;
			}
		}
	}else{
		
	printf("\nO maximo divisor comum entre %d e %d = %d\n\n", a, b, a);
		
	}
			
	}while(b!=0);
	
	
	
	
	
	
	
	
	
	
	
	
	/*do{
	printf("Primeiro numero: ");
	scanf("%d",& a);
	printf("Segundo numero: ");
	scanf("%d", &b);
		
	resto=(fabs(b))*a;
	a=b;
	b=resto;
	
	printf("\na=%d\nb=%d\nresto=%d\n\n", a, b, resto);	
		
	}while(b!=0);*/
	
	
	
	
	return 0;
}