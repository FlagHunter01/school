#include <stdio.h>
#include <string.h>

void Copie(char * a, char * b){
    int compteur = 0;
    while (a[compteur] != '\0'){
        b[compteur] = a[compteur];
        compteur ++;
    }
    b[compteur + 1] = '\0';
}

int main()
{
    // Premiere chaine entrée par l'utilisateur
    char premiere[50];
    // Seconde chaine entrée par l'utilisateur
    char seconde[50];
    // Buffer qui sert a l'échange de string
    char buffer[50];;

    printf("Premiere chaine (50 max): ");
    scanf("%s", premiere);
    printf("Seconde chaine (50 max): ");
    scanf("%s", seconde);

    // Permutation sans strcpy
    printf("\nPermutation sans strcpy:\n");
    Copie(premiere, buffer);
    Copie(seconde, premiere);
    Copie(buffer, seconde);
    printf(premiere);
    printf("\n");
    printf(seconde);

    // Permutation avec strcpy
    printf("\nPermutation avec strcpy:\n");
    strcpy(buffer, seconde);
    strcpy(seconde, premiere);
    strcpy(premiere, buffer);
    printf(premiere);
    printf("\n");
    printf(seconde);
    printf("\n");
}