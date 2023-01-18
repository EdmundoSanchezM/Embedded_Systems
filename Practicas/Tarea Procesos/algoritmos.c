/** @brief: Este archivo contiene todos los algoritmos usados para esta tarea.
*   @Author: Sanchez Mendez Edmundo Josue
*   @Date: 13 septiembre de 2021
*/
#include <stdio.h>
#include "defs.h"

extern int arreglo [];
float promedio( ){
	float prom = 0;
	register int i;
	for( i = 0; i < N; i++)
		prom += arreglo[i];
	prom = prom / N;
	
	return prom;
}

int mayor( ){
	int temp;
	register int i,j;
	for (i=1; i<N; i++)
        	for (j=0 ; j<N - 1; j++)
    			if (arreglo[j] > arreglo[j+1]){
	    			temp = arreglo[j];
	    			arreglo[j] = arreglo[j+1];
		            	arreglo[j+1] = temp;
    			}
        return arreglo[N-1];
}


int menor( ){
	int temp;
	register int i,j;
	for (i=1; i<N; i++)
        	for (j=0 ; j<N - 1; j++)
    			if (arreglo[j] > arreglo[j+1]){
    				temp = arreglo[j];
    				arreglo[j] = arreglo[j+1];
                    		arreglo[j+1] = temp;
    			}
        return arreglo[0];
}

int pares( ){
	int cont = 0;
	register int i;
	for( i = 0; i < N; i++)
		if( arreglo[i]%2 == 0)
			cont++;
			
	return cont;
}
