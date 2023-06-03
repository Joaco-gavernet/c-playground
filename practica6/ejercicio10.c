// b. Una vez implementadas todas las funciones de biblioteca, escriba un programa que lea números
// enteros y los inserte en una pila. A continuación, desapile los elementos para verificar si funciona
// correctamente. La lectura finaliza con el ingreso del 0.
// c. Manteniendo la misma interfaz, modifique el tipo de datos stack y reimplemente la biblioteca para que la función s_length retorne la cantidad de elementos sin recorrer la pila.

#include <stdio.h>
#include "./bibliotecas/istack.h"

int main() {
  int x;
  printf("Ingresar numero para apilar (0 para finalizar): ");
  scanf("%d", &x);

  stack * stackBase = s_create(); // how to avoid if x == 0 ???

  while(x != 0) {
    s_push(stackBase, x);
    printf("Valor almacenado %d\n", s_top(*stackBase));
    printf("Ingresar numero para apilar (0 para finalizar): ");
    scanf("%d", &x);
  }

  printf("Cantidad de elementos en la pila: %d\n", s_length(*stackBase));
  printf("Pop de pila %d\n", s_pop(stackBase));

  return 0;
}