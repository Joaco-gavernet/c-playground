#include <stdlib.h>
#include <stdio.h>
#define LONG 300

int main() {
  FILE * f = fopen("./recursos/vinos.csv", "r");
  FILE * n = fopen("./recursos/reporte_vinos.txt", "a");
  float prom[8] = {0};
  int read = 0;
  float max[8] = {0};
  float min[8] = {LONG}; // inicializo en numero de elevada magnitud
  float actual[8];
  char word[LONG];

  fgets(word, LONG, f);
  while (!feof(f)) {
    for(int i = 0; i < 8; i++) {
      fscanf(f, "%f;", &actual[i]);
      if (actual[i] > max[i]) max[i] = actual[i];
      if (actual[i] < min[i]) min[i] = actual[i];
      prom[i] += actual[i];
    }
    read++;
    fscanf(f, "%s", &word);
    printf("Proceso %s\n", word); // marca de fin de procesamiento de vino
  }

  for(int i = 0; i < 8; i++) prom[i] /= read;

  fprintf(n, "Atributo  |\t Acidez Fija\t Acidez Volatil\t Acido Citrico\t Azucares Residuales\t PH   \t Sulfatos\t Alcohol\t Calidad\n");
  fprintf(n, "Promedio  |\t %.2f       \t %.2f          \t %.2f         \t %.2f               \t %.2f  \t %.2f    \t %.2f  \t %.2f  \n", prom[0], prom[1], prom[2], prom[3], prom[4], prom[5], prom[6], prom[7]);
  fprintf(n, "Maximos   |\t %.2f       \t %.2f          \t %.2f         \t %.2f               \t %.2f  \t %.2f    \t %.2f  \t %.2f  \n", max[0], max[1], max[2], max[3], max[4], max[5], max[6], max[7]);
  fprintf(n, "Minimos   |\t %.2f       \t %.2f          \t %.2f         \t %.2f               \t %.2f  \t %.2f    \t %.2f  \t %.2f  \n", min[0], min[1], min[2], min[3], min[4], min[5], min[6], min[7]);

  fclose(f);
  return 0;
}