#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

void guardaMuestras( float seno[] ){
	FILE *Ap;
	register int n;
	
	Ap = fopen("seno.dat", "w");
	if( Ap == NULL){
		perror("Error al abrir el archivo");
		exit(EXIT_FAILURE);
	}
	
	for(n = 0; n < N; n++){
		fprintf(Ap, "%f \n", seno[n] );
	}
	fclose(Ap);
}

