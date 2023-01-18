#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#define EVER 1

void ISRsw( int sig );

int main(){
	if( signal(SIGINT, ISRsw) == SIG_ERR){//Error al colocar el manejador
		perror("Error al asignar manejador\n");
		exit(EXIT_FAILURE);
	}

	if( signal(SIGTERM, ISRsw) == SIG_ERR){//Error al colocar el manejador
		perror("Error al asignar manejador\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Proceso con pid %d en ejecucion\n", getpid());

	for(;EVER;){
		pause();
		//sleep(2);
	}
	return 0;
}

void ISRsw( int sig ){
	printf("Señal %d recibida\n", sig);
	if( sig == SIGINT )
		printf("No quiero terminar....\n");
	else if( sig == SIGTERM )
		printf("Que no entiendes que no quiero terminar....\n");
}

