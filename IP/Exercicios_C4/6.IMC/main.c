#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float imc(float peso, float altura){
	float IMC = peso / (altura * altura);
	return IMC;
	}
		
void categoria(int IMC){
	
	if(IMC < 19){
		printf("\n-------- Cat. Magro!", IMC);}
	else if(IMC >= 12 && IMC <= 25 ){
		printf("\n-------- Cat. Normal!", IMC);}
	else if(IMC > 25 && IMC <= 30 ){
		printf("\n-------- Cat. Excesso peso!", IMC);}
	else if(IMC > 30 && IMC <= 40 ){
		printf("\n-------- Cat. Obeso I!", IMC);}
	else{
		printf("\n-------- Cat. Obeso II!", IMC);}	
}

float peso_minimo(float altura){
	return 19 * (altura * altura);
}

float peso_maximo(float altura){
	return 25 * (altura * altura);
}



int main() {
	float alt, peso;
	
	printf("Sua altura (metros): ");
	scanf("%f", &alt);
	printf("Seu peso (kg): ");
	scanf("%f", &peso);
	
	printf("\nIMC: %0.1f", imc(peso,alt));	
	categoria(imc(peso, alt));
	printf("\nPMI = %0.1f", peso_minimo(alt));
	printf("\nPMI = %0.1f", peso_maximo(alt));
	
	return 0;
}