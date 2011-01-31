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
#define min(a,b)  ((a < b) ? (a) : (b))
#define max(a,b)  ((a > b) ? (a) : (b))
#define SI 1
#define NO -1

int main( int argc, char *argv[]) {
  
  /* INICIALIZACIONES */
  FILE *entrada = fopen(argv[1], "r");   /* ARCHIVO DE ENTRADA */
  HashLote cand_raiz = *(newHashLote()); /* GUARDA LOS CANDIDATOS A RAIZ */
  HashLote hijos = *(newHashLote());     /* LISTA DE PREDECESORES DE CADA NODO */
  HashLote *padres = newHashLote();      /* LISTA DE SUCESORES DE CADA NODO */
  HashLote *casos = newHashLote();       /* RESULTADO DE CADA CASO */
  int countCaso = 0;                     /* CUENTA LOS CASOS EVALUADOS */
  int fuente;                            /* NODO FUENTE RECIEN LEIDO */
  int destino;                           /* NODO DESTINO RECIEN LEIDO */
  int nodoMax = 0;                       /* NODO DE NÚMERO MÍNIMO */
  int nodoMin = 0;                       /* NODO DE NÚMERO MÁXIMO */
  int raiz = 0;                          /* CANDIDATO ELEGIDO COMO RAIZ */

  /* COMIENZO DEL PROCESAMIENTO DE DATOS */

  /* LECTURA DEL ARCHIVO DE ENTRADA */
  while(fscanf(entrada, "%d %d", &fuente, &destino) != EOF){
    countCaso++;
    if (fuente != -1 && destino != -1) {
      if (fuente != 0 && destino != 0){
      	/* Almacenar la entrada y descartar las dos primeras condiciones */
	
	/* Actualizar el máximo y el minimo de este caso */
	if (nodoMin > 0 && nodoMin > min(fuente,destino)) {
	  nodoMin = min(fuente,destino);
	}
	if (nodoMax < max(fuente,destino)){
	  nodoMax = max(fuente,destino);
	}

  	/* Inserta la fuente en los candidatos de raiz solo si no existia ya */
	/* en hijos*/
  	if (!(contiene(&hijos, fuente))) {
	  insertar(&cand_raiz, fuente, TRUE);
	}
      
	/* Inserta los hijos y chequea que no esté en la lista de posibles */
	/* raices. si esta en la lista de raices, se elimina de ésta. */
	/* si el nodo destino ya estaba almacenado, es porque ese nodo tiene */
	/* dos padres, entonces se ya se sabe que no es un árbol */
	int cont = get(&hijos,destino);
	if (cont == 0 || cont == fuente) {
	  if (cont == 0) {
	    insertar(&hijos, destino, fuente);
	  }
	  if(contiene(&cand_raiz, destino)){
	    insertar(&cand_raiz, destino, FALSE);
	  }
	} else {
	  /* Se viola la segunda condición: */
	  /* Todo nodo solo tiene exactamente un padre */
	  insertar(casos, countCaso, NO);
	  goto limpiar_mem;
	}
	
	/* Inserto el nodo correspondiente en la lista de sucesores */
        insertar(padres, fuente, destino);

      } else {
	/* Se procesan los datos ya guardados para este caso */
	
	/* Primera condición: */
	/* Si hay mas de un candidato a raiz, no es un árbol */
	if (cand_raiz.size != 1) {
	  insertar(casos, countCaso, NO);
	  goto limpiar_mem;
	} else {
	  int *arr = (int *) toArray(&cand_raiz);
	  raiz = arr[0];
	  free(arr);
	  arr = NULL;
	  hl_liberar(&cand_raiz);
	}
	
	/* Segunda condición: */
	/* Todo nodo debe tener exactamente un padre */
	/* ya está verificada en la etapa de lectura, si algun nodo tuviese */
	/* dos padres, el caso hubiese terminado en la sección anterior. */
	/* falta revisar que no haya nodos aislados, es decir que existan */
	/* arcos hacia cada uno de los nodos */
	register int i;
	for (i = nodoMin; i <= nodoMax; i++){
	  if ( (i != raiz) && !(contiene(padres,i)) ) {
	    insertar(casos, countCaso, NO);
	    break;
	  }
	}
	if (get(casos,countCaso) == NO) {
	  goto limpiar_mem;
	}
	
	/* Tercera condición: */
	/* Existe un camino desde la raiz hacia cada nodo. verificamos la  */
	/* lista de predecesores. si se encuentra algún ciclo, el caso no  */
	/* es un arbol. */
	for (i = nodoMin; i <= nodoMax; i++ ){
	  
	}
	
      }
    }
    /* IMPRIMIR LA SALIDA */

  limpiar_mem:
    /* LIBERAR MEMORIA USADA */
    hl_liberar(&cand_raiz);
    hl_liberar(&hijos);
    hl_liberar(padres);
    hl_liberar(casos);
    break;
  }
}
