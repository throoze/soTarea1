#define TAMAX 10

typedef struct {
  int trozo[TAMAX],ini,fin;
  segmento *ant,*sig;
} segmento

typedef struct {
  segmento *head,*tail;
} hashLote

typedef struct {
  void contenido;
  cajita sig,ant;
} cajita

typedef struct {
  cajita *head,*tail;
} lista

int insertar(hashLote *lote, int num);

segmento newSegmento(int hola);
