#include <stdio.h>

int main() {

    // reels qui servent au calcul
    float first_int, second_int;

    // Lecture (sans vérif) des valeurs
    printf("Entrer reel 1: ");
    scanf("%f", &first_int);
    printf("Entrer reel 2: ");
    scanf("%f", &second_int);

    // Calcul de la somme
    float result = first_int + second_int;

    // Affichage du résultat
    printf("La somme des deux entiers est: %f\n\n", result);
    
    return 0;
}