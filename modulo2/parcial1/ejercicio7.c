#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **reservar(int);
void inicializar(int**, int);
void imprimir(int**, int);
int **liberar(int**, int);

int main() {
  int n;
  scanf("%d", &n);
  int **M;
  M = reservar(n);
  inicializar(M, n);
  imprimir(M, n);
  M = liberar(M, n);
  return 0;
}

int **reservar(int n) {
  int **M = (int**) calloc(n, sizeof(int *));
  if (M == NULL) return NULL;
  for (int i = 0; i < n; i++) M[i] = (int *) calloc((i + 1), sizeof(int));
  return M;
}

void inicializar(int **M, int n) {
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) M[i][j] = (rand() % 21);
  }
}

void imprimir(int **M, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) printf("%2d ", M[i][j]);
    printf("\n");
  }
}

int **liberar(int **M, int n) {
  for (int i = 0; i < n; i++) free(M[i]);
  free(M);
  return NULL;
}
