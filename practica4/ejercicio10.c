// 10. Escriba un programa que lea un número entero n y luego reserve memoria en forma dinámica para
// un arreglo de n elementos double. Inicialice las posiciones del arreglo a partir de valores ingresados
// por teclado y a continuación imprima el promedio de todos ellos.
// a. Empleando notación de arreglos.
// b. Empleando notación de punteros.
// Por último, libere la memoria reservada.
// Nota: modularice la reserva de memoria, la inicialización, el cálculo del promedio y la liberación de
// memoria.

#include <stdio.h>
#include <stdlib.h>

double promedio(double *arr, int n)
{
  double total = 0;
  for (int i = 0; i < n; i++)
    total += arr[i]; // notacion de arreglo

  return total / n;
}

int main()
{

  int n;
  printf("Ingrese un numero entero: ");
  scanf("%d", &n);

  double *arr = (double *)calloc(n, sizeof(double));

  for (int i = 0; i < n; i++)
  {
    printf("Ingrese un numero real: ");
    scanf("%lf", arr + i); // notacion de puntero
  }

  printf("El promedio de los numeros ingresados es: %lf\n", promedio(arr, n));

  free(arr); // libero memoria reservada

  return 0;
}