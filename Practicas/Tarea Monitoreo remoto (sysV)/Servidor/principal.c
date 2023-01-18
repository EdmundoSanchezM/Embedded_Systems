/** @brief: Este archivo es el principal, es donde se asigna el valor
	    de la variable arreglo y se crean los hilos
*   @Author: Sanchez Mendez Edmundo Josue
*   @Date: 10 de octubre de 2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <syslog.h>
#include "hilos.h"
#include "servidor.h"
#include "procesos.h"
#include "signal.h"
#include "demonio.h"

int sockfd, leer;
pthread_t tid;
extern char tiempo[10], latitude[11], a_lat, longitude[12], a_long;

int main(int argc, char **argv)
{
   	int cliente_sockfd;
   	pid_t pid;
   	leer = 1;
	iniDemonio();
	Initsignals();
	sockfd = initServidor();
	pthread_create( &tid,  NULL, hiloLeerArchivo,  NULL);
 	for(;EVER;){
	   	syslog(LOG_INFO,"En espera de peticiones de conexión ...\n");
	   	if( (cliente_sockfd = accept(sockfd, NULL, NULL)) < 0 )
		{
			perror("Ocurrio algun problema al atender a un cliente");
			exit(1);
	   	}
	   	
	   	pid = fork();
	   	if( !pid ){	//Proceso hijo atiende al cliente
	   		atiendeCliente( cliente_sockfd );
	   	}
   	
 	}
   	syslog(LOG_INFO,"Concluimos la ejecución de la aplicacion Servidor \n");

   	close (sockfd);

	return 0;
}
