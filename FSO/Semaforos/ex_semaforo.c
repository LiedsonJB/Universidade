#include < s tdio . h>
#include <pthread . h>
#include <semaphore . h>
#include <unis td . h>
sem_t sem;
void* thread_func ( void*arg ) {
	sem_wait(&sem);
	printf( ” Thread␣%d␣entrou␣na␣região␣ crítica.\n” , (int)arg);
	sleep ( 2 ) ;
	printf( ” Thread␣%␣d␣saiu␣da␣região␣ crítica.\n” , (int)arg);
	sem_post(&sem);
	return NULL ;
}

int main ( ) {
	pthread_t threads [ 3 ] ;

	sem_init (&sem, 0 , 1 ) ;
	for ( int i = 0; i < 3; i ++) {
		pthread_create(&threads[i] , NULL, thread_func , ( void*) i ) ;
	}
	for ( int i = 0; i < 3; i ++) {
		pthread_join ( threads [ i ] , NULL ) ;
	}

	sem_destroy(&sem ) ;
	return 0;
}
