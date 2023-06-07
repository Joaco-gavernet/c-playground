#include <stdio.h>
#include <stdlib.h>
#define LONG 300

int main(){
  FILE *f;
  int actual;

  int may = 0;
  int min = 0;
  int nums = 0;
  
  // Abrir el archivo
  f = fopen("./recursos/prueba2.txt", "r");
  if (f == NULL){
    printf ("\nError al abrir archivo fuente\n");
    return 1;
  }

  while ((actual = fgetc(f)) != EOF){
    printf("imprimo caracter leido: %c\n", actual);
    if ((actual - 65 >= 0) && (actual - 91 < 0)) may++;
    else if ((actual - 97 >= 0) && (actual - 123 < 0)) min++;
    else if ((actual - 48 >= 0) && (actual - 58 < 0)) nums++;
  }

  printf("Mayusculas: %d \nMinusculas: %d \nNumeros: %d", may, min, nums);

  fclose(f);
  return 0;
}