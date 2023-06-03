// 15. Escriba un programa que, dado un número entero n ingresado por
// teclado, construya una pirámide de pascal de n filas. Un triángulo de
// pascal es una serie de filas apiladas que comienza con un elemento y
// agrega un elemento más en cada fila. El primer y último elemento de
// cada fila es un 1. Los demás elementos se calculan sumando los 2
// números superiores de la fila anterior. Por ejemplo, para obtener el
// segundo elemento de la cuarta fila (4) deben sumarse el primer (1) y
// segundo (3) elemento de la tercera fila de forma que 1+3 = 4. Tenga en
// cuenta las siguientes condiciones:
// a) Utilizar una estructura de datos eficiente. Contemple la información necesaria para recorrer
// la pirámide y liberar la memoria de forma correcta.
// b) Implemente una función que dado un entero n retorne una pirámide de pascal de n filas.
// c) Implemente una función para imprimir la pirámide.
// d) Implemente una función para destruir la pirámide.

#include <stdio.h>
#include <stdlib.h>

#define forn(i,n) for(int i=0;i<n;i++)

int ** reservarMemoria(int n) {
  int ** result = (int **) calloc(n, sizeof(int *));
  forn(i, n) {
    result[i] = (int *) calloc(i + 1, sizeof(int));
  }
  return result;
}

void imprimirPiramide(int ** p, int n) {
  // print Pascal Pyraminx stored in variable and of n rows without segmentation fault occurring
  forn(i, n) {
    forn(j, i + 1) {
      printf("%2d ", p[i][j]);
    }
    printf("\n");
  }
}

void armarPiramide(int ** p, int n) {
  forn(i, n) {
    forn(j, i+1) {
      if ((j == 0) || (j == i)) p[i][j] = 1;
      else p[i][j] = p[i-1][j-1] + p[i-1][j];
    }
  }
}

void destruirPiramide(int ** p, int n) {
  forn(i, n) free(p[i]);
}

int main() {
  int n;
  printf("Ingresar cantidad de filas: ");
  scanf("%d", &n);

  int ** pyraminx; // puntero al primer elemento
  pyraminx = reservarMemoria(n);
  imprimirPiramide(pyraminx, n);

  armarPiramide(pyraminx, n);
  imprimirPiramide(pyraminx, n);
  destruirPiramide(pyraminx, n);

  return 0;
}