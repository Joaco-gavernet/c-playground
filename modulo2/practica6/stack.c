// a. Stack* s_create () – Retorna una nueva pila. Se debe invocar antes de
// manipular cualquiera de ellas.
// b. int s_push(stack* s, int n) – Apila n en s. Retorna el elemento apilado.
// c. int s_pop (stack* s) – Desapila un elemento de s.
// d. int s_top (stack s) – Retorna el próximo elemento que será desapilado.
// e. int s_empty(stack s) – Retorna 1 si s está vacía, 0 en caso contrario.
// f. int s_length(stack s) – Retorna la cantidad de elementos apilados en s.

#include <stdio.h>
#include "./bibliotecas/istack.h"

stack * s_create() {
  stack * nueva;
  nueva = (stack *) calloc(1, sizeof(stack));
  return nueva;
}

int s_push(stack * s, int n) {
  nodo * nuevo = (nodo *) calloc(1, sizeof(nodo));
  nuevo->dato = n;
  nuevo->sig = s->first;
  s->first = nuevo;
  s->dim += 1;
  return n;
}

int s_pop(stack * s) {
  int result = 0;
  int dato;
  if (s->dim != 0) {
    nodo * result = s->first;
    dato = result->dato;
    s->first = result->sig;
    free(result); // libero el ultimo elemento en la pila
  }
  return dato;
}

int s_top(stack s) {
  return s.first->dato;
}

int s_empty(stack s) { 
  return (s.dim == 0) ? 1 : 0;
}

int s_length(stack s) { 
  return s.dim;
}
