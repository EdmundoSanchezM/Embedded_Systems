/** @brief: Este archivo contiene el manejo de los procesos,
*           tanto para los hijos como para los padres
*   @Author: Sanchez Mendez Edmundo Josue
*   @Date: 13 septiembre de 2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "algoritmos.h"
#include "defs.h"

void procesoPadre( ){
	int estado;
	char aux;
	pid_t pid;
	register int np;
	for(np = 0; np < NUM_PROC; np++){
		pid = wait(&estado);
		aux = (estado>>8);
		printf("Proceso hijo con pid: %d y retorno %d terminado\n", pid, aux);
	}
}

void procesoHijo( int np ){
	int resultado;
	printf("Proceso hijo: %d con pid: %d \n", np,getpid());
	if(np == 0){
		resultado = promedio();
		printf("Promedio de los elementos del arreglo: %d\n", resultado);
	}else if(np == 1){
		resultado = mayor();
		printf("Numero mayor en el arreglo: %d\n", resultado);
	}else if(np == 2){
		resultado = menor();
		printf("Numero menor en el arreglo: %d\n", resultado);
	}else if(np == 3){
		resultado = pares();
		printf("Numeros pares en el arreglo: %d\n", resultado);
	}	
	exit(resultado);
}
