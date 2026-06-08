#include <stdio.h>
#include<math.h>


int main() {
	
	float x, result;
	
	
		printf("Entre com o'x': ");
		scanf("%f", &x);
	
	if(x>0){
		result=(1/x) * exp(x);
		printf("\n\nResultado= %.3f\n\n", result);
	}
	else{
		result= exp(fabs(x));
		printf("\n\nResultado= %.3f\n\n", result);
	}
	
	
	return 0;
}