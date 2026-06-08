#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int x, y;
	
	printf("Coordenada x: ");
	scanf("%d", &x);
	printf("Coordenada y: ");
	scanf("%d", &y);
	//Quadrantes
	if(x>0 && y>0)
	printf("\n\nCoordenada (%d;%d)- Primero Quadrante.\n\n", x, y);
	
	else if(x<0 && y>0)
	printf("\n\nCoordenada (%d;%d)- Segundo Quadrante.\n\n", x, y);
	
	else if(x<0 && y<0)
	printf("\n\nCoordenada (%d;%d)- Terceiro Quadrante.\n\n", x, y);
	
	else if(x<0 && y>0)
	printf("\n\nCoordenada (%d;%d)- Quarto Quadrante.\n\n", x, y);
	
	//So no eixo X
	else if(x<0 && y==0)
	printf("\n\nCoordenada (%d;%d)- Encontra-se no Eixo X (negativo).\n\n", x, y);
	else if(x>0 && y==0)
	printf("\n\nCoordenada (%d;%d)- Encontra-se no Eixo X (positivo).\n\n", x, y);
	
	//So no eixo Y
	else if(x==0 && y>0)
	printf("\n\nCoordenada (%d;%d)- Encontra-se no Eixo Y (positivo).\n\n", x, y);
	else if(x==0 && y<0)
	printf("\n\nCoordenada (%d;%d)- Encontra-se no Eixo Y (negativo).\n\n", x, y);
	
	else printf("\n\nCoordenada (%d;%d)- Encontra-se na Origem.\n\n", x, y);
	
	return 0;
}