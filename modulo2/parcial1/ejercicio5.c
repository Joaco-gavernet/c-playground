#include <stdio.h>

struct destino {
  int codProv;
  int codLoc;
  char nomLoc[30];
  int nHab;
};

int main() {
  FILE * f = fopen("Habitantes.txt", "r");
  FILE * n = fopen("Habitantes.dat", "w");
  if (f == NULL || n == NULL) {
    printf("No se pudo abrir el archivo");
    return -1;
  }

  struct destino act, max;
  fscanf(f, "%d %d %s %d", &act.codProv, &act.codLoc, act.nomLoc, &act.nHab);
  max.nHab = 0;

  while (!feof(f)) {
    fwrite(&act, sizeof(struct destino), 1, n);
    if (act.nHab > max.nHab) max = act;
    fscanf(f, "%d %d %s %d", &act.codProv, &act.codLoc, act.nomLoc, &act.nHab);
  }

  printf("Mayor n habitantes en localidad %d %s", max.codLoc, max.nomLoc);

  fclose(f);
  fclose(n);
  return 0;
}