#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int n1, n2, n3;
	
	printf("Insira primreiro: ");
	scanf("%d", &n1);
	printf("Insira segundo: ");
	scanf("%d", &n2);
	printf("Insira terceiro: ");
	scanf("%d", &n3);
	
	if(n1>n2 && n1>n3)
	printf("\n%d é maior!\n\n", n1);
	if(n2>n1 && n2>n3)
	printf("\n%d é maior!\n\n", n2);
	if(n3>n1 && n3>n2)
	printf("\n%d é maior!\n\n", n3);
	
	
	system("pause");
	
	return 0;
}