#include <stdio.h>
#include "ipot.h"

int potencia(int x, int y) {
  int res = 1;
  for (int i = 0; i < y; i++) res *= x;
  return res;
}

int cuadrado(int x) {
  return potencia(x, 2);
}
