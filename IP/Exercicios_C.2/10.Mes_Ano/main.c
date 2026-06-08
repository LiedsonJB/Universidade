#include <stdio.h>
#include <stdlib.h>


int main() {
	
	int ano;
	int mes;
	
	printf("Entre com o Mes: ");
	scanf("%d", &mes);
	printf("Entre com o Ano: ");
	scanf("%d", &ano);
	
	/*if(ano%4==0 && ano%100!=0)
		printf("\nAno Bissesto!!");
		else printf("\nAno nao Bissesto!");*/
	
	switch(mes){
		
		case 1:
		printf("\nJaneiro: 31 dias!");
		break;
		
		case 2:
		if(ano%4==0 && ano%100!=0)
		printf("\nFevereiro (b): 29 dias!");
		else printf("\nFevereio: 28 dias!");
		break;
		
		case 3:
		printf("\nMarco: 31 dias!");
		break;
		case 4:
		printf("\nAbril: 30 dias!");
		break;
		case 5:
		printf("\nMaio: 31 dias!");
		break;
		case 6:
		printf("\nJunho: 30 dias!");
		break;
		case 7:
		printf("\nJulho: 31 dias!");
		break;
		case 8:
		printf("\nAgosto: 31 dias!");
		break;
		case 9:
		printf("\nSetembro: 30 dias!");
		break;
		case 10:
		printf("\nOutubro 31 dias!");
		break;
		case 11:
		printf("\nNovembro: 30 dias!");
		break;
		case 12:
		printf("\nDesembro: 31 dias!");
		break;
		
		default:
		printf("\nMes inexistente, tente verificar a ortografia!!! ");
		break;
	}
	
	
	return 0;
}