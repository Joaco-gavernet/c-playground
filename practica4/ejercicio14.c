// En álgebra lineal, una matriz triangular es un tipo especial de matriz cuadrada cuyos elementos por
// encima o por debajo de su diagonal principal son cero. Una matriz cuadrada de orden n se dice que es
// triangular inferior si es de la forma:
// Escriba un programa que lea desde teclado un valor entero n y reserve memoria para una matriz
// triangular inferior de orden n de enteros. Como se desea ahorrar espacio de almacenamiento, no se
// deben almacenar los elementos cuyo valor es 0, es decir, sólo se reservará memoria para los valores
// del triángulo inferior de la matriz. Luego, inicialice la estructura con valores aleatorios entre 0 y 20
// e imprímala en pantalla. Por último, libere la memoria reservada.
// Nota: modularice la reserva de memoria, la inicialización, la impresión y la liberación de memoria.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define forn(i,n) for(int i=0;i<n;i++)

// 1 2 3 0 x
// 4 5 6 0 x
// 7 8 9 0 x
// 0 0 0 0 x
// x x x x x

// 1  -> n = 1
// 4  -> n = 1 + 2
// 9  -> n = 1 + 2 + 3
// 16 -> n = 1 + 2 + 3 + 4
// 25 -> n = 1 + 2 + 3 + 4 + 5
// 36 -> n = 1 + 2 + 3 + 4 + 5 + 6


int * reservarMemoria(int n) {
  int tot = 0;
  for (int i = 1; i <= n; i++) tot += i;

  int * result = (int *) calloc(tot, sizeof(int));
  return result;
}

void inicializarRandom(int * matrix, int n, int lower, int upper) {
  int tot = 0;
  for (int i = 1; i <= n; i++) tot += i;
  forn(i, tot)  matrix[i] = lower + rand() % upper;
}

void imprimirMatrizTriangular(int * matrix, int n) {
  int print = 0;
  int printed = 0;
  int elements = (n * n);

  int tot = 0;
  for (int i = 1; i <= n; i++) tot += i;

  forn(i, tot) {
    printf("%2d ", matrix[i]);
    if (i - printed == print) { 
      forn(j, n - (print + 1)) printf(" x ");
      printf("\n");
      print++;
      printed += print;
    }
  }
}

int main() {
  srand(time(NULL));
  int n;
  printf("Ingresar valor de orden: ");
  scanf("%d", &n);

  int *matrix;

  matrix = reservarMemoria(n);
  inicializarRandom(matrix, n, 0, 20);

  imprimirMatrizTriangular(matrix, n);

  return 0;
}