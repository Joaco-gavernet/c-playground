#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 1
#define DIM 5

#define forn(i,n) for(int i = 0; i < n; i++)

int buscarX(int x, int arr[], int dim) {
  int i = 0;
  while (arr[i] != x && i < dim) i++; // busco x en arr
  return (i < DIM) ? i : -1;
}

int main(){
  srand(time(NULL));
  int arr[DIM];
  forn(i, DIM) arr[i] = rand() % 10 + 1; // inicializo arr con valores aleatorios
  
  printf("arr[] = "); // imprimo array
  forn(i, DIM) printf("%d ", arr[i]); // imprimo array
  int x = 1;
  int result = buscarX(x, arr, DIM);

  printf("Posicion de %d en arr: %d\n", x, result);

  #if DEBUG
    printf("Cantidad de elementos procesados %d", (result > 0) ? result + 1 : DIM);
  #endif

  return 0;
}