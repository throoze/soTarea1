#include "almacenamiento.h"

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
    int fin = inUse.ini + TAMAX - 1;
    if ( inUse.ini <= pos && pos < (inUse.ini + TAMAX) ) {
      break;
    } else if  ( fin < pos && inUse.sig == NULL ) {
      segmento nuevo = newSegmento();
      inUse.sig = nuevo;
      nuevo.ant = inUse;
      inUse = nuevo;
      break;
    } else if (pos < inUse.ini && inUse.ant != NULL) {
      segmento nuevo = newSegmento();
      inUse.ant.sig = nuevo;
      nuevo.ant = inUse.ant;
      inUse.ant = nuevo;
      nuevo.sig = inUse;
      inUse = nuevo;
      break;
    }
    inUse = inUse.sig;
  }
  
  inUse.ini = calcRango(pos);
  inUse.trozo[calcPosicion(pos)] = num;
}
