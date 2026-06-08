#include <stdio.h>
#include <stdlib.h>

/*Este programa mostra o valor total que que 
o Lucas gastará com carne e cerveja no seu aniversário*/

int main() {
	
	int pessoas, carne, cerveja, custo;
	
	printf("Quantas pessoas vao na festa?: ");
	scanf("%d", &pessoas);
	
	carne=(400*500)/1000;
	cerveja=120*5;
	custo= (carne+cerveja)*pessoas;
	
	printf("\nO lucas gastara o total de: %d$ ", custo);
	printf("\nAs carnes custarao: %d$", carne*pessoas);
	printf("\nAs cervejas custarao: %d$", cerveja*pessoas);
	
	return 0;
}