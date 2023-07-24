#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// TODO: générer valeurs uniques pour facile

// Niveaux de difficulté sélectionnables par le joueur
#define facile 1
#define moyenne 2
#define difficile 3
#define quitter 4

// Demande et retourne le choix initial de l'utilisateur
int menu();
// Génère un chiffre alléatoire en fonction de la difficulté
char chiffre_random(int difficulte);
// Génère le tableau secret
char *generer_secret(int difficulte);
// Vérifie que l'utilisateur entre 0 - 9 et la bonne longueur
bool check_entree(char *tableau, int longueur);
// Permet au joueur de faire son tour et d'abandonner
bool tour_joueur(char *tableau, int difficulte, int *quantite_coups);
// Verification du tour du joueur
bool check_tour(char *tableau_publique, char *tableau_prive);

/*
    MAIN
*/
int main()
{
    while (true)
    {
        // Niveau de difficulté sélectionné par le joueur
        int difficulte = menu();
        // Si le joueur veut quitter, on sort de la boucle de jeu
        if (difficulte == quitter)
        {
            break;
        }
        // Si le joueur choisit de jouer
        else
        {
            // Secret a trouver
            char *tableau_secret = generer_secret(difficulte);
            // Entree de l'utilisateur
            char *tableau_publique = malloc(sizeof(char) * 8);
            // Flag de victoire
            bool victoire = false;
            // Flag d'abandon
            bool abandon = false;
            // Nombre de coups
            int quantite_coups = 0;

            printf("\n\nC'est parti!\nSi ton entrée est trop longue, elle sera tronquée.\nEntrer '-1' pour abandonner.\n\n");
            // On laisse le joueur jouer jusqu'a victoire/abandon
            do
            {
                abandon = tour_joueur(tableau_publique, difficulte, &quantite_coups);
                victoire = check_tour(tableau_publique, tableau_secret);
            } while (!victoire && !abandon);

            // Affichage en cas de victoire
            if (victoire)
            {
                printf("\n\nT'a gagné en %d coups, prends un PIM'S!\n\n", quantite_coups);
            }

            // Affichage en cas d'abandon
            else
            {
                printf("\n\nWe'll get'em next time!\n\n");
            }

            // Nettoyage
            free(tableau_secret);
            free(tableau_publique);
        }
    }
    // Fin de jeu
    printf("\nA la prochaine!\n\n");
    return 0;
}

/*



    FIN DU MAIN



*/

// Demande et retourne le choix initial de l'utilisateur
int menu()
{
    int choix;
    do
    {
        printf("\n\n### MENU PRINCIPAL ###\n\nPartie facile:\t\t1\nPartie moyenne:\t\t2\nPartie difficile:\t3\nQUITTER:\t\t4\n\nTon choix: ");
        scanf(" %d", &choix);
    } while (choix != facile && choix != moyenne && choix != difficile && choix != quitter);

    return choix;
}

// Génère un chiffre alléatoire en fonction de la difficulté
char chiffre_random(int difficulte)
{
    // Chiffre aléatoire
    int chiffre;
    // Chiffre aleatoire converti en char
    char sortie;

    time_t temps;
    srand((unsigned)time(&temps));

    if (difficulte == facile)
    {
        // AJOUTER CHECK VALEUR UNIQUE
        do
        {
            chiffre = rand() % 5;
        } while (chiffre == 0);
    }
    else
    {
        if (difficulte == moyenne)
        {
            if (rand() % 6 == 0)
                chiffre = 0;
            else
            {
                do
                {
                    chiffre = rand() % 7;
                } while (chiffre == 0);
            }
        }
        else
        {
            if (difficulte == difficile)
            {
                if (rand() % 5 == 0)
                    chiffre = 0;
                else
                {
                    do
                    {
                        chiffre = rand() % 9;
                    } while (chiffre == 0);
                }
            }
            else
            {
                printf("\n\n### PROBLEME ###\nDifficulté incorrecte lors de la génération d'un random.\n");
            }
        }
    }

    // Conversion du chiffre en char
    sortie = chiffre + '0';

    return sortie;
}

// Génère le tableau secret
char *generer_secret(int difficulte)
{
    char *tableau = NULL;
    if (difficulte == facile)
    {
        tableau = malloc(sizeof(char) * 4);
        for (int compteur = 0; compteur < 4; compteur++)
        {
            tableau[compteur] = chiffre_random(facile);
        }
    }
    else
    {
        if (difficulte == moyenne)
        {
            tableau = malloc(sizeof(char) * 6);
            for (int compteur = 0; compteur < 6; compteur++)
            {
                tableau[compteur] = chiffre_random(moyenne);
            }
        }
        else
        {
            if (difficulte == difficile)
            {
                tableau = malloc(sizeof(char) * 8);
                for (int compteur = 0; compteur < 8; compteur++)
                {
                    tableau[compteur] = chiffre_random(difficile);
                }
            }
            else
            {
                printf("\n\n### PROBLEME ###\nDifficulté incorrecte lors de la génération du tableau.\n");
            }
        }
    }

    return tableau;
}

// Vérifie que l'utilisateur entre 0 - 9 et la bonne longueur
bool check_entree(char *tableau, int difficulte)
{
    int longueur = 5;
    if (difficulte == moyenne)
    {
        longueur = 7;
    }
    if (difficulte == difficile)
    {
        longueur = 9;
    }
    for (int compteur = 0; compteur < longueur -1; compteur++)
    {
        if (tableau[compteur] < '0' || tableau[compteur] > '9')
        {
            if (strcmp(tableau, "-1") == 0)
            {
                return true;
            }
            else
            {
                printf("T'a entré autre chose que des chiffres ou ta chaine n'est pas assez longue -_-\n");
                return false;
            }
        }
    }
    tableau[longueur - 1] = '\0';
    return true;
}

// Permet au joueur de faire son tour et d'abandonner
bool tour_joueur(char *tableau, int difficulte, int *quantite_coups)
{
    do
    {
        printf("Ton entrée: ");
        scanf(" %s", tableau);
    } while (!check_entree(tableau, difficulte));
    if (strcmp(tableau, "-1") == 0)
        return true;
    else{
        (*quantite_coups) ++;
        return false;
    }
}

// Verification du tour du joueur
bool check_tour(char *tableau_publique, char *tableau_prive)
{
    if (strcmp(tableau_prive, tableau_publique) == 0)
    {
        return true;
    }
    else
    {
        // Quantité de A a afficher
        int a = 0;
        // Quantité de B a afficher
        int b = 0;
        for (int compteur = 0; compteur < strlen(tableau_prive); compteur++)
        {
            if (tableau_prive[compteur] == tableau_publique[compteur])
            {
                a++;
            }
            else
            {
                for (int compteur_bis = 0; compteur_bis < strlen(tableau_prive); compteur_bis++)
                {
                    if (tableau_prive[compteur] == tableau_publique[compteur_bis])
                    {
                        printf("%c", tableau_prive[compteur]);
                        b++;
                    }
                }
            }
        }

        // Affichage
        for (int compteur = 0; compteur < a; compteur++)
        {
            printf("A");
        }
        for (int compteur = 0; compteur < b; compteur++)
        {
            printf("B");
        }
        printf("\n\n");

        return false;
    }
}