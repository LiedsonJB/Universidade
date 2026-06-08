#include <stdio.h>
#include <stdlib.h>


int maior_menor(int q){ // void pois nao retorna nada, so dá um print
	int i, m, M, n;
	printf("Entre com os %d numeros:\n", q);
	scanf("%d", &n);
	m=n;
	M=n;

	while(i<q-1){
	scanf("%d", &n);
	M = M < n ? n : M;
	m = m > n ? n : m;
	i++;
}	
printf("\nO maior: %d\nO menor: %d", M, m);
}


int main() {
	int quant, num;
	printf("Quantos numeros pretende introduzir?: ");
	scanf("%d", &quant);
	
	maior_menor(quant);

	
	return 0;
}