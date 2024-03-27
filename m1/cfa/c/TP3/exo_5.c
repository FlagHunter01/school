#include <stdio.h>

void exercice5(char *chaine)
{
    int compteur = 0;
    while (chaine[compteur] != '\0')
        compteur++;
    printf("Cette chaine contient %d caractères.\n", compteur);
}