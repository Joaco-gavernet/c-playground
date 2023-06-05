#include <stdio.h>
#include "ipot.h"
#include "ipot.c"

int main() {
  int x = 2;
  int y = 3;

  printf("%d^%d = %d\n", x, y, potencia(x, y));
  printf("%d^2 = %d\n", x, cuadrado(x));

  return 0;
}