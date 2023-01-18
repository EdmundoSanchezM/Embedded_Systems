#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <syslog.h>

extern int sockfd;
extern pthread_t tid;
int leer;
void ISRsw( int sig ){
	int estado;
	pid_t pid;
	syslog(LOG_INFO,"Senal recibida : %d \n", sig);
	if( sig == SIGCHLD ){
		pid = wait(&estado);
		syslog(LOG_INFO,"Proceso con pid: %d terminado y retorno: %d\n", pid, estado>>8);
	}else if( sig == SIGINT ){
		leer = 0;
		syslog(LOG_INFO,"\nSe recibio la señal SIGINT en el servidor\n");
		syslog(LOG_INFO,"Concluimos la ejecución de la aplicacion Servidor \n");
		pthread_join( tid, NULL );
		close( sockfd );
		exit( 0 );
	}
}

void Initsignals(){
   	if( signal( SIGCHLD, ISRsw ) == SIG_ERR ){
   		perror("Error en la senial SIGCHLD \n");
   		exit(EXIT_FAILURE);
   	}
   	if( signal( SIGINT, ISRsw ) == SIG_ERR ){
   		perror("Error en la senial SIGINT \n");
   		exit(EXIT_FAILURE);
   	}
}
