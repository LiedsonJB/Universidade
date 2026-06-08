#include <stdio.h>
#include <stdlib.h>

void tempo(s){
	int m, h;
	m = s / 60;
	s = s % 60;
	h = m / 60;
	m = m % 60;	
	printf("\n%d:%d:%d",h, m, s );	
}

int main() {
	int seg;
	printf("Total de segundos: ");
	scanf("%d", &seg);
	
	tempo(seg);
	
	return 0;
}