#include <stdio.h>

int main()
{
    // Lecture des valeurs
    int a, b, min, max;
    printf("Entrez le premier entier positif: ");
    scanf("%d", &a);
    printf("Entrez le second entier positif: ");
    scanf("%d", &b);

    // Détermination de la plus grande et plus petite valeur
    if (a > b)
    {
        max = a;
        min = b;
    }
    else
    {
        max = b;
        min = a;
    }

    // Calcul du quotient
    int quotient = max / min;
    // Calcul du reste
    int reste = max % min;

    printf("\nRésultats:\n - Quotient: %d\n - Reste: %d\n", quotient, reste);

    return 0;
}