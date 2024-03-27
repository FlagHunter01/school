#include <stdio.h>

int Somme (int a, int b){
    return a + b;
}

int main() {
    int a, b;
    printf("Entrez le premier entier: ");
    scanf("%d", &a);
    printf("Entrez le deuxième entier: ");
    scanf("%d", &b);

    printf("\nLa somme est %d.\n", Somme(a, b));

    return 0;
}