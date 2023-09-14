#include <stdio.h>

int main() {

    // entiers qui servent au calcul
    int first_int, second_int;

    // Lecture (sans vérif) des valeurs
    printf("Entrer entier 1: ");
    scanf("%d", &first_int);
    printf("Entrer entier 2: ");
    scanf("%d", &second_int);

    // Calcul de la somme
    int result = first_int + second_int;

    // Affichage du résultat
    printf("La somme des deux entiers est: %d\n\n", result);
    
    return 0;
}