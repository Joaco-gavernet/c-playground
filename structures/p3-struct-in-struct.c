#include <stdio.h>
#define DIM 2

typedef struct
{
  char calle[50];
  char ciudad[30];
  int codigo_postal;
  char pais[40];
} direccion;

struct alu
{
  char apellido[50];
  char nombre[50];
  char legajo[8];
  float promedio;
  direccion domicilio;
};
typedef struct alu alumno;

void initDomicilio(direccion *ubicacion)
{
  printf("read calle, ciudad, codigo_postal, & pais: \n");
  scanf("%s %s %d %s", ubicacion->calle, ubicacion->ciudad, &((*ubicacion).codigo_postal), ubicacion->pais);
}

void initAlumno(alumno *ingresante)
{
  printf("read apellido, nombre, legajo, & promedio: \n");
  scanf("%s %s", ingresante->apellido, ingresante->nombre);
  scanf("%s %f", &((*ingresante).legajo), &(ingresante->promedio));
  initDomicilio(&(*ingresante).domicilio);
}

void printAlumno(alumno A)
{
  printf("\nalumno: %s %s %s %f", A.apellido, A.nombre, A.legajo, A.promedio);
  printf("\ndomicilio: %s %s %s", A.domicilio.calle, A.domicilio.ciudad, A.domicilio.pais);
  printf(" %d", A.domicilio.codigo_postal);
}

int checkBestAvarege(alumno clase[], int diml)
{
  int i, best = 0;
  for (i = 0; i < diml; i++)
    if (clase[i].promedio > clase[best].promedio)
      best = i;
  return best;
}

int main()
{
  alumno clase[DIM];
  int i;

  for (i = 0; i < DIM; i++)
  {
    initAlumno(&(clase[i]));
  }

  for (i = 0; i < DIM; i++)
  {
    printAlumno(clase[i]);
  }

  int best = checkBestAvarege(clase, DIM);
  printf("\nmejor promedio %s %s", clase[best].nombre, clase[best].apellido);

  // TESTCASES
  // lopez maxi 032 4
  // 2 gonnet 1900 argentina
  // gavernet joaquin 036 8
  // 34 laplata 1900 argentina

  return 0;
}
