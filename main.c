#include "main.h"
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

int main( int argc, char *argv[]) {

  FILE *leer = fopen(argv[1], "r");
  int fuente;
  int destino;
  while(fscanf(leer, "%d %d", &fuente, &destino) != EOF){
    printf("%d %d\n", fuente, destino);
  }

  HashLote cand_raiz = *(newHashLote());
  HashLote hijos = *(newHashLote());
}
