#include <stdio.h>
#include <stdlib.h>
#define LONG 300

int main(){
  FILE *f;
  char linea[LONG];
  
  // Abrir el archivo
  f = fopen("./recursos/prueba.txt", "r");
  if (f == NULL){
    printf ("\nError al abrir archivo fuente\n");
    return 1;
  }

  
  fgets(linea, LONG, f);
  while (!feof(f)){
    puts(linea);
    fgets(linea, LONG, f);
  }

  fclose(f);
  return 0;
}