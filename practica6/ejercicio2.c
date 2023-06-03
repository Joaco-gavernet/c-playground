#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
  if (argc != 4) {
    printf("Error en la cantidad de parametros\n");
    return -1;
  }

  int tot = 0;
  for (int i = 1; i < argc; i++) tot += atoi(argv[i]);
  printf("El promedio es %d\n", tot / (argc - 1));

  return 0;
}