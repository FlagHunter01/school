#include <stdio.h>

int main()
{
    // Affichage de la tête du tableau
    printf("Caractère\tDécimal\tHexadécimal\n");

    // Affichage des caratères
    for (int counter = 0; counter < 128; counter++)
        printf("%c\t\t%d\t%x\n", counter, counter, counter);

    return 0;
}