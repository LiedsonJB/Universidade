#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t id = fork();
        printf("PID: %d\n", getpid());
        getchar();
        
        return 0;
}       

