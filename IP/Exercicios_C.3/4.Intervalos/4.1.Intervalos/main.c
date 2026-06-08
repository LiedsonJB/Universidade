#include <stdio.h>
#include <stdlib.h>


int main() {
	
	int quant, i;
	
	printf("Insira a quantidade de numeros a ler:");
	scanf("%d", &quant);
	
	int num[quant], intervalo[5]={0,0,0,0,0,0};
	
	
	for(i=0;i<quant; i++){
		
		//Ler os numeros
		printf("Numero %d: ", i+1 );
		scanf("%d", &num[i]);
		
		//Inserir em intervalos
		if(num[i]<=0){
			intervalo[0]++;}
			
		else if(num[i]>0 && num[i]<=25){
			intervalo[1]++;}
			
		else if(num[i]>25 && num[i]<=50){	
			intervalo[2]++;}
			
		else if(num[i]>50 && num[i]<=75){	
			intervalo[3]++;}
			
		else if(num[i]>75 && num[i]<=100){	
			intervalo[4]++;}
			
		else if (num[i]>100){	
			intervalo[5]++;}	
		
	}
	
	//Mostrar os resultados
	
	printf("\nIntervalos:\n");
	
	printf("\nIntervalo ]-oo;0]: %d numeros;", intervalo[0]);
	printf("\nIntervalo ]0;25]: %d numeros;", intervalo[1]);
	printf("\nIntervalo ]25;50]: %d numeros;", intervalo[2]);
	printf("\nIntervalo ]50;75]: %d numeros;", intervalo[3]);
	printf("\nIntervalo ]75;100]: %d numeros;", intervalo[4]);
	printf("\nIntervalo ]100;+oo[: %d numeros;", intervalo[5]);
	

	return 0;
}