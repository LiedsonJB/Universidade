#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t id = fork();

	if(id == 0){
		printf("filho -> pid: %d\nppid: %d\n", getpid(), getppid());
		exit(0);
	}else{
		printf("Pai -> pid: %d\n", getpid());
		wait(NULL);
		printf("Pai terminando...");
	}

	return 0;
}
