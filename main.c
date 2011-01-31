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

int hayCamino(HashLote *lote, int hoja, int desde, int raiz){
  int pred = get(lote,desde);
  if (pred != 0){
    if(pred == raiz){
      return 1;
    }
    else if( pred == hoja){
      return 0;
    }
    else{
      if(hayCamino(lote,hoja,pred,raiz)){
      	insertar(lote,desde,raiz);
      	return 1;
      }
      else {
      	return 0;
      }
    }
  } else {
    return 0;
  }
}

int main( int argc, char *argv[]) {
  /* INICIALIZACIONES */
  FILE *entrada = fopen(argv[1], "r");
  HashLote cand_raiz = *(newHashLote());
  HashLote hijos = *(newHashLote());
  ListaInt casos = *(newListaInt());
  int fuente;
  int destino;
  int raiz;

  /* LECTURA DEL ARCHIVO DE ENTRADA */
  while(fscanf(entrada, "%d %d", &fuente, &destino) != EOF){
    if (fuente == -1 && destino == -1) {
      fclose(entrada);
      CajitaInt *aux = casos.head;
      register int j = 1;
      while (aux) {
	printf("Caso %d %s un arbol.\n",j,(aux->data ? "es" : "no es"));
	j++;
	aux = aux->sig;
      }
      aux = NULL;
      li_liberar(&casos);
      break;
    }
    else if (fuente == 0 && destino == 0){
      if(cand_raiz.size != 1) {
	add(&casos,FALSE);
	goto liberar_mem;
      }
      else {
	int *ar = posToArray(&cand_raiz);
	raiz = ar[0];
	free(ar);
	/* verifica que todos los hijos tienen camino a la raiz unica */
	ar = posToArray(&hijos);
	register int i;
	int bool = 1;
	for (i = 0; i < hijos.size; i++){
	  bool = hayCamino(&hijos,ar[i],ar[i],raiz);
	  if (bool != 1)  {
	    add(&casos,FALSE);
	    goto liberar_mem;
	  }
	}
	if (bool) {
	  add(&casos,TRUE);
	}
      }
      
    liberar_mem:      
      /* liberar la memoria */
      if (cand_raiz.size !=0) {
	hl_liberar(&cand_raiz);
	cand_raiz = *(newHashLote());
      }
      hl_liberar(&hijos);
      hijos = *(newHashLote());
      if (fuente != 0 && destino != 0) {
	/* TERMINA DE LEER EL CASO, EN CASO DE HABERSE CORTADO. */
	while(fscanf(entrada, "%d %d", &fuente, &destino) != EOF){
	  if (fuente == 0 && destino == 0){
	    break;
	  }
	}
      }
      continue;
    }
    else {
      
      
      /* ALMACENAR LA ENTRADA Y DESCARTAR LAS DOS PRIMERAS CONDICIONES */
      
      /* INSERTA LA FUENTE EN LOS CANDIDATOS DE RAIZ SOLO SI NO EXISTIA YA EN ESTE HASHLOTE O EN HIJOS*/
      if (!(contiene(&hijos, fuente))) {
	insertar(&cand_raiz, fuente, TRUE);
      }
      

      /* INSERTA LOS HIJOS MIENTRAS NO ESTEN REPETIDOS EN HIJOS, SI SE ENCUENTRA COMO POSIBLE RAIZ, ENTONCES ES ELIMINADO DE DICHO HASHLOTE */
      if(!(contiene(&hijos, destino))){
	insertar(&hijos, destino, fuente);
	if(contiene(&cand_raiz,destino)){
	  insertar(&cand_raiz,destino,FALSE);	  
	}
      }
      else{
	add(&casos, FALSE);
	goto liberar_mem;
      }
    }
  }
}
