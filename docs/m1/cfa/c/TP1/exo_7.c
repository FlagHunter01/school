#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Drapeau de présence de diviseurs
    bool divisible = false;

    // Lecture de l'entier
    int entier;
    printf("Saisir l'entier positif: ");
    scanf("%d", &entier);

    // Recherche des diviseurs
    printf("\nLes diviseurs de %d sont:\n", entier);
    for (int counter = 2; counter < entier; counter++)
    {
        if (entier % counter == 0)
        {
            printf(" - %d\n", counter);
            divisible = true;
        }
    }

    // Message si pas de diviseurs
    if (!divisible)
        printf("Ben en fait y'en a pas mdr.\n");

    return 0;
}