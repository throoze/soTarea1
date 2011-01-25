#include "almacenamiento.h"


segmento newSegmento() {
  segmento nuevo = (segmento *) malloc(sizeof(segmento));
  if (nuevo) {
    nuevo.ini = 1;
    nuevo.ant = NULL;
    nuevo.sig = NULL;
    int i;
    for (i = 0 ; i < TAMAX; i++){
      nuevo.trozo[i] = 0;
    }
    return nuevo;
  } else {
    fprintf(stderr, "newSegmento: Error al hacer la reserva de memoria!!!\n");
    exit 1;
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

int insertar (hashLote *lote, int pos, int num) {
  segmento inUse = lote.head;
  while (TRUE) {
    int fin = inUse.ini + (TAMAX - 1);
    if ( inUse.ini <= pos && pos <= fin ) {
      break;
    } else if  ( fin < pos && inUse.sig == NULL ) {
      segmento nuevo = newSegmento();
      nuevo.ini = calcRango(pos);
      inUse.sig = nuevo;
      nuevo.ant = inUse;
      inUse = nuevo;
      break;
    } else if (pos < inUse.ini && inUse.ant != NULL) {
      segmento nuevo = newSegmento();
      nuevo.ini = calcRango(pos);
      inUse.ant->sig = nuevo;
      nuevo.ant = inUse.ant;
      inUse.ant = nuevo;
      nuevo.sig = inUse;
      inUse = nuevo;
      break;
    }
    inUse = inUse.sig;
  }
  int newPos = calcPosicion(pos);
  inUse.trozo[newPos] = num;
  return 0;
}


