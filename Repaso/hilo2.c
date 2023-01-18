#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_HILOS 4

void * funHilo( void *arg );

int num1 = 45, num2 = 5;

int main( )
{
	int *resultado, nhs[NUM_HILOS];
	register int nh;
	pthread_t tids[NUM_HILOS];
	
	printf("Probando hilos...\n");

	for( nh=0; nh < NUM_HILOS; nh++){
		nhs[nh] = nh;
		//nhs[0] = 0;
		//nhs[1] = 1;
		//nhs[2] = 2;
		//nhs[3] = 3;
		pthread_create( &tids[nh],  NULL, funHilo,  (void *)&nhs[nh] );
	}
	
	for( nh=0; nh < NUM_HILOS; nh++){
		pthread_join( tids[nh], (void **)&resultado );
		printf("El resultado del hilo: %d es: %d \n", nh, *resultado);
		free( resultado );
	}

	return 0;
}

void * funHilo( void *arg )
{
	int nh = *(int *)arg;
	int *res = (int *)malloc( sizeof(int) );
	
	if( nh == 0 )
		*res = num1 + num2;
	else if( nh == 1 )
		*res = num1 - num2;
	else if( nh == 2 )
		*res = num1 * num2;
	else if( nh == 3 )
		*res = num1 / num2;

	pthread_exit( (void *)res );
}
