#include <stdio.h>
#include <string.h>

#define forn(i, n) for(int i = 0; i < n; i++)
#define LONG 7

typedef struct {
  char dni[10];
  int posicionBytes;
} Persona;

int main() {
  FILE * origen = fopen("./recursos/personas2.csv", "r");
  FILE * destino = fopen("./recursos/personas.idx", "w");

  if (origen == NULL || destino == NULL) {
    printf("Error al abrir los archivos\n");
    return 1;
  }

  Persona tabla[LONG]; // vector de cadenas de caracteres (DNIs)
  int id = 0;
  char aux[100];
  int desplazamiento = 0;

  fscanf(origen, "%s", aux);
  printf("Desplazamiento %d\n", desplazamiento);

  while (!feof(origen)) {
    tabla[id].posicionBytes = desplazamiento;
    fscanf(origen, "%d%c", &id); // leo el numero y luego proceso el ";" que lo acompaña
    fscanf(origen, "%[^;]s", tabla[id].dni); // leo hasta el ";" y guardo en tabla[id].dni
    printf("ID %d: DNI %s\n", id, tabla[id].dni); // proceso el resto de la informacion para desplazar el puntero de fichero

    fscanf(origen, "%[^\n]s", aux);
  }

  for (int i = 1; i <= id; i++) fprintf(destino, "%d | %s\n", i, tabla[i]);

  fclose(origen);
  fclose(destino);
  return 0;
}