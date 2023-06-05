#include <stdio.h>
#include <stdlib.h>

typedef int** Piramide;

Piramide crear_piramide(int);
void inicializar(Piramide, int);
void imprimir(Piramide, int);
void liberar_piramide(Piramide, int);

int main() {
  Piramide p;
  int n = 5;

  p = crear_piramide(n);
  inicializar(p, n);
  imprimir(p, n);
  liberar_piramide(p, n);

  return 0;
}

Piramide crear_piramide(int n) {
  Piramide p = (Piramide) calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++) {
    p[i] = (int*) calloc(i + 1, sizeof(int));
  }

  return p;
}

void liberar_piramide(Piramide p, int n) {
  for (int i = 0; i < n; i++) free(p[i]);
  free(p);
}

void inicializar(Piramide p, int n) {
  for (int i = 0; i < n; i++) {
    p[i][0] = 1;
    p[i][i] = 1;
  }

  for (int i = 2; i < n; i++) {
    for (int j = 1; j < i; j++) {
      p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
    }
  }
}

void imprimir(Piramide p, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) printf("%d ", p[i][j]);
    printf("\n");
  }
}