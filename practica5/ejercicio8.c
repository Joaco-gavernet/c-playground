#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char * enteroEnPalabra(int n) {
  char * result = (char *) malloc(20 * sizeof(char));

  switch (n) {
  case 0:
    strcpy(result, "cero");
    break;
  case 1:
    strcpy(result, "uno");
    break;
  case 2:
    strcpy(result, "dos");
    break;
  case 3:
    strcpy(result, "tres");
    break;
  case 4:
    strcpy(result, "cuatro");
    break;
  case 5:
    strcpy(result, "cinco");
    break;
  case 6:
    strcpy(result, "seis");
    break;
  case 7:
    strcpy(result, "siete");
    break;
  case 8:
    strcpy(result, "ocho");
    break;
  case 9:
    strcpy(result, "nueve");
    break;
  default:
    strcpy(result, "indefinido");
    break;
  }

  return result;
}

int enteroEnBinario(int n) {
  int result = 0;
  int i = 0;

  while (n > 0) {
    result += (n % 2) * pow(10, i++);
    n /= 2;
  }

  return result;
}

int main() {
  FILE * words = fopen("./recursos/numeros.txt", "w");
  FILE * binary = fopen("./recursos/numeros.dat", "w");

  if (words == NULL || binary == NULL) {
    printf("Error al abrir los archivos\n");
    return -1;
  }

  int n;
  char * palabra;
  int binario;

  printf("Ingrese numero entero (-1 para terminar): ");
  scanf("%d", &n);
  palabra = enteroEnPalabra(n);
  binario = enteroEnBinario(n);
  printf("El numero leido es el %s y en binario es %d\n", palabra, binario);

  while (n != -1) {
    fprintf(words, "%s\n", palabra);
    fprintf(binary, "%d\n", binario);

    printf("Ingrese numero entero (-1 para terminar): ");
    scanf("%d", &n);
    palabra = enteroEnPalabra(n);
    binario = enteroEnBinario(n);
    printf("El numero leido es el %s y en binario es %d\n", palabra, binario);
  }

  free(palabra);
  fclose(words);
  fclose(binary);
  return 0;
}