#include <stdio.h>
#include <stdlib.h>



int main() {
	
	
	int ano;
	int mes;
	
	printf("Entre com o Mes: ");
	scanf("%d", &mes);
	printf("Entre com o Ano: ");
	scanf("%d", &ano);
	
	//Verificar se ano é bissesto
	if(ano%4==0 && ano%100!=0){
	printf("\nAno Bissesto!!");	}
	else{
	printf("\nAno comum!");	
	} 
	
	
	//Verificação dos meses
		if(mes==1)
		printf("\nJaneiro: 31 dias!");
	
	//Particularidade do mes de Fevereiro
		else if(mes==2){
		if(ano%4==0 && ano%100!=0)
		printf("\nFevereiro (b): 29 dias!");
		else printf("\nFevereio: 28 dias!");
		}
		
		else if(mes==3){
		printf("\nMarco: 31 dias!");
		}
		
		else if(mes==4){
		printf("\nAbril: 30 dias!");	
		}
		
		else if(mes==5){
		printf("\nMaio: 31 dias!");
		}
		
		else if(mes==6){
		printf("\nJunho: 30 dias!");	
		}
		
		else if(mes==7){
		printf("\nJulho: 31 dias!");	
		}
		
		else if(mes==8){
		printf("\nAgosto: 31 dias!");	
		}
		
		else if(mes==9){
		printf("\nSetembro: 30 dias!");	
		}
		
		else if(mes==10){
		printf("\nOutubro 31 dias!");
		}
		
		else if(mes==11){
		printf("\nNovembro: 30 dias!");	
		}
		
		else if(mes==12){
		printf("\nDesembro: 31 dias!");	
		}
		
		else{
		printf("\nMes inexistente, tente averiguar o dado inserido!!! ");	
		}
		
	return 0;
}