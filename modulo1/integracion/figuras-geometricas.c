#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define forn(i, n) for (i = 0; i < n; i++)
#define DIMF 4

typedef struct
{
  unsigned int tipo : 3; // tipo de figura almacenada
  union
  {
    int radio;                    // 4 bytes
    unsigned short int radios[2]; // 4 bytes, radio mayor y radio menor de elipse
    unsigned short int bh[2];     // 4 bytes, base (b) y altura (h)
  } datos;                        // 4 bytes
} figura;

float calcularArea(figura f)
{
  float area = 0;
  if (f.tipo == 0)
  { // circulo
    area = 3.14 * pow(f.datos.radio, 2);
  }
  else if (f.tipo == 1)
  { // elipse
    area = 3.14 * f.datos.radios[0] * f.datos.radios[1];
  }
  else if (f.tipo == 2)
  { // triangulo
    area = (f.datos.bh[0] * f.datos.bh[1]) / 2;
  }
  else
  { // cuadrado y rectangulo
    area = f.datos.bh[0] * f.datos.bh[1];
  }

  return area;
}

int main()
{
  enum figuras
  {
    circulo,
    elipse,
    triangulo,
    cuadrado,
    rectangulo
  };
  const char *recuperarFigura[] = {"circulo", "elipse", "triangulo", "cuadrado", "rectangulo"};

  figura mantel;
  mantel.tipo = cuadrado;
  mantel.datos.bh[0] = 2;
  mantel.datos.bh[1] = 2;

  figura sol;
  sol.tipo = circulo;
  sol.datos.radio = 10;

  printf("Area de %s = %.2f\n", recuperarFigura[mantel.tipo], calcularArea(mantel));
  printf("Area de %s = %.2f\n", recuperarFigura[sol.tipo], calcularArea(sol));

  return 0;
}
