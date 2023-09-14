#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Lit l'imput de l'user
int Lire_user(char *chaine, int longueur)
{
    char *position_entree = NULL;
    // Si l'entrée n'est pas vide (erreur de lecture)
    if (fgets(chaine, longueur, stdin) != NULL)
    {
        // On remplace le retour à la ligne par la fin de chaine
        position_entree = strchr(chaine, '\n');
        if (position_entree != NULL)
        {
            *position_entree = '\0';
        }
        return 1;
    }
    else
        return 0;
}

// Vrai si le fichier est vide, faux sinon
bool Fichier_Vide(FILE *fichier)
{
    fseek(fichier, 0, SEEK_END);
    if (ftell(fichier) == 0)
    {
        puts("\nVotre équipe n'a pas de Pokemons!\n");
        return true;
    }
    else
        return false;
}

// Ajoute une quantité donnée de pokemons dans le fichier
void Ajouter_pokemons(FILE *fichier, int quantite)
{
    printf("\n\nIl faut %d Pokemons de plus!\n", quantite);
    char *pokemon = malloc(sizeof(char) * 20);
    for (int compteur = 0; compteur < quantite; compteur++)
    {
        printf(" - %d: ", compteur + 1);
        scanf(" %s", pokemon);
        fprintf(fichier, "%s\n", pokemon);
    }
    free(pokemon);
    printf("\n\n");
}

// Affiche les Pokemons et retourne leur quantite
int Lire_pokemons(FILE *fichier)
{
    printf("\nPokemons présents dans l'équipe:\n");
    rewind(fichier);
    // Quantité de Pokemons dans l'équipe
    int quantite = 0;
    // Pokemon lu du fichier
    char *pokemon = malloc(sizeof(char) * 30);
    while (fgets(pokemon, 30, fichier))
    {
        quantite++;
        printf(" - %s", pokemon);
    }
    printf("\n");
    return quantite;
}

int main()
{
    // Nom du fichier a vérifier
    char *adresse = malloc(sizeof(char) * 30);

    // Récupération du nom de fichier
    puts("Entrez le nom de votre équipe: ");
    if (Lire_user(adresse, 30))
    {
        FILE *fichier = NULL;
        fichier = fopen(adresse, "a+");

        if (Fichier_Vide(fichier))
        {
            Ajouter_pokemons(fichier, 6);
        }
        else
        {
            // Quantité de Pokemons dans le fichier
            int quantite = Lire_pokemons(fichier);
            if (quantite < 6)
                Ajouter_pokemons(fichier, 6 - quantite);
            else{
                if (quantite == 6)
                printf("\nBravo, votre équipe est complète!\n\n");
                else
                printf("Wadafak y'a trop de Pokémons!\n\n");
            }
        }

        // Fin de programme
        fclose(fichier);
        free(adresse);
        return 0;
    }
    else
    {
        // Fin de programme
        free(adresse);
        puts("\nErreur de lecture du nom de l'équipe :/\n\n");
        return 1;
    }
}