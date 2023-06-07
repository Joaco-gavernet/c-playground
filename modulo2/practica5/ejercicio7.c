#include <stdio.h>
#define LONG 300

void copiarGetC(FILE * original, FILE * copia) {
  char c;

  while ((c = fgetc(original)) != EOF) {
    fputc(c, copia);
  }
  printf("Copia realizada correctamente\n");
}

void copiarGetS(FILE * original, FILE * copia) {
  char cadena[LONG];
  
  while (fgets(cadena, LONG, original) != NULL) {
    fputs(cadena, copia);
  }

  printf("Copia realizada correctamente\n");
}

void copiarRead(FILE * original, FILE * copia) {
  unsigned int n;

  while(fread(&n, sizeof(char), 1, original) != 0) {
    fwrite(&n, sizeof(char), 1, copia);
  }

  printf("Copia realizada correctamente\n");
}

int main() {
  FILE * original = fopen("./recursos/original.txt", "r");
  FILE * copia = fopen("./recursos/copia.txt", "w");

  if (original == NULL || copia == NULL) {
    printf("Error al abrir los archivos\n");
    return -1;
  }

  // funciones de copia utilizando: 
  // 1) fgetc + fputc
  // 2) fgets + fputs
  // 3) fread + fwrite

  copiarGetC(original, copia); // 1)
  copiarGetS(original, copia); // 2)
  copiarRead(original, copia); // 3)

  fclose(original);
  fclose(copia);
  return 0;
}