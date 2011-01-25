#ifndef STD
#define STD
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#endif
#define TAMAX 10

/*INICIO definición del tipo HashLote*/
typedef struct {
  int trozo[TAMAX],ini;
  struct Segmento *ant,*sig;
} Segmento;

typedef struct {
  Segmento *head,*tail;
} HashLote;
/*FIN del tipo HashLote*/

/*INICIO definición del tipo Lista.*/
typedef struct {
  void contenido;
  struct Cajita sig,ant;
} Cajita;

typedef struct {
  Cajita *head,*tail;
} Lista;
/*FIN del tipo Lista.*/



/*INICIO Funciones y Procedimientos referentes al tipo hashLote*/
/**
 * Constructor del tipo Segmento. Se encarga de hacer la reserva de memoria y de
 * inicializar los campos convenientemente. El contenido del arreglo (trozo) se 
 * inicializa en 0.
 *
 * retorna: un Segmento nuevo, inicializado, con su correspondiente reserva de 
 *          memoria.
 */
Segmento newSegmento();


/**
 * Inserta el numero 'num' en la posición 'pos' del HashLote '*lote'.
 * 
 * *lote: apuntador al lote donde se desea hacer la inserción.
 * 
 * pos: posición en la que se desea insertar.
 * 
 * num: número a insertar en el HashLote.
 * 
 * retorna: Un entero que indica el estado de la inserción; 0 si fue realizada 
 *          con éxito, cualquier otro número en caso contrario.
 */
int insertar(HashLote *lote, int pos, int num);

/**
 * Sirve para calcular el Segmento al que corresponde la posicion pasada como 
 * argumento.
 * 
 * pos: posición a la cual se le quiere calcular el rango.
 * 
 * retorna: Entero que indica el inicio del rango al que corresponde 'pos'.
 *          El final del rango es calculable sumando (x + (TAMAX - 1)), donde 
 *          'x' es el número devuelto por esta función.
 */
int calcRango(int pos);

/**
 * Calcula la posicion interna dentro de un Segmento donde debe ir 'pos'
 * 
 * pos: posición a la cual se le calcula la posición interna en el trozo de 
 *      HashLote.
 * 
 * retorna: Posición interna en el arreglo del segmento al cual corresponde la 
 *          posición 'pos'.
 */
int calcPosicion(int pos);
/*FIN Funciones y Procedimientos referentes al tipo HashLote*/


/*INICIO Funciones y Procedimientos referentes al tipo Lista*/
