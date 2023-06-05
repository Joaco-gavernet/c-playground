#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
  if (argc < 2) {
    printf("Error\n");
    return -1;
  }

  float tot = 0;
  float prom;

  for (int i = 0; i < argc; i++) {
    printf("%2f\n", atoi(argv[i]));
    tot += atoi(argv[i]);
  }
  prom = tot / (argc - 1);

  printf("El promedio es: %f\n", prom);

  return 0;
}