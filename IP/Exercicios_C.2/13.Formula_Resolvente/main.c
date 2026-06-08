#include <stdio.h>
#include<math.h>

int main() {
	
	float a, b, c;
	float r1, r2, D;
	
	printf("Insira termo 'a': ");
	scanf("%f", &a);
	printf("Insira termo 'b': ");
	scanf("%f", &b);
	printf("Insira termo 'c': ");
	scanf("%f", &c);
	
	D= b*b-4*a*c; //Discriminante
	
	
	if(D>0){
	printf("\nExistem duas raizes:\n ");
	r1= (-b + sqrt(D))/(2*a); //Primeira raiz
	r2= (-b - sqrt(D))/(2*a);//Segunda raiz
	
	printf("\nPrimeira raiz=%0.2f\n", r1);
	printf("\nSegunda raiz=%0.2f\n", r2);
	}
	else if(D==0){
	printf("\nExiste uma raiz:\n ");
	r1= (-b + sqrt(D))/(2*a); //Primeira raiz
	printf("\nA raiz=%0.2f\n", r1);
	}
	else {
	printf("\nO discriminante e negativo!\n ");
	}
	
	
	return 0;
}