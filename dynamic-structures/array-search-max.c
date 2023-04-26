#include <stdlib.h>
#include <stdio.h>

void allocate(int *p, int n) { *p = (int *)malloc(n * sizeof(float)); }
void init(int *p, int n)
{
  for (int i = 0; i < n; i++)
    p[i] = rand() % 100;
}
void print(int *p, int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", p[i]);
  printf("\n");
}
int maxNum(int *p, int n)
{
  int maxn = 0;
  for (int i = 0; i < n; i++)
    if (p[i] > maxn)
      maxn = p[i];
  return maxn;
}

int main()
{

  srand(time(NULL));
  int n;
  scanf("%d", &n);

  int *a;

  // malloc
  allocate(&a, n);
  print(a, n);

  // RANDOM NUMBERS
  init(a, n);
  print(a, n);
  printf("\n");

  int maxn = maxNum(a, n);
  printf("max number: %d", maxn);

  free(a);
}
