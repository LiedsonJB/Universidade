#include <stdio.h>
#include <stdlib.h>


int main() {
	
	float A= 80000, B= 200000, a=0, b=0;
	int cont= 0;
while(A<=B);{
  b=B + (B* 0.015);	
  a=A + (A* 0.03);		
  cont ++;
}

	printf("\n\nSao %d anos para ultrapassagem!\nPop. A: %f\nPop. B: %.1f", cont, A, B);
	
	return 0;
}