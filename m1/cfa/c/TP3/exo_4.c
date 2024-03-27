#include <stdio.h>

void exercice4(char *string)
{
    int compteur = 0;
    while (string[compteur] != '\0')
    {
        putchar(string[compteur]);
        compteur++;
    }
    putchar('\n');
}