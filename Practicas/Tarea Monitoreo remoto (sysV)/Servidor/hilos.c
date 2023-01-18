#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <syslog.h>
#include "defs.h"
#include "archivos.h"
#include "serial.h"

extern int leer;

void * hiloLeerArchivo( void *arg ){
	char datos[ TAM_BUFFER ];
	unsigned char dato;
	int fd_serie;
	register int indice;
	fd_serie = config_serial( "/dev/ttyS0", B9600 );
	syslog(LOG_INFO,"serial abierto con descriptor: %d\n", fd_serie);
	while(leer){
		indice = 0;
		dato = 0;
		while( dato != '\n' ){
			read( fd_serie, &dato, 1 );
			datos[indice] = dato;
			indice++;
		}
		datos[ indice ] = '\0';
		if( datos[3] == 'G' && datos[4] == 'G' && datos[5] == 'A'){
			manejarCadenas(datos);
		}
	}
	close( fd_serie );
	pthread_exit( (void*) 0 );
}
