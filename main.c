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
  ListaInt casos = *(newListaInt());
  int fuente;
  int destino;

  /* LECTURA DEL ARCHIVO DE ENTRADA*/
  while(fscanf(entrada, "%d %d", &fuente, &destino) != EOF){
    if (fuente != -1 && destino != -1) {
      if (fuente != 0 && destino != 0)
  	/* ALMACENAR LA ENTRADA Y DESCARTAR LAS DOS PRIMERAS CONDICIONES */

	/* INSERTA LA FUENTE EN LOS CANDIDATOS DE RAIZ SOLO SI NO EXISTIA YA EN ESTE HASHLOTE O EN HIJOS*/
	if (!(contiene(&cand_raiz, fuente) && !(contiene(&hijos, fuente)))) {
	  insertar(&cand_raiz, fuente, 1);  
	}
	else {

	  /* INSERTA LOS HIJOS MIENTRAS NO ESTEN REPETIDOS EN HIJOS, SI SE ENCUENTRA COMO POSIBLE RAIZ, ENTONCES ES ELIMINADO DE DICHO HASHLOTE*/
	  if(!(contiene(&hijos, destino))){
	    insertar(&hijos, destino, fuente);
	  }else{
		add(&casos, 0);
	  }
	  /* PROBAR LA CONDICION QUE FALTA E IMPRIMIR LA SALIDA DE ESTE CASO */
        }
      //    printf("%d %d\n", fuente, destino);
     
  } else {
      break;
    }
  }
  printf("POSIBLES RAICES");
  hl_print(cand_raiz);
  printf("HIJOS");
  hl_print(hijos);
  printf("CASOS");
  li_print(casos); 
}
