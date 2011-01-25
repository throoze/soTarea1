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


/**
 * Constructor del tipo segmento. Se encarga de hacer la reserva de memoria y de
 * inicializar los campos convenientemente. El contenido del arreglo (trozo) se 
 * inicializa en 0.
 *
 * retorna: un segmento nuevo, inicializado, con su correspondiente reserva de 
 *          memoria.
 */
segmento newSegmento();


/**
 * Inserta el numero 'num' en la posición 'pos' del hashLote '*lote'.
 * 
 * *lote: apuntador al lote donde se desea hacer la inserción.
 * 
 * pos: posición en la que se desea insertar.
 * 
 * num: número a insertar en el hashLote.
 * 
 * retorna: Un entero que indica el estado de la inserción; 0 si fue realizada 
 *          con éxito, cualquier otro número en caso contrario.
 */
int insertar(hashLote *lote, int pos, int num);

/**
 * Sirve para calcular el segmento al que corresponde la posicion pasada como 
 * argumento.
 * 
 * pos: posición a la cual se le quiere calcular el rango.
 * 
 * retorna: entero que indica el inicio del rango al que corresponde 'pos'.
 *          El final del rango es calculable sumando (x + (TAMAX - 1)), donde 
 *          'x' es el número devuelto por esta función.
 */
int calcRango(int pos);

/**
 * Calcula la posicion interna dentro de un segmento donde debe ir 'pos'
 * 
 * pos: posición a la cual se le calcula la posición interna en el trozo de 
 *      hashLote.
 * 
 * retorna: Posición interna en el arreglo del segmento al cual corresponde la 
 *          posición 'pos'.
 */
int calcPosicion(int pos);
