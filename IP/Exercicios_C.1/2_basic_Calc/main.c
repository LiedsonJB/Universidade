#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//este programa recebe dois numeros e faz a adição, a ubtração, as multiplicação e a divisão

int main() { setlocale(LC_ALL, "Portuguese");
	
	float num1, num2;
	float som, subt, mult, divi;
	
	printf("Insira primeiro numero: ");
	scanf("%f", &num1);
	printf("Insira segundo numero: ");
	scanf("%f", &num2);
	
	
	som= num1+num2;
	subt= num1-num2;
	mult=num1*num2;
	divi= num1/num2;
	
	printf("\n\nSoma=%0.3f", som);
	printf("\nSubtracao=%0.3f", subt);
	printf("\nMultiplicacao=%0.3f", mult);
	printf("\nDivisao=%0.3f", divi);
	
	return 0;
}