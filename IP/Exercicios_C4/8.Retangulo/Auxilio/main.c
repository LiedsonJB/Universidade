#include <stdio.h>
#include <stdlib.h>


int main() {
	int n= 10000;
	int i=0;
	
	while(i<5){
		if(n%3 == 0){
			printf("%d", n);
			i++;}
		n += 1;
	}
	
	
	return 0;
}