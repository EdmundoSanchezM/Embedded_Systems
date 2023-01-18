#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define NUM_PROC 8
#define EVER 1

void proceso_padre();
void proceso_hijo(int np);
int num1 = 45, num2=5;
int main(){

	pid_t pid;
	register int np;
	printf("Probando procesos...\n");
	
	for(np = 0; np < NUM_PROC; np++){
		pid = fork();
		if( pid == -1){
			perror("Error al crear proceso hijos\n");
			exit(EXIT_FAILURE);
		}
		if( !pid ){
			proceso_hijo( np );
			
		}
	}
	proceso_padre();
	return 0;

}

void proceso_padre(){
	int estado;
	pid_t pid;
	register int np;
	for(np = 0; np < NUM_PROC; np++){
		pid = wait(&estado);
		printf("Resultado: %d en proceso con pid: %d\n", estado>>8,pid);
	}
}

void proceso_hijo(int np){
	int res;
	printf("Proceso hijo: %d con pid: %d \n", np,getpid());
	//for(;EVER;);
	//sleep(5);
	if(np == 0){
		res = num1 + num2;
	}else if(np == 1){
		res = num1 - num2;
	}else if(np == 2){
		res = num1 * num2;
	}else if(np == 3){
		res = num1 / num2;
	}	
	exit(res);
}
