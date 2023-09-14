#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// TODO: a finir

typedef struct Voiture
{
    char marque[50];
    char couleur[30];
    int annee;
    int kilometrage;
} Voiture;

void peupler_tableau(Voiture *tableau);
void afficher_produits(Voiture voiture);

int main()
{
    Voiture *tableau = malloc(sizeof(Voiture) * 3);
    peupler_tableau(tableau);
    for (int compteur = 0; compteur < 3; compteur++)
    {
        afficher_produits(tableau[compteur]);
    }
}

