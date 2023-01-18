/** @brief: Este archivo es el principal, es donde se asigna el valor
	    de la variable arreglo y se crean los procesos
*   @Author: Sanchez Mendez Edmundo Josue
*   @Date: 13 septiembre de 2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "procesos.h"
#include "defs.h"

int arreglo [] = {23, -67, 56, -12, 44, 77, -22, 78};
int main(){
	pid_t pid;
	register int np;
	printf("Tarea 2...\n");
	
	for(np = 0; np < NUM_PROC; np++){
		pid = fork();
		if( pid == -1){
			perror("Error al crear proceso hijos\n");
			exit(EXIT_FAILURE);
		}
		if( !pid ){
			procesoHijo( np );
			
		}
	}
	procesoPadre();

	return 0;
}
