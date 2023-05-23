#include <stdio.h>
#include <string.h>
#define MAX 2

typedef struct {
  char nombre[20];
  char apellido[20];
  int ranking;
  int titulos;
  // int edad; // comento ya que no es informacion relevante al ejercicio
  // int fortuna;
} jugador;

int main() {
  jugador tabla[MAX];
  int i = 0;

  // Mauricio Lopez 1 8
  // Leandro Romanut 2 1
  
  while (i < MAX) {
    printf("Ingresar nombre, apellido, ranking, y titulos: ");
    scanf("%s %s %d %d", tabla[i].nombre, tabla[i].apellido, &tabla[i].ranking, &tabla[i].titulos);
    i++;
  }
  
  FILE * f = fopen("./recursos/jugadores.txt", "wb+");
  fwrite(tabla, sizeof(jugador), i, f);
  
  // PROCESO INFORMACION LEIDA
  rewind(f); // retorno al inicio del archivo
  jugador aux;
  jugador mejorRanking;
  jugador masTitulos;

  fread(&aux, sizeof(jugador), 1, f);
  mejorRanking = aux;
  masTitulos = aux;

  while (!feof(f)) {
    fread(&aux, sizeof(jugador), 1, f);
    if (aux.ranking < mejorRanking.ranking) mejorRanking = aux;
    if (aux.titulos > masTitulos.titulos) masTitulos = aux;
  }

  // IMPRESION DE RESULTADOS
  printf("Jugador con mejor ranking: %s %s\n", masTitulos.nombre, masTitulos.apellido);
  printf("Jugador con mas titulos: %s %s\n", masTitulos.nombre, masTitulos.apellido);

  fclose(f);
  return 0;
}