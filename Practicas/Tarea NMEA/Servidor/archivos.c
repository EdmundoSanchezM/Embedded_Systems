#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char tiempo[10], latitude[11], a_lat ,longitude[12], a_long;
void manejarCadenas(char *datos){
	a_lat = a_long = 42;
	char cadenaNMEA[100];
	register int i,j;
	int lastcoma = 7;
	strcpy(cadenaNMEA, datos);
	j=0;
	for(i = 7 ; cadenaNMEA[i] != '\0' ; i++)
		if(cadenaNMEA[i] == 44){
			 switch (j){
			 	case 0:
				    	strncpy(tiempo, cadenaNMEA + lastcoma, i - lastcoma - 3);//Quitando .00 para eso el -3					
				    	tiempo[9] = '\0';
				    	char arr_t[10];
				    	int k = 0 , l = 0;
				    	for(; tiempo[k] != '\0'; k++,l++){
				    		arr_t[l] = tiempo[k];
				    		if(k%2!=0){
				    			l++;
				    			arr_t[l] = ':';
				    		}
				    	}
				    	arr_t[l-1] = '\0';
				    	strcpy(tiempo, arr_t);
			      	break;
			   	case 1:
				    	strncpy(latitude, cadenaNMEA + lastcoma, i - lastcoma);
				    	latitude[10] = '\0';
			      	break;
			      	case 2:
				    	a_lat = cadenaNMEA[i-1];
			      	break;
			   	case 3:
				    	strncpy(longitude, cadenaNMEA + lastcoma, i - lastcoma);
				    	longitude[11] = '\0';
			      	break;
			      	case 4:
			      		a_long = cadenaNMEA[i-1];
			      	break;
			    default:
			      break;
			  }
			j++;
			lastcoma = i+1;
		}
}

void leerArchivo(char *datos,  char *archivo ){
	FILE *apArch;
	apArch = fopen( archivo, "r");
	if( apArch == NULL ){
		perror("Error al abrir el archivo");
		exit(EXIT_FAILURE);
	}
	while( fscanf(apArch, "%s", datos) != EOF )
		if( !strncmp( "$GPGGA", datos, 6 ) ){
			break;
		}
				
	fclose( apArch );
}
