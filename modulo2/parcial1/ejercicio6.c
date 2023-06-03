#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]) {
  if (argc < 2) {
    printf("Argumentos insuficientes");
    return -1;
  }

  int i;
  char result[200] = "";
  for (i = 1; i < argc; i++) {
    strcat(result, argv[i]);
    strcat(result, " ");
  }

  puts(result);
  return 0;
}