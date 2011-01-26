#include "main.h"

int main (){
  printf("No llevamos nada en el Main!!! =S\n\n");

  HashLote hola = *(newHashLote());

  printf("\n\nVeamos el resultado de las inserciones \n\n");

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
}
