#include <stdio.h>
#include <stdlib.h>

//Este programa converte a temperatura em graus celsius para fahrenheit

int main() {
	
float cels, fahr;

printf("Temperatura em G.Celsius: ");
scanf("%f", &cels);

fahr= (1.8*cels)+32;

printf("\nEssa temperatura em Fahrenheit: %.2f", fahr);


	return 0;
}