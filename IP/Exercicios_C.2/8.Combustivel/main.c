#include <stdio.h>
#include <stdlib.h>



int main() {
	
	int comb, preco;
	
	printf("Quantidade de combustivel: ");
	scanf("%d", &comb);
	 
	if(comb>40){
		preco= (comb*160)-0.05*(comb*160);
		printf("Fizeste um abastecimento maior que 40L.\nPagas %d$.\n\n", preco);
	}
	 else{
	 	preco=comb*160;
	 	printf("Fizeste um abastecimento de %d litro(s).\nPagas %d $.\n\n", comb, preco);
	 	
	 }
	
	
	return 0;
}