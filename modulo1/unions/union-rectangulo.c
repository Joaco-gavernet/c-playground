#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DIM 4
#define forn(i, n) for (i = 0; i < n; i++)

union tventana
{
  struct
  {
    int x, y, ancho, alto;
  } isolated;

  struct
  {
    struct
    {
      int x, y;
    } point1, point2;
  } pairs;

  int junction[4];
};
typedef union tventana ventana;

int main()
{
  ventana rectangulo;

  rectangulo.isolated.x = 10;
  rectangulo.isolated.y = 10;
  rectangulo.isolated.ancho = 20;
  rectangulo.isolated.alto = 30;
  printf("Isolated: %d %d %d %d\n", rectangulo.isolated.x, rectangulo.isolated.y, rectangulo.isolated.ancho, rectangulo.isolated.alto);

  rectangulo.pairs.point1.x = 10;
  rectangulo.pairs.point1.y = 10;
  rectangulo.pairs.point2.x = 20;
  rectangulo.pairs.point2.y = 30;
  printf("Pairs: %d %d %d %d\n", rectangulo.pairs.point1.x, rectangulo.pairs.point1.y, rectangulo.pairs.point2.x, rectangulo.pairs.point2.y);

  rectangulo.junction[0] = 10;
  rectangulo.junction[1] = 10;
  rectangulo.junction[2] = 20;
  rectangulo.junction[3] = 30;
  printf("Junction: %d %d %d %d\n", rectangulo.junction[0], rectangulo.junction[1], rectangulo.junction[2], rectangulo.junction[3]);

  return 0;
}
