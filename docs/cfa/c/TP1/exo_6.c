#include <stdio.h>
#include <limits.h>

int main()
{
    printf("Entrer 0 pour arrêter la boucle.\n\n");

    // Stocke la plus grande valeur
    int max = INT_MIN;

    // Stocke la plus petite valeur
    int min = INT_MAX;

    // Contient la dernière valeur lue
    int read = 0;

    // Lecture et comparaison
    do
    {
        printf("Entrer un entier: ");
        scanf("%d", &read);

        if (read > max)
        {
            max = read;
        }
        if (read < min)
        {
            min = read;
        }
    } while (read != 0);

    // Affichage final
    printf("\n - Le min est %d\n - Le max est %d\n", min, max);

    return 0;
}