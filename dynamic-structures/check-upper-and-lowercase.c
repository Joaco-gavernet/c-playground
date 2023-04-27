#include <stdlib.h>
#include <stdio.h>

int minusc(char *input)
{
  int tot = 0;
  for (int i = 0; input[i] != '\0'; i++)
    if ((input[i] - 'a' >= 0) && (input[i] - 'a' <= 'z' - 'a'))
      tot++;
  return tot;
}

int mayusc(char *input)
{
  int tot = 0;
  for (int i = 0; input[i] != '\0'; i++)
    if ((input[i] - 'A' >= 0) && (input[i] - 'A' <= 'Z' - 'A'))
      tot++;
  return tot;
}

int main()
{
  char *aux = (char *)malloc(100 * sizeof(char));

  for (int i = 0; i < 1; i++)
  {
    gets(aux);
    printf("minusculas: %d \n", minusc(aux));
    printf("mayusculas: %d \n", mayusc(aux));
  }
}
