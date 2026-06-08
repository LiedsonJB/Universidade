#include <stdio.h>
#include <stdlib.h>

int main() {
	int num, soma= 0, cont=0, m=0, M=0;
	
	printf("Digite uma sequencia de numeros inteiros (termine com 0): \n");
	scanf("%d", &num);
	m=num;
	soma+=num;
	
while(num!=0){
	scanf("%d", &num);
	soma+=num;
	cont++;

	if(num>M){
		M=num;
	}else if(num<m && num!=0){
		m=num;
	}else{
		continue;
	}
} 
	printf("\n\nMedia= %d", soma/cont);
	printf("\nO maximo e: %d", M);
	printf("\nO minimo e: %d", m);
	
	return 0;
}