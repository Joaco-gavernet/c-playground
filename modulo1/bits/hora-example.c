#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DIM 4
#define forn(i, n) for (i = 0; i < n; i++)

struct thorario
{
    unsigned int hora : 5;
    unsigned int minuto : 6;
    unsigned int segundo : 5;
};
typedef struct thorario horario;

void printHora(horario input)
{
    printf("horario: %2d:%2d:%2d \n", input.hora, input.minuto, input.segundo);
}

void readHora(horario *ahora)
{
    int aux;
    printf("Ingrese la hora [0, 24): ");
    scanf("%d", &aux);
    ahora->hora = aux;
    printf("Ingrese minutos [0, 60): ");
    scanf("%d", &aux);
    ahora->minuto = aux;
    printf("Ingrese segundos [0, 60): ");
    scanf("%d", &aux);
    ahora->segundo = aux;
}

int main()
{
    horario ahora = {12, 14, 30}; // horas, minutos, segundos
    printHora(ahora);

    readHora(&ahora);
    printHora(ahora);

    return 0;
}
