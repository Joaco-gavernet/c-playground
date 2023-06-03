#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

int main(){
  int x= 15;

  while (x<50){
    #ifdef DEBUG
      printf("x= %d", x);
      y = y+1; // no tiene mucho sentido esta linea
    #endif
    x++;
  }
  
  return 0;
}