#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include"defs.h"
#include"archivos.h"

void * hiloLeerArchivo( void *arg ){
	char datos[ TAM_BUFFER ];
	leerArchivo( datos, "nmea.txt" );
	manejarCadenas(datos);
	pthread_exit( (void*) 0 );
}
