#include "main.h"
#ifndef STD
#define STD
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define TAMAX 10
#endif
#ifndef ALM
#define ALM
#include "almacenamiento.h"
#endif

int main( argc, char *argv[]){

  FILE *leer = fopen(argv[1], "r");
  int fuente;
  int destino; 
  while(fscanf(leer, "%d %d", &fuente, &destino) != EOF){
    printf("%d %d\n", fuente, destino);
   return 1;  

  HashLote cand_raiz = *(newHashLote());
  HashLote hijos = *(newHashLote());


  /*  printf("\n\nVeamos el resultado de las inserciones \n\n");

  printf("%d\n",insertar(&hola,1,32));
  printf("%d\n",insertar(&hola,2,34));
  printf("%d\n",insertar(&hola,3,543));
  printf("%d\n",insertar(&hola,9,345));
  printf("%d\n",insertar(&hola,16,-98));
  printf("%d\n",insertar(&hola,35,54));
  printf("%d\n",insertar(&hola,123,98));
  printf("%d\n",insertar(&hola,400,56));
  printf("%d\n",insertar(&hola,401,986));
  printf("%d\n",insertar(&hola,402,36));
  printf("%d\n",insertar(&hola,403,234));
  printf("%d\n",insertar(&hola,404,984));

  printf("\n\nAhora imprimimos el HashLote \n\n");

  print(hola);
  
  printf("\n\nAhora veamos que hay en el HashLote \n\n");

  printf("%d\n",get(&hola,1));
  printf("%d\n",get(&hola,2));
  printf("%d\n",get(&hola,3));
  printf("%d\n",get(&hola,9));
  printf("%d\n",get(&hola,16));
  printf("%d\n",get(&hola,35));
  printf("%d\n",get(&hola,123));
  printf("%d\n",get(&hola,400));
  printf("%d\n",get(&hola,401));
  printf("%d\n",get(&hola,402));
  printf("%d\n",get(&hola,403));
  printf("%d\n",get(&hola,404));
  printf("%d\n",get(&hola,405));
  printf("%d\n",get(&hola,413));

  printf("\n\nAhora imprimamos de nuevo \n\n");
  
  print(hola);

  printf("\n\nAhora veamos si la funcion 'contiene' funciona \n\n");

  printf("Hay algo en el 1?: %s\n", (contiene(&hola, 1) ? "SI" : "NO"));
  printf("Hay algo en el 2?: %s\n", (contiene(&hola, 2) ? "SI" : "NO"));
  printf("Hay algo en el 5?: %s\n", (contiene(&hola, 5) ? "SI" : "NO"));
  printf("Hay algo en el 9?: %s\n", (contiene(&hola, 9) ? "SI" : "NO"));
  printf("Hay algo en el 15?: %s\n", (contiene(&hola, 15) ? "SI" : "NO"));
  printf("Hay algo en el 16?: %s\n", (contiene(&hola, 16) ? "SI" : "NO"));
  printf("Hay algo en el 122?: %s\n", (contiene(&hola, 122) ? "SI" : "NO"));
  printf("Hay algo en el 123?: %s\n", (contiene(&hola, 123) ? "SI" : "NO"));
  printf("Hay algo en el 400?: %s\n", (contiene(&hola, 400) ? "SI" : "NO"));
  printf("Hay algo en el 401?: %s\n", (contiene(&hola, 401) ? "SI" : "NO"));
  printf("Hay algo en el 402?: %s\n", (contiene(&hola, 402) ? "SI" : "NO"));

  printf("\n\nAhora vamos a limpiar el HashLote \n\n");

  if (limpiarHL(&hola) != 0) {
      printf("Error limpiando el HashLote!!!!\n");
  }

  printf("\n\nAhora veamos que hay en el HashLote \n\n");

  print(hola); */

}
