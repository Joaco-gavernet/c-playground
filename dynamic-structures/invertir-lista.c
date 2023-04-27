#include <stdlib.h>
#include <stdio.h>

struct nodo
{
  int dato;
  struct nodo *sig;
};

void inicializarLista(struct nodo **first, int n)
{
  *first = (struct nodo *)calloc(1, sizeof(struct nodo));
  (*first)->dato = n;
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

void cargarLista(struct nodo **first)
{
  int n;
  printf("ingrese un numero: ");
  scanf("%d", &n);
  while (n != 0)
  {
    if (tamanio(*first))
      agregarFinal(*first, n);
    else
      inicializarLista(first, n);
    printf("ingrese un numero: ");
    scanf("%d", &n);
  }
  imprimirLista(*first);
}

struct nodo *invertirLista(struct nodo *first)
{
  struct nodo *inverted;

  if (first == 0)
  {
    return 0;
  }
  else
  {
    struct nodo aux = *first;
    while (aux.sig != 0)
    {
      if (tamanio(inverted))
      {
        agregarInicio(&inverted, aux.dato);
      }
      else
      {
        inicializarLista(&inverted, aux.dato);
      }
      aux = *aux.sig;
    }
    agregarInicio(&inverted, aux.dato);
  }
  return inverted;
}

int main()
{
  struct nodo *first = 0;
  struct nodo *inverted;

  cargarLista(&first);

  inverted = invertirLista(first);
  imprimirLista(inverted);

  vaciarLista(first);
  vaciarLista(inverted);
}
