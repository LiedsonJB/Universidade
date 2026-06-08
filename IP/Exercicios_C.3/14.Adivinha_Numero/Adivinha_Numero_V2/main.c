#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() { srand(time(NULL));
	
	int op, num, al, tentativas=0;
	char op2, op3;
	
	
	do{
	
	system("color 3");
	printf("-----Bem Vindo ao Game-----\n------ADIVINHA NUMERO-----");
	
	printf("\n\n\nSelecione o nivel de dificuldade:");
	printf("\n1. Facil (1 a 10)| ");
	printf("\n2. Dificil (1 a 100)| ");
	printf("\n3. Extremo (1 a 1000)| ");
	printf("\n\nSua opcao aqui->  ");
	scanf("%d", &op);
	
	
	//----------------------------------------------------------------------
	
		switch (op){
		
		case 1: 
		al=rand()%3;
		system("cls");
		system("color D");
		printf("\nNIVEL FACIL INICIADO\n");	
		
		do{
		printf("\nAcerte o numero: ");	
		scanf("%d", &num);	
		tentativas ++;
		
		if(num==al){
			system("cls");
			system("color 2");
			printf("\nACERTOU!!!");
			printf("\nNumero: %d", num);
		printf("\nTentativas: %d", tentativas);
		printf("\n\nDeseja repetir o nivel? (s/qualquer carartere)\nR: ");
		fflush(stdin);
		scanf("%c", &op2);
		
		if(op2 == 's' || op2 == 'S'){
			system("cls");
			system("color D");
			al=rand()%3;
			tentativas=0;
			num=-1;
		}else{
			system("color B");
			tentativas=0;
			printf("Adeus!");
			break;}
		}
		else{
		printf("\nErrou! ");
		printf("\nNumero: %d", al);
		continue;
		}	
			
		}while(num!=al);
		
		break;
		
		
		//---------------------------------------------------------------------
		case 2:
		al=rand()%3;
		system("cls");
		system("color D");
		printf("\nNIVEL DIFICIL INICIADO\n");	
			
		do{
		printf("\nAcerte o numero: ");	
		scanf("%d", &num);	
		tentativas ++;
		
		if(num==al){
			system("cls");
			system("color 2");
			printf("\nACERTOU!!!");
			printf("\nNumero: %d", num);
		printf("\nTentativas: %d", tentativas);
		printf("\n\nDeseja repetir o nivel? (s/qualquer carartere)\nR: ");
		fflush(stdin);
		scanf("%c", &op2);
		
		if(op2 == 's' || op2 == 'S'){
			system("cls");
			system("color D");
			al=rand()%3;
			tentativas=0;
			num=-1;
		}else{
			system("color B");
			tentativas=0;
			printf("Adeus!");
			break;}
		}
		else{
		printf("\nErrou! ");
		printf("\nNumero: %d", al);
		continue;
		}	
			
		}while(num!=al);
		
		
		
		break;
		//---------------------------------------------------------------------
		
		case 3:
		al=rand()%3;
		system("cls");
		system("color D");
		printf("\nNIVEL EXTREMO INICIADO\n");	
			
		do{
		printf("\nAcerte o numero: ");	
		scanf("%d", &num);	
		tentativas ++;
		
		if(num==al){
			system("cls");
			system("color 2");
			printf("\nACERTOU!!!");
			printf("\nNumero: %d", num);
		printf("\nTentativas: %d", tentativas);
		printf("\n\nDeseja repetir o nivel? (s/qualquer carartere)\nR: ");
		fflush(stdin);
		scanf("%c", &op2);
		
		if(op2 == 's' || op2 == 'S'){
			system("cls");
			system("color D");
			al=rand()%3;
			tentativas=0;
			num=-1;
		}else{
			system("color B");
			tentativas=0;
			printf("Adeus!");
			break;}
		}
		else{
		printf("\nErrou! ");
		printf("\nNumero: %d", al);
		continue;
		}	
			
		}while(num!=al);
		
		
		break;
		
		//---------------------------------------------------------------------
		default:
		system("color c");
		printf("\n\n\n--------Opcao desconhecida!!!\n\n ");	
		break;	
		
	}
		
		fflush(stdin);
		system("cls");
		printf("Deseja escolher um outro Nivel?(s/caractere qualquer?\nR: ");
		scanf("%c", &op3);
			system("cls");
		
	}while(op3=='s'|| op3 == 'S');
	
	
	printf("\n\nAdeus!");
	
	
	
	return 0;
}