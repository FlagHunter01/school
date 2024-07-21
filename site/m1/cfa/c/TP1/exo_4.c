#include <stdio.h>

int main() {
    // Lecture de l'entier
    int entier;
    printf("Saisir l'entier: ");
    scanf("%d", &entier);

    // Vérification de la parité
    if (entier % 2) {
        printf("\nL'entier est impair.");
    }
    else {
        printf("\nL'entier est pair.");
    }
    
    return 0;
}