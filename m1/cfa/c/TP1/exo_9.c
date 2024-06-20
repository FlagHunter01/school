#include <stdio.h>
#include <stdbool.h>

bool Est_pair(int nombre)
{
    if (nombre % 2)
        return false;
    else
        return true;
}

int Algo_recursif(int a, int b)
{
    int reste = 0;

    printf("%d * %d", a, b);

    while (b)
    {
        if (Est_pair(b))
        {
            a = 2 * a;
            b = b / 2;
        }
        else
        {
            b -= 1;
            reste += a;
        }
        printf("\t= %d * %d + %d\n", a, b, reste);
    }

    return reste;
}

int main()
{
    // Lecture des entiers
    int a, b;
    printf("Entrez l'entier positif A: ");
    scanf("%d", &a);
    printf("Entrez l'entier positif B: ");
    scanf("%d", &b);
    printf("\n");

    // Affichage du résultat
    printf("\n\nLe résultat de %d * %d est %d\n", a, b, Algo_recursif(a, b));

    return 0;
}