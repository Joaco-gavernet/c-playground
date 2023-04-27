#include <stdlib.h>
#include <stdio.h>

struct nodo
{
  int dato;
  struct nodo *sig;
};

void inicializarLista(struct nodo **first)
{
  *first = (struct nodo *)calloc(1, sizeof(struct nodo));
  (*first)->sig = 0;
}

void imprimirLista(struct nodo *first)
{
  if (first == 0)
    printf("lista vacia"); // verifico si la lista esta vacia
  else
  {
    struct nodo aux = *first;
    printf("-> %d", aux.dato);
    while (aux.sig != 0)
    {
      aux = *aux.sig;
      printf(" -> %d", aux.dato);
    }
  }
  printf("\n");
}

void agregarFinal(struct nodo *aux, int n)
{
  while (aux->sig != 0)
  {
    aux = aux->sig;
  } // salgo con un puntero al ultimo nodo asignado en aux
  struct nodo *nuevo = (struct nodo *)malloc(sizeof(struct nodo));
  nuevo->dato = n;
  nuevo->sig = 0;

  aux->sig = nuevo;
}

void agregarInicio(struct nodo **first, int n)
{
  struct nodo *nuevo = (struct nodo *)malloc(sizeof(struct nodo *));
  nuevo->dato = n;
  nuevo->sig = *first;
  *first = nuevo;
}

int tamanio(struct nodo *first)
{
  if (first == 0)
    return 0; // verifico si la lista esta vacia
  else
  {
    struct nodo aux = *first;
    int tot = 1;
    while (aux.sig != 0)
    {
      aux = *aux.sig;
      tot++;
    }
    return tot;
  }
}

void vaciarLista(struct nodo **aux)
{
  struct nodo *sig;
  while (*aux != 0)
  {
    sig = (*aux)->sig;
    free(*aux);
    *aux = sig;
  }
}

int main()
{
  struct nodo *first;
  inicializarLista(&first);
  imprimirLista(first);

  agregarFinal(first, 1);
  agregarFinal(first, 2);
  agregarFinal(first, 3);
  imprimirLista(first);

  agregarInicio(&first, -1);
  imprimirLista(first);
  printf("tamanio: %d\n", tamanio(first));

  vaciarLista(&first);
  printf("tamanio despues de vaciar lista: %d", tamanio(first));
}
