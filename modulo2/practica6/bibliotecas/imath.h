// 9. Implemente la biblioteca imath.h, la cual contiene funciones matemáticas para enteros. La misma debe
// contener las siguientes funciones:
// a. int potencia(int x, int y) – Eleva x a la y-ésima potencia.
// b. int cuadrado(int x) – Eleva x al cuadrado.
// c. int cubo(int x) – Eleva x al cubo.
// d. int absoluto(int i) – Retorna el valor absoluto entero de i.
// e. int factorial (int i) – Retorna el factorial de i.
// f. int sumatoria (int i) – Retorna la sumatoria de 0 hasta i.
// g. int multiplo (int x, int y) – Retorna 1 si y es divisor de x, 0 en otro
// caso.
// h. int divisor (int x, int y) – Retorna 1 si y es múltiplo de x, 0 en otro
// caso.
// i. int par (int i) – Retorna 1 si i es par, 0 en otro caso.
// j. int impar (int i) – Retorna 1 si i es impar, 0 en otro caso.
// Una vez implementadas todas las funciones de biblioteca, escriba un programa que lea números enteros e
// imprima el cuadrado y el cubo de aquellos números que son pares y el factorial de aquellos que son
// impares. La lectura finaliza con el ingreso del 0.


#define forn(i, n) for(int i = 0; i < n; i++)

int potencia(int x, int y) {
  int result = x;
  forn(i, y) result *= x;
  return result;
}
int cuadrado(int x) { return (x * x); }
int cubo(int x) { return (x * x * x); }
int absoluto(int i) { return (i > 0) ? i : -i; }
int factorial(int i) { 
  int result = 1; 
  for(int j = 1; j <= i; j++) result *= j;
  return result;
}
int sumatoria(int i) {
  int result = 0; 
  for(int j = 0; j <= i; j++) result += j;
  return result;
}
int multiplo(int x, int y) { return (x % y) ? 0 : 1; }
int divisor(int x, int y) { return (y % x) ? 0 : 1; }
int par(int x) { return (x % 2) ? 0 : 1; }
int impar(int x) { return (x % 2) ? 1 : 0; }