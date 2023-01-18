#include <stdio.h>
#include <math.h>
#include "defs.h"

void generaSeno( float seno[] ){

	float f = 1000, fs = 40000;
	register int n; //No se le asigna memoria, si no en un registro del procesador. Lo mejor es tener todo en registros, pero no tenemos tanto, lo mejor es tener las varibles mas usadas.

	for(n = 0; n < N; n++){
		seno[n] = sinf(2*M_PI*f*n/fs);
	}
}
