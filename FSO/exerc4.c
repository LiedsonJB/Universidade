#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

	int id;
       	
	id = fork();

	if(id==0){
		printf("\nPID do filho: %d\n", getpid());
		sleep(3);
	}else if(id > 0){
		id = fork();

		if(id == 0){
			printf("\nPID do filho 2: %d\n", getpid());
			sleep(5);
		}else{
			int pidRetorno = wait(NULL);
			printf("\nPID do filho que terminou: %d\n", pidRetorno);
			wait(NULL);
		}
	}
	return 0;
}

