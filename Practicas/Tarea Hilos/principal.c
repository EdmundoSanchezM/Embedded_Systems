/** @brief: Este archivo es el principal, es donde se asigna el valor
	    de la variable arreglo y se crean los hilos
*   @Author: Sanchez Mendez Edmundo Josue
*   @Date: 20 septiembre de 2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "hilos.h"
#include "defs.h"

int arreglo [] = {23, -67, 56, -12, 44, 77, -22, 78};
int main(){
	int *resultado, nhs[NUM_HILOS];
	register int nh;
	pthread_t tids[NUM_HILOS];
	
	printf("Probando hilos...\n");

	for( nh=0; nh < NUM_HILOS; nh++){
		nhs[nh] = nh;
		pthread_create( &tids[nh],  NULL, funHilo,  (void *)&nhs[nh] );
	}
	
	for( nh=0; nh < NUM_HILOS; nh++){
		pthread_join( tids[nh], (void **)&resultado );
		printf("El resultado del hilo: %d es: %d \n", nh, *resultado);
		free( resultado );
	}

	return 0;
}
