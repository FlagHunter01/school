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

int Calculer_somme(int N, int *tableau)
{
    int *pointeur = tableau;
    int somme = 0;
    for (int compteur = 0; compteur < N; compteur++)
    {
        somme += *pointeur;
        pointeur += 1; // et non sizeof(int) car les cases mémoire sont "collées" quand attribuées à un type
        printf("%d\n", somme);
    }
    return somme;
}

int main()
{
    int N = Lire_N();
    int *tableau = malloc(sizeof(int) * N);
    Remplir_tableau(N, tableau);
    printf("La somme des éléments du tableau est : %d.\n", Calculer_somme(N, tableau));
    return 0;
}