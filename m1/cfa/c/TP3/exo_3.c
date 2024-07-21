#include <stdio.h>

// Valeur des cellules de RAM non utilisées
#define no_display -1

void Recursif(int nombre, int *ram)
{
    // Position de la fonction dans la RAM
    int position = 9 - nombre;

    // Valeur la plus petite à afficher
    int min;

    // Si la fonction n'est pas la première de la RAM (N = 9)
    // et n'est pas la première instance (la cellule précédente n'est pas utilisée)
    if (position && (ram[position - 1] != no_display))
    {
        // La valeur minimale = précédente + 1
        min = ram[position - 1] + 1;
    }
    else
    {
        // On est la première instance donc on commence à 0
        min = 0;
    }

    // Pour chaque valeur entre min et 9
    for (int compteur = min; compteur < 10; compteur++)
    {
        // On incrémente notre propre valeur
        ram[position] = compteur;

        // Si on n'est pas en dernière position, on lance la récursivité
        if (position < 8)
        {
            Recursif(nombre - 1, ram);
        }
        // Sinon on affiche tout nous mêmes
        else
        {
            for (int compteur_ram = 0; compteur_ram <= position; compteur_ram++)
            {
                if (ram[compteur_ram] != no_display)
                {
                    printf("%d", ram[compteur_ram]);
                }
            }
            printf("\n");
        }
    }
}

void exercie3()
{
    int nombre;
    int ram[9] = {no_display, no_display, no_display, no_display, no_display, no_display, no_display, no_display, no_display};
    printf("Entrez le nombre de chiffres (1 - 9): ");
    scanf("%d", &nombre);
    printf("\n");

    Recursif(nombre, ram);
    printf("\n");
}