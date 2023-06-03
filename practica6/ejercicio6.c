#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AREA_CIRCULO(r) (3.14 * (r) * (r))
#define forn(i,n) for(int i = 0; i < n; i++)

int main() {
  srand(time(NULL));

  forn(i, 3) {
    int r = rand() % 10 + 1;
    printf("Area para el radio %d = %f m2\n", r, AREA_CIRCULO(r));
  }

  return 0;
}