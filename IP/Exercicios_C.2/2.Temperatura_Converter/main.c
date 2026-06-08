#include <stdio.h>
#include<locale.h>

int main() { setlocale(LC_ALL, "Portuguese");
	
	int op;
	float C, F;
	
	printf("Opcoes disponiveis: \n1.Graus Celsius TO Fahrenheit\n2.Fahrenheit TO Celsius \n");
	printf("Tipo de conversão: ");
	scanf("%d", &op);
	
	switch(op){
		case 1:
		printf("\nDigite o valor em Celsius: ");
		scanf("%f", &C);
		printf("Conversao: %.2f",(C * (9/5)) + 32);
		break;
		
		case 2:
		printf("\nDigite o valor em Fahrenheit: ");
		scanf("%f", &F);
		printf("\nConversao: %.2f", (F - 32) * (5/9)  );
		break;
		
		default:
			printf("\n\nNO FOUND");
			break;
	}
	
	
	
	
	
	
	return 0;
}