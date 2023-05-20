// error en el intento de hacer un arreglo dinamico

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int numero;
  float apostado;
} apuesta;

int main() {
  FILE * f = fopen("./recursos/apuestas.txt", "r");
  float total = 0;

  apuesta * database;
  int diml = 0;

  do {
    database = (apuesta *) realloc(database, (diml + 1) * sizeof(apuesta));
    fscanf(f, "%d|%f;", &(database[diml].numero), &(database[diml].apostado));
    total += database[diml].apostado;
    diml++;
  } while (!feof(f));

  printf("El monto total apostado es $%d", total);

  return 0;
}