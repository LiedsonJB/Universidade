#include <stdio.h>
#include <stdlib.h>


int main() {
	
	int quant, num;
	int a=0, b=0, c=0, d=0, e=0, f=0;//intervalos
	
	printf("Informe a quantidade de numeros a ler: ");
	scanf("%d", &quant);
	
	
	for(int i=0;i<quant; i++){
		
		printf("Numero %d: ", i+1);
		scanf("%d", &num);
		
		//Verificação de intervalos
		if(num<=0){
		a++;}
		else if(num > 0 && num<=25){
		b++;}	
		else if(num>25 && num<=50){	
		c++;}
		else if(num>50 && num<=75){	
		d++;}
		else if(num>75 && num<=100){	
		e++;}	
		else if (num>100){	
		f++;}
	}
	
	//Output
	printf("\nIntervalos:");

	printf("\nIntervalo ]-oo;0]: %d numeros;", a);
	printf("\nIntervalo ]0;25]: %d numeros;", b);
	printf("\nIntervalo ]25;50]: %d numeros;", c);
	printf("\nIntervalo ]50;75]: %d numeros;", d);
	printf("\nIntervalo ]75;100]: %d numeros;", e);
	printf("\nIntervalo ]100;+oo[: %d numeros;", f);
	
	return 0;
}