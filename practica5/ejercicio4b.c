#include <stdlib.h>
#include <stdio.h>
#define LONG 300

typedef struct {
  int numero;
  float apostado;
} apuesta;

int main() {
  FILE * f = fopen("./recursos/apuestas.txt", "r");

  apuesta database[LONG];
  int i;
  float total = 0;

  do {
    fscanf(f, "%d|%f;", &(database[i].numero), &(database[i].apostado));
    total += database[i].apostado;
    i++;
  } while (!feof(f));

    printf("El monto total apostado es $%.2f", total);

  return 0;
}