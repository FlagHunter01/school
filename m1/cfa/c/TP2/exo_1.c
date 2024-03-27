#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    int N = Lire_N();
    int *tableau = malloc(sizeof(int) * N);
    Remplir_tableau(N, tableau);
    Imprimer_tableau(N, tableau);
    return 0;
}