#ifndef STD
#define STD
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#endif
#define TAMAX 10


typedef struct {
  int trozo[TAMAX],ini;
  struct segmento *ant,*sig;
} segmento;

typedef struct {
  segmento *head,*tail;
} hashLote;

typedef struct {
  void contenido;
  struct cajita sig,ant;
} cajita;

typedef struct {
  cajita *head,*tail;
} lista;

segmento newSegmento();


/*
Inserta el numero 'num' en la posición 'pos' del hashLote '*lote'.
Devuelve un entero que indica el estado de la inserción; 0 si fue realizada con
éxito, cualquier otro número en caso contrario.*/
int insertar(hashLote *lote, int pos, int num);

/*
Sirve para calcular el segmento al que corresponde la posicion pasada como 
argumento. Devuelve el inicio del rango al que corresponde 'pos'. El final del
rango es calculable sumando (x + (TAMAX - 1)), donde 'x' es el número devuelto
por esta función.
*/
int calcRango(int pos);

/*
Calcula la posicion interna dentro de un segmento donde debe ir 'pos'
*/
int calcPosicion(int pos);
