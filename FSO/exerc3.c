#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<sys/wait.h>

int main(){
	int id;

	id = fork();

	if(id == 0){
		printf("\nPID Filho: %d\n", getpid());
		execl("/bin/date", "date", NULL);
		perror("ERROR");
	}

	else if(id > 0){
		wait(NULL);	
		printf("Processo PAI terminando...");
	}


	return 0;		
}
	

