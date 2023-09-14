#include <stdio.h>

int Max_2(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int Max_4(int a, int b, int c, int d)
{
    int max1 = Max_2(a, b);
    int max2 = Max_2(c, d);
    return Max_2(max1, max2);
}

int main()
{
    int a, b, c, d;
    printf("Entrez entier 1: ");
    scanf("%d", &a);
    printf("Entrez entier 2: ");
    scanf("%d", &b);
    printf("Entrez entier 3: ");
    scanf("%d", &c);
    printf("Entrez entier 4: ");
    scanf("%d", &d);

    printf("\nLe plus grand entier est %d.\n", Max_4(a, b, c, d));

    return 0;
}