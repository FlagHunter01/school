#include <stdio.h>
#include <string.h>

int main()
{
    // Chaine entrée
    char chaine[50];
    // Clé qui sert a commencer l'affichage
    char cle;
    // position de la 1e occurence de la clé
    printf("Entrez la chaine: ");
    printf("Entrez le caractère clé: ");
    scanf(" %c", &cle);
    // POINTEUUUUUUUUR
    char * pointeur = strchr(chaine, cle);
    printf("\nLa chaine tronquée par %c est:\n%s\n", cle, pointeur);

    return 0;
}