#include <stdio.h>

int main() {

    // entiers renseignés par le client
    int first_int, second_int;

    // Entier de transition
    int transition_int;

    // Lecture (sans vérif) des valeurs
    printf("Entrer entier 1: ");
    scanf("%d", &first_int);
    printf("Entrer entier 2: ");
    scanf("%d", &second_int);

    // Affichage avant permutationrintf("La somme des deux entiers est: %d\n\n", result);
    printf("\nPremier entier: %d\nSecond entier: %d\n\nPermutation ...", first_int, second_int);

    // permutation
    transition_int = first_int;
    first_int = second_int;
    second_int = transition_int;

    // Affichage après permutation
    printf("\nPremier entier: %d\nSecond entier: %d\n\n", first_int, second_int);
    
    return 0;
}