#include <stdio.h>
#include <stdlib.h>

void inicializarMatriz(int *matrix, int m, int n) {
  for (int i = 0; i < m; i++) {
    printf("Ingresar valores para la fila %d: ", i);
    for (int j = 0; j < n; j++)
      scanf("%d", &(matrix[i * m + j]));
  }
}

void imprimirMatriz(int *matrix, int m, int n) {
  for (int i = 0; i < m; i++) {
    printf("\n");
    for (int j = 0; j < n; j++)
      printf("%d ", matrix[i * m + j]);
  }
}

int main() {
  int x = 2, y = 3;
  int * matrix = (int*) malloc(x*y*sizeof(int));
  inicializarMatriz(matrix, x, y);
  imprimirMatriz(matrix, x, y);
  free(matrix);
  return 0;
}