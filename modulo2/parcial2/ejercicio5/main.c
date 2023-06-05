#include <stdio.h>

int main() {
  char input[200];
  char x;

  gets(input);
  scanf("%c", &x);

  FILE * f = fopen(input, "r");
  FILE * n = fopen("resultado.txt", "wb");

  if (f == NULL || n == NULL) {
    printf("Error al abrir el archivo\n");
    return -1;
  }

  char act;

  act = fgetc(f);
  while (act != EOF) {
    printf("Desplazamiento actual: %d\n", ftell(f));
    if (act == x) {
      printf("Se encontro el caracter %c\n", act);
      fwrite(f, sizeof(ftell(f)), 1, n);
    }
    act = fgetc(f);
  }

  fseek(n, 0, SEEK_SET);

  // read and print positions saved in file resultado.txt
  int pos;
  fread(&pos, sizeof(pos), 1, n);
  while (!feof(n)) {
    printf("Posicion: %d\n", pos);
    fread(&pos, sizeof(pos), 1, n);
  }

  fclose(f);
  fclose(n);
  return 0;
}