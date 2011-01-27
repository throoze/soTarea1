#ifndef STD
#define STD
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define TAMAX 10
#endif

/*INICIO DEFINICIÓN DE TIPOS*/

/*INICIO definición del tipo HashLote*/
/**
 * Híbrido entre lista y arreglos, basicamente es una lista enlazada de 
 * arreglos, que utilizaremos para almacenar elementos que estén relacionados 
 * con la posición que ocupan, para luego poder ubicarlos facilmente y 
 * agilizar la búsqueda.
 */
typedef struct segmento {
  int trozo[TAMAX],ini;
  struct segmento *ant,*sig;
} Segmento;

typedef struct {
  Segmento *head,*tail;
} HashLote;
/*FIN del tipo HashLote*/

/*INICIO definición del tipo Lista.*/

/**
 * Clasica lista de elementos. Es una lista de apuntadores a void, con lo cual
 * se podra almacenar practicamente cualquier cosa.
 */
typedef struct cajita{
  void *contenido;
  struct cajita *sig,*ant;
} Cajita;

typedef struct {
  Cajita *head,*tail;
  int size;
} Lista;
/*FIN del tipo Lista.*/

/* FIN DEFINICIÓN DE TIPOS*/

/*----------------------------------------------------------------------------*/

/*INICIO DECLARACIÓN DE FUNCIONES Y PROCEDIMIENTOS*/

/*INICIO Funciones y Procedimientos referentes al tipo hashLote*/
/**
 * Constructor del tipo Segmento. Se encarga de hacer la reserva de memoria y de
 * inicializar los campos convenientemente. El contenido del arreglo (trozo) se 
 * inicializa en 0.
 *
 * retorna: un apuntador a Segmento nuevo, inicializado, con su correspondiente 
 * reserva de memoria.
 */
Segmento *newSegmento();

/**
 * Constructor del tipo HashLote. Se encarga de hacer la reserva de memoria.
 * 
 * retorna: un nuevo apuntador a HashLote con su correspondiente reserva de 
 * memoria.
 */
HashLote *newHashLote();

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
 * Devuelve el elemento almacenado en la posición 'pos', en el HashLote 'lote'.
 * 
 * *lote: apuntador al lote donde se buscará el elemento.
 * 
 * pos: posición que se desea buscar  en el HashLote *lote.
 * 
 * retorna: el elemento en el HashLote '*lote' en la posición 'pos', en caso de
 *          estar. Devuelve 0 si el elemento en la posición 'pos' no ha sido 
 *          asignado; y -1 en caso de que el segmento correspondiente a la 
 *          posición buscada no exista.
 */
int get(HashLote *lote, int pos);


/**
 * Dice si el elemento en la posición 'pos' ha sido insertado en el HashLote 
 * '*lote'.
 * *lote: apuntador al lote donde se buscará el elemento.
 * 
 * pos: posición que se desea buscar en el HashLote *lote.
 * 
 * retorna: 1 en caso de que el elemento en la posición 'pos' haya sido asignado;
 *          0 en caso contrario.
 */
int contiene(HashLote *lote, int pos);

/**
 * Imprime en la salida estándar el contenido útil del HashLote 'lote'.
 * 
 * lote: El HashLote que se desea imprimir por la salida estándar.
 */
void print(HashLote lote);

/**
 * Se encarga de devolver un HashLote a su estado original vacío, liberando la
 * memoria consumida por éste.
 * 
 * lote: Un apuntador al HashLote que se desea limpiar.
 * 
 * retorna: 0 si se completó la limpieza con éxito, 1 en caso contrario.
 */
int limpiarHL(HashLote *lote);


/**
 * Función auxiliar que se encarga de liberar la memoria ocupada por un Segmento
 * y recursivamente por todos los Segmentos apuntados por él.
 * 
 * seg: Segmento a liberar recursivamente. Se toma como apuntador a void para 
 *      poder seguir apuntando a las estructuras miembros del Segmento pasado
 *      como parámetro.
 * 
 * retorna: 0 si se completó la limpieza con éxito, 1 en caso contrario.
 */
int limpiarSeg(void *seg);
/*FIN Funciones y Procedimientos referentes al tipo HashLote*/

/*----------------------------------------------------------------------------*/

/*INICIO Funciones y Procedimientos referentes al tipo Lista*/
/**
 * Crea una nueva Cajita, reservando la memoria necesaria para ello.
 * 
 * retorna: Un nuevo apuntador a Cajita vacía.
 */
Cajita *newCajita();

/**
 * Crea una nueva lista vacía, reservando la memoria necesaria para ello.
 * 
 * retorna: un nuevo apuntador a una lista vacía.
 */
Lista *newLista();
/*FIN Funciones y Procedimientos referentes al tipo Lista*/

/*----------------------------------------------------------------------------*/


/*FIN DECLARACIÓN DE FUNCIONES Y PROCEDIMIENTOS*/
/*FIN DEL ARCHIVO (EOF)*/
