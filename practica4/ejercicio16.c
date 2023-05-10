// 16. Escriba un programa que permita conocer todos los divisores de un número entero n leído desde
// teclado. Los números deben almacenarse en un arreglo unidimensional. Como se desea optimizar el
// espacio a ocupar, la memoria debe reservarse a medida que se la va necesitando. Una vez que se
// almacenaron todos los divisores, imprímalos junto al número n. Por último, libere la memoria
// reservada.

#include <stdio.h>
#include <stdlib.h>

#define forn(i,n) for(int i=0;i<n;i++)

void buscarDivisores(int n, int ** divisores, int * dim) {
  if (n == 0) printf("0 no es divisible");
  else {
    for (int i = 1; i <= n/2; i++) {
      if (n % i == 0) {
        divisores[*dim] = (int *) malloc(sizeof(int));
        *divisores[(*dim)++] = i; // post incremento la dimension luego de actualizar el nuevo divisor
      }
    }
  }
}

void buscarDivisoresRealloc(int n, int * res, int * dim) {
  if (n == 0) printf("0 no es divisible");
  else {
    for (int i = 1; i <= n/2; i++) {
      if (n % i == 0) {
        realloc(res, *dim);
        res[(*dim)++] = i;
      }
    }
  }
  
}

void imprimirDivisores(int n, int ** divs, int dim) {
  printf("Imprimiendo divisores de %d", n);
  forn(i, dim) {
    printf("%d ", *divs[i]);
  }
}

void liberarDivisores(int ** divs, int * dim) {
  forn(i, *dim) {
    free(divs[i]);
  }
  *dim = 0;
}

int main() {
  int n;
  printf("Ingresar numero a buscar divisores: ");
  scanf("%d", &n);

  // implementacion con puntero a punteros
  int ** divisores;
  int dim = 0;
  buscarDivisores(n, divisores, &dim);
  imprimirDivisores(n, divisores, dim);
  liberarDivisores(divisores, &dim);

  // implementacion con realloc
  int * divisoresRealloc;
  int dimRealloc = 0;
  buscarDivisoresRealloc(n, divisoresRealloc, &dimRealloc);
  imprimirDivisoresRealloc(); // falta implementar y revisar funcionamientos
  free(divisoresRealloc);

  return 0;
}