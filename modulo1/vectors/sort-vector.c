#include <stdio.h>
#define forn(i, n) for (i = 0; i < n; i++)
#define dim 15

void initVector(int *, int);
void orderVector(int *, int);
void printVector(int *, int);

// check how does laura manages vectors dimension with functions

int main()
{
  int vec[dim] = {};

  initVector(vec, dim);
  printVector(vec, dim);

  orderVector(vec, dim);

  return 0;
}

void initVector(int *vec, int l)
{
  int i;
  forn(i, l) vec[i] = 1 + rand() % 100;
}

void orderVector(int *vec, int l)
{
  int i = 1, j, tmp;

  while (i < l)
  {
    while ((i < l) && (vec[i - 1] <= vec[i]))
      i++;

    if (vec[i - 1] > vec[i])
    {
      tmp = vec[i];
      j = i;

      while ((vec[j - 1] > tmp) && j)
      { // check that vector doesn't ends and is worth displacing
        vec[j] = vec[j - 1];
        j--;
      }
      vec[j] = tmp;
    }
  }

  printf("\n");
  printVector(vec, l);
}

void printVector(int *vec, int l)
{
  int i;
  forn(i, l) printf("%2d ", vec[i]);
}
