#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

	pid_t id = fork();

	if(id == 0)
		printf("PID Filho: %d", getpid());
	else{
		printf("PID Pai: %d", getppid());
		wait(NULL);
	}

	return 0;
}
