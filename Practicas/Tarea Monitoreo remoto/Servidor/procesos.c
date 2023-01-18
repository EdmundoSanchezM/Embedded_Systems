#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <netinet/in.h>
#include "defs.h"
#include "archivos.h"

char tiempo[10], latitude[11], a_lat, longitude[12], a_long;

void atiendeCliente(int cliente_sockfd){
	char mensaje[TAM_BUFFER];
	sprintf(mensaje,"time:%s latitude:%s N/S:%c longitude:%s E/W:%c",tiempo, latitude, a_lat, longitude, a_long);
	if( write (cliente_sockfd, mensaje, TAM_BUFFER) < 0 )
	{
		perror("Ocurrio un problema en el envio de un mensaje al cliente");
		exit(1);
	}
	
	close (cliente_sockfd);
	exit(0);

}
