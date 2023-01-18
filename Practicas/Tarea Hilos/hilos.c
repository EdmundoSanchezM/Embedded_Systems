/** @brief: Este archivo contiene el manejo de los hilos
*   @Author: Sanchez Mendez Edmundo Josue
*   @Date: 20 septiembre de 2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "algoritmos.h"

void * funHilo( void *arg ){
	int nh = *(int *)arg;
	int *res = (int *)malloc( sizeof(int) );
	if(nh == 0){
		*res = promedio();
		printf("Promedio de los elementos del arreglo: %d\n", *res);
	}else if(nh == 1){
		*res = mayor();
		printf("Numero mayor en el arreglo: %d\n", *res);
	}else if(nh == 2){
		*res = menor();
		printf("Numero menor en el arreglo: %d\n", *res);
	}else if(nh == 3){
		*res = pares();
		printf("Numeros pares en el arreglo: %d\n", *res);
	}
	pthread_exit( (void *)res );
}
