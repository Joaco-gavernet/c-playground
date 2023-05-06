// 11. Escriba un programa que lea desde teclado dos valores enteros n y m, y luego reserve memoria en
// forma dinámica para una matriz de enteros de n filas por m columnas. Inicialice la matriz creada con
// valores ingresados por teclado. Una vez inicializada, imprima las posiciones de todos aquellos valores
// múltiplos de 3. Por último, libere la memoria reservada.
// Nota: modularice la reserva de memoria, la inicialización, la impresión de las posiciones con valores
// múltiplo de 3 y la liberación de memoria.

#include <stdio.h>
#include <stdlib.h>

int **reservarMemoria(int m, int n) {
  int **fila = (int **) calloc(m, sizeof(int *));
  for (int i = 0; i < m; i++)
    fila[i] = (int *) calloc(n, sizeof(int));

  return fila;
}

void inicializarMatriz(int **matrix, int m, int n) {
  printf("\nLectura de matriz: \n");
  for (int i = 0; i < m; i++) {
    printf("Ingresar valores para la fila %d: ", i);
    for (int j = 0; j < n; j++)
    scanf("%d", &(matrix[i][j]));
  }
}

void imprimirMatriz(int **matrix, int m, int n) {
  for (int i = 0; i < m; i++) {
    printf("\n");
    for (int j = 0; j < n; j++)
      printf("%d ", matrix[i][j]);
  }
}

void imprimirPosMultiplosDe(int ** matrix, int m, int n, int x) {
  printf("Imprimir posiciones de los multiplos de %d: \n", x);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      if (matrix[i][j] % x == 0) printf("%d (fila = %d, columna = %d) \n", matrix[i][j], i + 1, j + 1);
  }
}

void liberarMemoria(int ** matrix, int m, int n) {
  for (int i = 0; i < m; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

int main() {
  int n, m;
  printf("Considerar que la matriz se interpreta de m*n arrancando desde fila 1 y columna 1\n");
  printf("Ingrese un numero entero de filas: ");
  scanf("%d", &m);
  printf("Ingrese un numero entero de columnas: ");
  scanf("%d", &n);

  int **matrix = reservarMemoria(m, n);
  imprimirMatriz(matrix, m, n);

  inicializarMatriz(matrix, m, n);
  imprimirMatriz(matrix, m, n);

  imprimirPosMultiplosDe(matrix, m, n, 3);
  liberarMemoria(matrix, m, n);

  return 0;
}