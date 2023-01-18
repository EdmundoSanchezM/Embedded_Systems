#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#define PID 18080

int main(){

	kill( PID, SIGINT );
	sleep(5);
	kill( PID, SIGTERM );
	sleep(5);
	kill( PID, SIGKILL );
	sleep(5);
	
	return 0;
}
