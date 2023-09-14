#include <stdio.h>

int Puissance(int nombre, int indice)
{
    if (indice)
        return nombre * Puissance(nombre, indice - 1);
    else
        return 1;
}

int Char_to_int(char caractere)
{
    int nombre = caractere - '0';
    return nombre;
}

void bonus(char *chaine)
{
    // Calcul de la longueur
    int longueur = 0;
    while (chaine[longueur] != '\0')
        longueur++;

    // Traduction en valeur numérique
    int somme = 0;
    for (int compteur = 0; compteur < longueur; compteur++)
    {
        somme += Char_to_int(chaine[compteur]) * Puissance(10, longueur - compteur - 1);
    }
    printf("\nLe nombre entré est %d.\n", somme);
}
