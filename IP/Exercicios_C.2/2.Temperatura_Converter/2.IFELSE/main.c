#include <stdio.h>
#include <stdlib.h>


int main() {
	
	float C, F;
	char op;
	
	printf("Conversoes:\nC-Celsius TO Fahrenheit\nF-Fahrenheit TO Celsius");
	printf("\n\nSua Opcao: ");
	scanf("%c", &op);
	fflush(stdin);
	
	if(op=='C'|| op=='c'){
	printf("Temperatura em Celsius: ");
	scanf("%f", &C);
	printf("Fahrenheit: %.2f\n\n",(C * (9/5)) + 32);
	}
	
	else if(op=='F' || op=='f'){
	printf("Temperatura em Fahrenheit: ");
	scanf("%f", &F);
	printf("\nCelsius: %.2f\n\n", (F - 32) * (5/9)  );
	}
	
	else{
		printf("\n\nErro- Opcao Invalida!!!\n\n");
	}
	
	
	return 0;
}