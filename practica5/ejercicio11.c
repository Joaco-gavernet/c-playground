#include <stdio.h>

int main() {
  FILE * f = fopen("./recursos/jugadores.txt", "rb+");
  char aux; // utilizo variable para leer de a 1 byte
  int contadorBytes = 0;

  fread(&aux, sizeof(char), 1, f);
  while (!feof(f)) {
    contadorBytes++;
    fread(&aux, sizeof(char), 1, f);
  }
  
  printf("Cantidad de bytes: %d\n", contadorBytes);

  fclose(f);
  return 0;
}