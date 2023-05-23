#include <stdio.h>
#include <string.h>
#define MAX 2
#define forn(i,n) for(int i = 0; i < n; i++)

typedef struct {
  char nombre[20];
  char apellido[20];
  int ranking;
  int titulos;
  // int edad; // comento ya que no es informacion relevante al ejercicio
  // int fortuna;
} jugador;

int actualizarRanking(FILE * f, char nombre[20], char apellido[20], int ranking) {
  jugador tabla[MAX];
  fread(tabla, sizeof(jugador), MAX, f);

  int i = 0;
  while (strcmp(tabla[i].nombre, nombre) && strcmp(tabla[i].apellido, apellido) && (i < MAX)) i++;
  
  if (i < MAX) {
    printf("Actualizando en %d\n", i);
    tabla[i].ranking = ranking;
    rewind(f);
    fwrite(tabla, sizeof(jugador), MAX, f);

    // verificacion
    fseek(f, 0, SEEK_SET); // retorno al inicio del archivo
    fread(tabla, sizeof(jugador), MAX, f);
    forn(i, MAX) 
      printf("Imprimo para verificar: %s %s %d %d\n", tabla[i].nombre, tabla[i].apellido, tabla[i].ranking, tabla[i].titulos);
    return 1;
  } else return 0;
}

int main() {
  FILE * f = fopen("./recursos/jugadores.txt", "rb+");
  fseek(f, 0, SEEK_SET); // retorno al inicio del archivo

  char nombre[20];
  char apellido[20];
  int ranking;
  
  printf("Ingrese nombre, apellido, y nuevo ranking del jugador: ");
  scanf("%s", nombre);
  while (strcmp(nombre, "ZZZ")) {
    scanf("%s %d", apellido, &ranking);
    if (actualizarRanking(f, nombre, apellido, ranking)) printf("Ranking actualizado con exito\n");
    else printf("No se encontro el jugador\n");

    printf("Ingrese nombre, apellido, y nuevo ranking del jugador: ");
    scanf("%s", nombre);
  }
  printf("Fin de ingreso de datos\n");

  // PROCESO INFORMACION LEIDA
  fseek(f, 0, SEEK_SET); // retorno al inicio del archivo
  jugador tabla[MAX];
  fread(tabla, sizeof(jugador), MAX, f);
  forn(i, MAX) 
    printf("Imprimo jugador leido en binario: %s %s %d %d\n", tabla[i].nombre, tabla[i].apellido, tabla[i].ranking, tabla[i].titulos);

  fclose(f);
  return 0;
}