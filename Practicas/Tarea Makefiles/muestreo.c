#include <stdio.h>
#include "procesamiento.h"
#include "archivos.h"
#include "defs.h"

int main(){
	float seno[N];

	generaSeno( seno );
	guardaMuestras( seno );


	return 0;
}
