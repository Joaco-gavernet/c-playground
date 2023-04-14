#include <stdio.h>
#include <stdlib.h>

typedef enum
{
  IZQUIERDA,
  CENTRO_H,
  DERECHA
} AlineacionHorizontal;
typedef enum
{
  ARRIBA = 1,
  CENTRO_V,
  ABAJO
} AlineacionVertical;
typedef enum
{
  DOS = 2,
  CERO = 0,
  UNO,
  MENOS_UNO = -1,
  OTRO
} Numeros;
// typedef enum { LET_A = "A", LET_B, LET_Z = "Z" } Letras;
typedef enum
{
  LETRA_A = 'A',
  LETRA_B,
  LETRA_Z = 'Z'
} Letras2;
typedef enum
{
  LUNES,
  MARTES,
  MIERCOLES,
  JUEVES,
  VIERNES,
  SABADO,
  DOMINGO
} Semana;

int main()
{
  printf("AlineacionHorizontal: %d\n", IZQUIERDA);
  printf("AlineacionVertical: %d\n", ARRIBA);
  printf("Numeros: %d\n", OTRO);
  //    printf("Letras: %c", LET_A); // un enum no puede recibir punteros a cadena de caracteres, solo constantes
  printf("Letras2: %c\n", LETRA_B);

  return 0;
}
