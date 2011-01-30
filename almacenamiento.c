#include "almacenamiento.h"
#ifndef STD
#define STD
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define TAMAX 10
#endif

/*INICIO Funciones y Procedimientos referentes al tipo hashLote*/
Segmento  *newSegmento() {
  Segmento *nuevo = (Segmento *) malloc(sizeof(Segmento));
  if (nuevo == NULL) {
    fprintf(stderr, "newSegmento: Error al hacer la reserva de memoria!!!\n");
    exit(1);
  } else {
    nuevo->ini = 1;
    nuevo->ant = NULL;
    nuevo->sig = NULL;
    int i;
    for (i = 0 ; i < TAMAX; i++){
      nuevo->trozo[i] = 0;
    }
    return nuevo;
  }
}

HashLote *newHashLote(){
  HashLote *nuevo = (HashLote *) malloc(sizeof(HashLote));
  if (nuevo) {
    nuevo->head = nuevo->tail = newSegmento();
    return nuevo;
  } else {
    fprintf(stderr, "newHashLote: Error al hacer la reserva de memoria!!!\n");
    exit(1);
  }
}

int calcRango (int pos) {
  int mod = pos % TAMAX;
  if (mod == 0) {
    return (pos - (TAMAX - 1));
  } else if (mod == 1) {
    return pos;
  } else {
    return pos - ((pos % TAMAX) - 1);
  }
}

int calcPosicion (int pos) {
  int mod = (pos % TAMAX);
  if (mod == 0) {
    return (TAMAX - 1);
  } else {
    return (mod - 1);
  }
}

int insertar (HashLote *lote, int pos, int num) {
  Segmento *inUse = lote->head;
  while (TRUE) {
    int fin = inUse->ini + (TAMAX - 1);
    /*DESCOMENTAR PARA VER EL FLUJO DE ESTA FUNCIÓN*/
    /*    printf("Inicio: %d; Fin: %d\n", inUse->ini, fin);*/
    if ( inUse->ini <= pos && pos <= fin ) {
      break;
    } else if  ( fin < pos && inUse->sig == NULL ) {
      Segmento *nuevo = newSegmento();
      nuevo->ini = calcRango(pos);
      inUse->sig = nuevo;
      nuevo->ant = inUse;
      inUse = lote->tail = nuevo;
      break;
    } else if (pos < inUse->ini && inUse->ant != NULL) {
      Segmento *nuevo = newSegmento();
      nuevo->ini = calcRango(pos);
      inUse->ant->sig = nuevo;
      nuevo->ant = inUse->ant;
      inUse->ant = nuevo;
      nuevo->sig = inUse;
      inUse = nuevo;
      break;
    }
    inUse = inUse->sig;
  }
  int newPos = calcPosicion(pos);
  inUse->trozo[newPos] = num;
  return 0;
}

int get(HashLote *lote, int pos){
  Segmento *inUse = lote->head;
  while (TRUE) {
    int fin = inUse->ini + (TAMAX - 1);
    if ( inUse->ini <= pos && pos <= fin ) {
      int newPos = calcPosicion(pos);
      return inUse->trozo[newPos];
    } else if  ( fin < pos && inUse->sig == NULL ) {
      return -1;
    } else if (pos < inUse->ini && inUse->ant != NULL) {
      return -1;
    }
    inUse = inUse->sig;
  }
}

int contiene(HashLote *lote, int pos){
  Segmento *inUse = lote->head;
  while (TRUE) {
    int fin = inUse->ini + (TAMAX - 1);
    if ( inUse->ini <= pos && pos <= fin ) {
      int newPos = calcPosicion(pos);
      if (inUse->trozo[newPos] != 0) {
	return 1;
      } else {
	return 0;
      }
    } else if  ( fin < pos && inUse->sig == NULL ) {
      return 0;
    } else if (pos < inUse->ini && inUse->ant != NULL) {
      return 0;
    }
    inUse = inUse->sig;
  }
}

void print(HashLote lote){
  Segmento *inUse = lote.head;
  printf("|-------|---------------|\n");
  printf("|  pos  |   contenido   |\n");
  printf("|-------|---------------|\n");
  while (inUse) {
    /*DESCOMENTAR PARA VER EL FLUJO DE ESTA FUNCIÓN*/
    /*printf("Inicio: %d; Fin: %d\n", inUse->ini, (inUse->ini + TAMAX -1));*/
    register int i;
    for (i = 0; i < TAMAX; i++){
      if (inUse->trozo[i] != 0) {
	int pos = (inUse->ini + i);
	printf("| %d\t| %d\t\t|\n",pos,inUse->trozo[i]);
      }
    }
    inUse = inUse->sig;
  }
  printf("|_______|_______________|\n");
}

int limpiarHL(HashLote *lote){
  lote->tail = NULL;
  if (limpiarSeg(lote->head->sig) != 0) {
    printf("limpiarHL: error al intentar liberar memoria!!!\n");
    return 1;
  }
  lote->head->ant = NULL;
  free(lote->head->trozo);
  free(lote->head);
  free(lote);
  return 0;
}

int limpiarSeg(void *seg){
  static int a = 0;
  a++;
  printf("Recursión No: %d",a);
  struct segmento *aux = (struct segmento *) seg;
  if (aux->sig != NULL) {
    if (limpiarSeg(aux->sig) != 0){
      printf("limpiarSeg: error al intentar liberar memoria!!!\n");
      return 1;
    }
  }
  aux->ant = NULL;
  free(aux->trozo);
  free(aux);
  return 0;
}
/*FIN Funciones y Procedimientos referentes al tipo HashLote*/


/*INICIO Funciones y Procedimientos referentes al tipo Lista*/
Cajita *newCajita() {
  Cajita *nueva = (Cajita *) malloc(sizeof(Cajita));
  if (nueva != NULL) {
    nueva->contenido = nueva->sig = nueva->ant = NULL;
    return nueva;
  } else {
    fprintf(stderr, "newCajita: Error al hacer la reserva de memoria!!!\n");
    exit(1);
  }
}

Lista *newLista() {
  Lista *nueva = (Lista *) malloc(sizeof(Lista));
  if (nueva != NULL) {
    nueva->head = nueva->tail = NULL;
    return nueva;
  } else {
    fprintf(stderr, "newLista: Error al hacer la reserva de memoria!!!\n");
    exit(1);
  }
}
/*FIN Funciones y Procedimientos referentes al tipo Lista*/
