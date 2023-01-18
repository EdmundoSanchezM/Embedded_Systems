#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){

	int num1 = 45, num2=5;
	int suma, resta;
	int estado;
	pid_t pid;
	printf("Probando procesos...\n");
	
	pid = fork();
	if( pid == -1){
		perror("Error al crear proceso hijos\n");
		exit(EXIT_FAILURE);
	}
	if( !pid ){
		printf("Proceso hijo con pid: %d \n", getpid());
		suma = num1 + num2;
		printf("La suma es: %d \n", suma );
		exit(5);
	}else{
		sleep(15);
		resta = num1 - num2;
		printf("Proceso padre con pid: %d \n", getpid());
		printf("La resta es: %d \n", resta );
		pid = wait(&estado);
		printf("Termino el proceso hijo con pid: %d y estado: %d\n", pid, estado>>8 );
	}
	return 0;

}
