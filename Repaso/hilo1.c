#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * suma( void *arg );
void * resta( void *arg );

int num1 = 45, num2 = 5;

int main( )
{
	int *res_suma, *res_resta;
	pthread_t tid_suma, tid_resta;

	printf("Probando hilos...\n");

	pthread_create( &tid_suma,  NULL, suma,  NULL);
	pthread_create( &tid_resta, NULL, resta, NULL);

	pthread_join( tid_suma,  (void **)&res_suma  );
	pthread_join( tid_resta, (void **)&res_resta );

	printf("La suma es: %d \n", *res_suma);
	printf("La resta es: %d \n", *res_resta);

	free( res_suma );
	return 0;
}

void * suma( void *arg )
{
	int *s = malloc( sizeof(int) );

	if( s == NULL )
	{
		perror("Error al asignar memoria");
		exit(EXIT_FAILURE);
	}

	*s = num1 + num2;

	pthread_exit( (void *)s );
}

void * resta( void *arg )
{
	static int r;

	r = num1 - num2;

	pthread_exit( (void *)&r );
}
