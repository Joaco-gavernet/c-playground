#include <stdio.h>
#include <stdlib.h>
#define size 25

void imprimir(int * v, int size){
  int i;
  for (i=0; i < size; i++){
  printf("v[%d]= %d", i, v[i]);
  }
}

int main(){
  int v[size];
  imprimir(v, size);
  return 0;
}
