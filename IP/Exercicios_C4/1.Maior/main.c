#include <stdio.h>
#include <stdlib.h>

int maior(int x,int y, int z)

{int m;
	if(x>y && x>z )
	m=x;
	else if(y>y && y>z )
	m=y;
	else
	m=z;
	
	return m;
}


int main() {
	
	int a, b, c;
	printf("A: ");
	scanf("%d", &a);
	printf("B: ");
	scanf("%d", &b);
	printf("C: ");
	scanf("%d", &c);

	printf("\nO maior numero: %d", maior(a,b,c));
	
	return 0;
}