#ifndef STD
#define STD
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define TAMAX 10
#endif

#ifndef ALM
#define ALM
#include "almacenamiento.h"
#endif


/**
 * Se encarga de leer y almacenar un caso de prueba a la vez, para su posterior
 * análisis.
 * 
 * retorna: 0 en caso de que la lectura sea exitosa, 1 en caso contrario.
 */
int lectura();
