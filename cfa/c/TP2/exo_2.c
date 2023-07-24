#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Lire_N()
{
    int choix;
    do
    {
        printf("Entrez la quantité d'enrtrées voulue pour le tableau: ");
        scanf("%d", &choix);
        if (choix < 1 || choix > 50)
            printf("La quantité doit être comprise entre 1 et 50!\n");
    } while (choix < 1 || choix > 50);

    return choix;
}

void Remplir_tableau(int choix, int *tableau)
{
    for (int compteur = 0; compteur < choix; compteur++)
    {
        printf("Entrez la valeur de la case %d: ", compteur + 1);
        scanf("%d", &tableau[compteur]);
    }
}

void Imprimer_tableau(int N, int *tableau)
{
    printf("\n\nAffichage du tableau:\n");
    for (int compteur = 0; compteur < N; compteur++)
        printf("%d ", tableau[compteur]);

    printf("\n");
}

int Tasser_tableau(int N, int *tableau)
{
    printf("\nLe tableau a initialement %d entrées.\n", N);
    // Indique de combien le tableau sera raccourci
    int quantite_zeros = 0;
    // Sert a déplacer les valeurs des cases
    int decalage = 0;

    // Calcul de la quantité de zeros dans le tableau
    for (int compteur = 0; compteur < N; compteur++)
    {
        if (tableau[compteur] == 0)
            quantite_zeros++;
    }
    printf("%d zéros ont été trouvés.\nLe tableau tassé sera de %d entrées.\n", quantite_zeros, N - quantite_zeros);

    // Décalage des valeurs en fonction de la quantité de zeros rencontrés
    for (int compteur = 0; compteur < N - quantite_zeros; compteur++)
    {
        while (tableau[compteur + decalage] == 0)
            decalage += 1;

        tableau[compteur] = tableau[compteur + decalage];
    }

    // Libération de la mémoire
    tableau = realloc(tableau, sizeof(int) * N - quantite_zeros);
    return quantite_zeros;
}

int main()
{
    int N = Lire_N();
    int *tableau = malloc(sizeof(int) * N);
    int quantite_zeros;
    Remplir_tableau(N, tableau);
    quantite_zeros = Tasser_tableau(N, tableau);
    Imprimer_tableau(N - quantite_zeros, tableau);
    return 0;
}