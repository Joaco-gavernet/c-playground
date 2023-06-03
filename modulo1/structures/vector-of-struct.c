#include <stdio.h>
#include <limits.h>
#include <float.h>
#define forn(i, n) for (i = 0; i < n; i++)
#define DIM 2

struct myFigure
{
  float base;
  float altura;
};

// void initRectangulo(struct myFigure element) {
//     printf("ingresar base: ");
//     scanf("%f", &(element.base));
//     printf("ingresar altura: ");
//     scanf("%f", &(element.altura));
// }

void initRectangulo(struct myFigure *ptr)
{
  printf("ingresar base: ");
  scanf("%f", &(ptr->base));
  printf("ingresar altura: ");
  scanf("%f", &(ptr->altura));
}

float calcArea(struct myFigure ptr)
{
  return ptr.base * ptr.altura;
}

int checkMinor(struct myFigure vect[], int diml)
{
  static float min = FLT_MAX;
  static int minPos = 0;
  int i;

  forn(i, diml)
  {
    int aux = calcArea(vect[i]);
    if (aux < min)
    {
      min = aux;
      minPos = i;
    }
  }

  return minPos;
}

int main()
{
  struct myFigure rectangulo = {3, 4};
  struct myFigure vect[DIM];
  int i;

  forn(i, DIM)
  {
    printf("Rectangulo %d: \n", i);
    initRectangulo(&vect[i]);
  }

  forn(i, DIM)
  {
    printf("\nRectangulo %d base %.0f y altura %.0f", i, vect[i].base, vect[i].altura);
  }

  printf("\nposition of minor: %d", checkMinor(vect, DIM));

  return 0;
}
