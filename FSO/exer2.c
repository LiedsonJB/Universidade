#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<sys/wait.h>

int main(){
	int id, i;

	for(i=0;i<3;i++){
		id = fork();

		if(id == 0){
			printf("\nPID Filho: %d\n", getpid());
			exit(0);
		}
	}

	for(i=0;i<3;i++){
		wait(NULL);
	}
	printf("\nPai terminando\n");
	return 0;		
}
	

