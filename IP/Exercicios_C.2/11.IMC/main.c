#include <stdio.h>
#include <stdlib.h>



int main() {
	
	float peso, altura,IMC;	
	
	printf("Insira seu peso: ");
	scanf("%f", &peso);
	printf("Insira sua altura: ");
	scanf("%f", &altura);
	
	
	IMC= peso/(pow(altura,2));
	printf("Seu IMC:%.2f", IMC);
	
	
	if(IMC<18.5){
	printf("\n\nEstas Magro!\n\n");}
	
	if(IMC>18.5 && IMC <25.0){
	printf("\n\nEstas Saudavel!\n\n");}
	
	if(IMC>25.0 && IMC <30.0){
	printf("\n\nEstas Forte!\n\n");}
	
	if(IMC>30.0){
	printf("\n\nEstas Obeso!\n\n");}
	
	
	return 0;
}