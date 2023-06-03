// Una vez implementadas todas las funciones de biblioteca, escriba un programa que lea números enteros e
// imprima el cuadrado y el cubo de aquellos números que son pares y el factorial de aquellos que son
// impares. La lectura finaliza con el ingreso del 0.

#include <stdio.h>
#include <stdlib.h>
#include "./bibliotecas/imath.h"

int main() {
  int x;
  printf("Ingresar x: ");
  scanf("%d", &x);

  while(x != 0) {
    if (par(x)) printf("Cuadrado y cubo de %d: %d y %d\n", x, cuadrado(x), cubo(x));
    else printf("Factorial de %d: %d\n", x, factorial(x));
    printf("Ingresar x: ");
    scanf("%d", &x);
  }

  return 0;
}