
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
  if (argc != 4) {
    printf("Error en la cantidad de parametros\n");
    return -1;
  }

  char operation = *argv[2];
  int result = 0;

  switch (operation) {
  case '/':
    result = atoi(argv[1]) / atoi(argv[3]);
    break;
  case '*':
    result = atoi(argv[1]) * atoi(argv[3]);
    break;
  case '-':
    result = atoi(argv[1]) - atoi(argv[3]);
    break;
  case '+':
    result = atoi(argv[1]) + atoi(argv[3]);
    break;
  default:
    printf("Operacion invalida\n");
    break;
  }

  printf("El resultado es %d\n", result);

  return 0;
}