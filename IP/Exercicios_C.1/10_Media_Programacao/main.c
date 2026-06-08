#include <stdio.h>
//Este programa mostra a classificação final de um aluno de Programação II

int main() {
	
	float n[3];
    int media;
    
	for(int a=0; a<3;a++){
		printf("Nota %d: ",a+1);
		scanf("%f", &n[a]);}
	
	
	media= (n[0]+n[1]+n[2])/3;
	
	printf("\n\nMedia: %d", media);
	return 0;
}