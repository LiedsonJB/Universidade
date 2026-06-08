#include <stdio.h>
#include <stdlib.h>

/*Este programa mostra o valor da multa paga
 pelo atraso no empréstimo de um livro na biblioteca do ISECMAR*/

int main() {
	
	int atraso, multa;
	
	printf("Dias de atraso: ");
	scanf("%d", &atraso);
	
	multa= atraso * 250;
	
	printf("\nAtrasaste %d dias, logo, deves %d$", atraso, multa);
	
	return 0;
}