#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE * f = fopen("./recursos/precipitaciones.txt", "r");
  int month[31];
  int mayor;

  fscanf(f, "%d", &month[0]);
  mayor = 0;
  for(int i = 1; i < 31; i++) {
    fscanf(f, "-%d", &month[i]);
    if (month[mayor] < month[i]) mayor = i;
  }

  printf("Dia de mayor precipitaciones %d con %d cm3", (mayor + 1), month[mayor]);

  return 0;
}