#include <stdio.h>
#include <stdlib.h>

struct destino {
  int codProv;
  int codLoc;
  char nomLoc[30];
  int nHab;
};

int main() {
  FILE * f = fopen("Habitantes.txt", "r");
  FILE * n = fopen("Habitantes.dat", "wb+"); // recordar revisar el metodo de apertura del archivo
  if (f == NULL || n == NULL) {
    printf("No se pudo abrir el archivo");
    return -1;
  }
  
  struct destino * habitantes;
  struct destino aux;
  int diml = 0;

  while (fscanf(f, "%d %d %s %d", &aux.codProv, &aux.codLoc, aux.nomLoc, &aux.nHab) != EOF) {
    fwrite(&aux, sizeof(struct destino), 1, n); // actualizo .dat mientras proceso .txt
    diml++;
  }

  fclose(f);

  // proceso al finalizar
  rewind(n); // fseek(n, 0, SEEK_SET);
  habitantes = (struct destino *) calloc(diml, sizeof(struct destino));
  fread(habitantes, diml, sizeof(struct destino), n); // se recupera informacion del .dat en vector dinamico

  struct destino maxHab = habitantes[0]; // se inicializa el maximo en el primer elemento
  for (int i = 0; i < diml; i++) {
    if (habitantes[i].nHab > maxHab.nHab) {
      maxHab = habitantes[i];
    }
  }
  fclose(n); // recordar cerrar archivo cuando finaliza su uso

  printf("Localidad %s con codigo %d cuenta con la mayor cantidad de habitantes", maxHab.nomLoc, maxHab.codLoc);

  return 0;
}