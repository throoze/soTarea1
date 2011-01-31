#include "main.h"
#ifndef STD
#define STD
#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define TAMAX 10
#endif
#ifndef ALM
#define ALM
#include "almacenamiento.h"
#endif

int main( int argc, char *argv[]) {
  /* INICIALIZACIONES */
  FILE *entrada = fopen(argv[1], "r");
  HashLote cand_raiz = *(newHashLote());
  HashLote hijos = *(newHashLote());
  int fuente;
  int destino;

  /* LECTURA DEL ARCHIVO DE ENTRADA*/
  while(fscanf(entrada, "%d %d", &fuente, &destino) != EOF){
    if (fuente != -1 && destino != -1) {
      if (fuente != 0 && destino != 0) 
	/* ALMACENAR LA ENTRADA Y DESCARTAR LAS DOS PRIMERAS CONDICIONES */
	if (TRUE) {
	  
	}
      } else {
	/* PROBAR LA CONDICION QUE FALTA E IMPRIMIR LA SALIDA DE ESTE CASO */
      }
      printf("%d %d\n", fuente, destino);
    } else {
      break;
    }
  }
}
