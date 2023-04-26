#include <stdlib.h>
#include <stdio.h>

void f(int *p);

int main()
{

  int *ptr = NULL;
  f(&ptr);

  if (ptr == NULL)
    printf("es NULL");
  else
    printf("NO es NULL");

  return 0;
}

void f(int *p)
{
  *p = (int *)malloc(10 * sizeof(int));
}
