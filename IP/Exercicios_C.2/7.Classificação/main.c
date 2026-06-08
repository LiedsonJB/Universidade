#include <stdio.h>
#include <stdlib.h>


int main() {
	
	float pont;
	
	printf("Insira a pontuacao: ");
	scanf("%f", &pont);
	
	if(pont>=19 && pont<=20)
	printf("\n\nSobresaliente!\n\n");
	else if(pont>=16 && pont<19)
	printf("\n\nNotable!\n\n");
	else if(pont>=13 && pont<16)
	printf("\n\nBien!\n\n");
	else if(pont>=10 && pont<16)
	printf("\n\nSuficiente!\n\n");
	else if(pont<10 && pont>=0)
	printf("\n\nInsuficiente!\n\n");
	
	else printf("\n\nErro-pontuacao invalida!!!\n\n");
	
	
	
	
	return 0;
}