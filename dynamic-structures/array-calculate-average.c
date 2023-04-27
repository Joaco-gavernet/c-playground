#include <stdlib.h>
#include <stdio.h>

void allocateFloat(int *p, int n) { *p = (float *)malloc(n * sizeof(float)); }

void init(float *p, int n)
{
  for (int i = 0; i < n; i++)
  {
    scanf("%f", &(p[i])); // p + 1, es valido para hacer una asignacion
    fflush(stdin);
  }
}

void print(float *p, int n)
{
  for (int i = 0; i < n; i++)
    printf("%f ", p[i]);
  printf("\n");
}

float promedio(float *p, int n)
{
  float total = 0;
  for (int i = 0; i < n; i++)
    total += p[i];
  return total / n;
}

int main()
{

  int n;
  scanf("%d", &n);
  float *a;

  // malloc
  allocateFloat(&a, n);
  print(a, n);
  init(a, n);
  print(a, n);

  float prom = promedio(a, n);
  printf("promedio: %f", prom);

  free(a);
}
