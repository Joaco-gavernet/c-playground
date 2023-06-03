#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int dato;
  struct nodo * siguiente;
} lista;

void carga(struct nodo **);
int liberar(struct nodo **);

int main() {
  struct nodo * l;
  carga(&l);
  while (liberar(&l)) {
    printf("Libero nodo\n");
  }

  return 0;
}

void carga(struct nodo ** first) {
  int n;
    *first = (struct nodo *) calloc(1, sizeof(struct nodo));
    (*first)->dato = rand() % 100 + 1;
    (*first)->siguiente = NULL;

  for (int i = 0; i < 3; i++) {
    struct nodo * nuevo = (struct nodo *) calloc(1, sizeof(struct nodo));
    nuevo->dato = rand() % 100 + 1;
    nuevo->siguiente = *first;
    *first = nuevo;
  }
}

int liberar(struct nodo ** first) {
  if ((*first) == NULL) return 0;

  struct nodo * act = (*first);
  struct nodo * ant = act;

  while (act->siguiente != NULL) {
    ant = act;
    act = act->siguiente;
  }

  if (ant == act) {
    free(act);
    (*first) = NULL;
  } else {
    free(act);
    ant->siguiente = NULL;
  }
  
  return 1;
}