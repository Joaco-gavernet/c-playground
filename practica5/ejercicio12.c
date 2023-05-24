#include <stdio.h>
#define forn(i, n) for(int i = 0; i < n; i++)
#define LONG 7

int main() {
  FILE * origen = fopen("./recursos/personas2.csv", "r");
  FILE * destino = fopen("./recursos/personas.idx", "w");

  int tabla[LONG] = {0}; // vector de cadenas de caracteres (DNIs)
  int id = 0;
  char example[100];

  fscanf(origen, "%s", example);
  printf("Ultimo leido en .csv %s\n", example);

  while (!feof(origen)) {
    fscanf(origen, "%d;", &id);
    fscanf(origen, "%d;", &tabla[id]);
    printf("ID %d: DNI %d\n", id, tabla[id]);

    fscanf(origen, "%[^\n]s", example);
    printf("Ultimo leido en .csv %s\n", example);
  }

  for (int i = 1; i <= id; i++) fprintf(destino, "%d | %d\n", i, tabla[i]);
  
  fclose(origen);
  fclose(destino);
  return 0;
}