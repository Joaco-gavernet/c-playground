#include <stdio.h>
#include <string.h>

int checkWord(char *word) {
  FILE * f = fopen("./recursos/diccionario.txt", "r");
  int result = 0;
  char actual[20];
  
  do {
    fscanf(f, "%s", actual);
    printf("palabra leida: %s\n", actual);
  } while (!feof(f) && (strcmp(word, actual) > 0));

  if (strcmp(word, actual) == 0) result = 1;
  fclose(f);
  return result;
}

int main() {
  char word[20];

  do {
    scanf("%s", word);
    printf("Esta en el diccionario: %d\n", checkWord(word));
  } while (strcmp(word, "ZZZ") != 0);

  return 0;
}