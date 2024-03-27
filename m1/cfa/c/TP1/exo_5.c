#include <stdio.h>

int main()
{
    // Lecture des 3 entiers
    int a, b, c;
    printf("Saisissez le premier entier: ");
    scanf("%d", &a);
    printf("Saisissez le deuxième entier: ");
    scanf("%d", &b);
    printf("Saisissez le troisième entier: ");
    scanf("%d", &c);

    // Comparaison des entiers
    int max;
    if (a > b)
    {
        max = a;
    }
    else
    {
        max = b;
    }
    if (c > max) {
        max = c;
    }

    // Affichage

    printf("\nLe plus grand entier est: %d.\n", max);
    return 0;
}

