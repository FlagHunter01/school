---
title: Language C
description: Cours de C
status: deprecated
---

## Variables, conditions et boucles

```c linenums="1" title="exo_1.c"
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
```

```c linenums="1" title="exo_1bis.c"
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
```

```c linenums="1" title="exo_2.c"
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
```

```c linenums="1" title="exo_3.c"
#include <stdio.h>

int main()
{
    // Affichage de la tête du tableau
    printf("Caractère\tDécimal\tHexadécimal\n");

    // Affichage des caratères
    for (int counter = 0; counter < 128; counter++)
        printf("%c\t\t%d\t%x\n", counter, counter, counter);

    return 0;
}
```

```c linenums="1" title="exo_4.c"
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
```

```c linenums="1" title="exo_5.c"
#include <stdio.h>

int main()
{
    // Lecture des 3 entiers
    int a, b, c;
    printf("Saisissez le premier entier: ");
    scanf("%d", &a);
    printf("Saisissez le deuxième entier: ");
    scanf("%d", &b);
    printf("Saisissez le troisième entier: ");
    scanf("%d", &c);

    // Comparaison des entiers
    int max;
    if (a > b)
    {
        max = a;
    }
    else
    {
        max = b;
    }
    if (c > max) {
        max = c;
    }

    // Affichage

    printf("\nLe plus grand entier est: %d.\n", max);
    return 0;
}


```

```c linenums="1" title="exo_6.c"
#include <stdio.h>
#include <limits.h>

int main()
{
    printf("Entrer 0 pour arrêter la boucle.\n\n");

    // Stocke la plus grande valeur
    int max = INT_MIN;

    // Stocke la plus petite valeur
    int min = INT_MAX;

    // Contient la dernière valeur lue
    int read = 0;

    // Lecture et comparaison
    do
    {
        printf("Entrer un entier: ");
        scanf("%d", &read);

        if (read > max)
        {
            max = read;
        }
        if (read < min)
        {
            min = read;
        }
    } while (read != 0);

    // Affichage final
    printf("\n - Le min est %d\n - Le max est %d\n", min, max);

    return 0;
}
```

```c linenums="1" title="exo_7.c"
#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Drapeau de présence de diviseurs
    bool divisible = false;

    // Lecture de l'entier
    int entier;
    printf("Saisir l'entier positif: ");
    scanf("%d", &entier);

    // Recherche des diviseurs
    printf("\nLes diviseurs de %d sont:\n", entier);
    for (int counter = 2; counter < entier; counter++)
    {
        if (entier % counter == 0)
        {
            printf(" - %d\n", counter);
            divisible = true;
        }
    }

    // Message si pas de diviseurs
    if (!divisible)
        printf("Ben en fait y'en a pas mdr.\n");

    return 0;
}
```

```c linenums="1" title="exo_8.c"
#include <stdio.h>

int main()
{
    // Lecture des valeurs
    int a, b, min, max;
    printf("Entrez le premier entier positif: ");
    scanf("%d", &a);
    printf("Entrez le second entier positif: ");
    scanf("%d", &b);

    // Détermination de la plus grande et plus petite valeur
    if (a > b)
    {
        max = a;
        min = b;
    }
    else
    {
        max = b;
        min = a;
    }

    // Calcul du quotient
    int quotient = max / min;
    // Calcul du reste
    int reste = max % min;

    printf("\nRésultats:\n - Quotient: %d\n - Reste: %d\n", quotient, reste);

    return 0;
}
```

```c linenums="1" title="exo_9.c"
#include <stdio.h>
#include <stdbool.h>

bool Est_pair(int nombre)
{
    if (nombre % 2)
        return false;
    else
        return true;
}

int Algo_recursif(int a, int b)
{
    int reste = 0;

    printf("%d * %d", a, b);

    while (b)
    {
        if (Est_pair(b))
        {
            a = 2 * a;
            b = b / 2;
        }
        else
        {
            b -= 1;
            reste += a;
        }
        printf("\t= %d * %d + %d\n", a, b, reste);
    }

    return reste;
}

int main()
{
    // Lecture des entiers
    int a, b;
    printf("Entrez l'entier positif A: ");
    scanf("%d", &a);
    printf("Entrez l'entier positif B: ");
    scanf("%d", &b);
    printf("\n");

    // Affichage du résultat
    printf("\n\nLe résultat de %d * %d est %d\n", a, b, Algo_recursif(a, b));

    return 0;
}
```

## Tableaux, chaînes de caractères, fonctions & pointeurs

```c linenums="1" title="exo_1.c"
#include <stdio.h>
#include <stdlib.h>

int Lire_N()
{
    int choix;
    do
    {
        printf("Entrez la quantité d'enrtrées voulue pour le tableau: ");
        scanf("%d", &choix);
        if (choix < 1 || choix > 50)
            printf("La quantité doit être comprise entre 1 et 50!\n");
    } while (choix < 1 || choix > 50);

    return choix;
}

void Remplir_tableau(int choix, int *tableau)
{
    for (int compteur = 0; compteur < choix; compteur++)
    {
        printf("Entrez la valeur de la case %d: ", compteur + 1);
        scanf("%d", &tableau[compteur]);
    }
}

void Imprimer_tableau(int N, int *tableau)
{
    printf("\n\nAffichage du tableau:\n");
    for (int compteur = 0; compteur < N; compteur++)
        printf("%d ", tableau[compteur]);
    
    printf("\n");
}

int main()
{
    int N = Lire_N();
    int *tableau = malloc(sizeof(int) * N);
    Remplir_tableau(N, tableau);
    Imprimer_tableau(N, tableau);
    return 0;
}
```

```c linenums="1" title="exo_2.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Lire_N()
{
    int choix;
    do
    {
        printf("Entrez la quantité d'enrtrées voulue pour le tableau: ");
        scanf("%d", &choix);
        if (choix < 1 || choix > 50)
            printf("La quantité doit être comprise entre 1 et 50!\n");
    } while (choix < 1 || choix > 50);

    return choix;
}

void Remplir_tableau(int choix, int *tableau)
{
    for (int compteur = 0; compteur < choix; compteur++)
    {
        printf("Entrez la valeur de la case %d: ", compteur + 1);
        scanf("%d", &tableau[compteur]);
    }
}

void Imprimer_tableau(int N, int *tableau)
{
    printf("\n\nAffichage du tableau:\n");
    for (int compteur = 0; compteur < N; compteur++)
        printf("%d ", tableau[compteur]);

    printf("\n");
}

int Tasser_tableau(int N, int *tableau)
{
    printf("\nLe tableau a initialement %d entrées.\n", N);
    // Indique de combien le tableau sera raccourci
    int quantite_zeros = 0;
    // Sert a déplacer les valeurs des cases
    int decalage = 0;

    // Calcul de la quantité de zeros dans le tableau
    for (int compteur = 0; compteur < N; compteur++)
    {
        if (tableau[compteur] == 0)
            quantite_zeros++;
    }
    printf("%d zéros ont été trouvés.\nLe tableau tassé sera de %d entrées.\n", quantite_zeros, N - quantite_zeros);

    // Décalage des valeurs en fonction de la quantité de zeros rencontrés
    for (int compteur = 0; compteur < N - quantite_zeros; compteur++)
    {
        while (tableau[compteur + decalage] == 0)
            decalage += 1;

        tableau[compteur] = tableau[compteur + decalage];
    }

    // Libération de la mémoire
    tableau = realloc(tableau, sizeof(int) * N - quantite_zeros);
    return quantite_zeros;
}

int main()
{
    int N = Lire_N();
    int *tableau = malloc(sizeof(int) * N);
    int quantite_zeros;
    Remplir_tableau(N, tableau);
    quantite_zeros = Tasser_tableau(N, tableau);
    Imprimer_tableau(N - quantite_zeros, tableau);
    return 0;
}
```

```c linenums="1" title="exo_3.c"
#include <stdio.h>
#include <stdlib.h>

int Lire_N()
{
    int choix;
    do
    {
        printf("Entrez la quantité d'enrtrées voulue pour le tableau: ");
        scanf("%d", &choix);
        if (choix < 1 || choix > 50)
            printf("La quantité doit être comprise entre 1 et 50!\n");
    } while (choix < 1 || choix > 50);

    return choix;
}

void Remplir_tableau(int choix, int *tableau)
{
    for (int compteur = 0; compteur < choix; compteur++)
    {
        printf("Entrez la valeur de la case %d: ", compteur + 1);
        scanf("%d", &tableau[compteur]);
    }
}

void Imprimer_tableau(int N, int *tableau)
{
    printf("\n\nAffichage du tableau:\n");
    for (int compteur = 0; compteur < N; compteur++)
        printf("%d ", tableau[compteur]);
    
    printf("\n");
}

void Inversion (int N, int * tableau) {
    for (int compteur = 0; compteur < N / 2; compteur ++){
        int temp = tableau[compteur];
        tableau[compteur] = tableau[N - compteur - 1];
        tableau[N - compteur - 1] = temp;
    }
}

int main()
{
    int N = Lire_N();
    int *tableau = malloc(sizeof(int) * N);
    Remplir_tableau(N, tableau);
    Inversion(N, tableau);
    Imprimer_tableau(N, tableau);
    return 0;
}
```

```c linenums="1" title="exo_4.c"
// Piqué de mes TPs du BTS

#include <stdio.h>
#include <stdlib.h>

int main()
{
        //### DECLARATION DES VARIABLES #####################################################################################################

        char chain[50];                                 // Chaine pour stocker l'expression
        printf("\nEntrez une chaine pour savoir s'il s'agit d'un palyndrome! Longueur max: 50.\n");
        printf("Entrée: ");
        scanf("%s", chain);                             // "%s", chain   =   "%s", &chain[0]
        int index = 0;                                  // Numéro du caractère qu'on veut traiter
        int value = 1;                                  // Valeur du caractère qu'on veurt traiter
        int lenth = 0;                                  // Longueur de la chaine

        //### CALCUL DE LA LONGUEUR DE LA CHAINE ############################################################################################

        while (value != '\0')
        {
                value = chain[index];                   // Lecture de la valeur du caractère ne n° 'index'
                index ++;
                if (value == '\0')                      // Si le caractère est le caractère de fin de chaine ...
                {
                        lenth = index - 2;              // La longueur est de 'index'+2 (décalage car premier = chain[0] et index ++ avant if)
                }
        }
        index = 0;                                      // On reset l'index

        //### COMPARAISON DES VALEURS ########################################################################################################

        while (index <= lenth/2)                        // Tant que index est plus petit que la moitié de la longueur
        {
                if (chain[index] == chain[lenth-index]) // Si le caractère 0+i est égal au caractère 'longueur'-i
                {                                       // En gros on part du début et de la fin et on resserre jusqu'au milieu
                        index ++;
                        if (lenth-index == index)       // Soit les deux bouts se rejoignent au milieu (si quantité de caractères paire)
                        {
                                printf("\n      C'est un palyndrome!\n\n");
                                return 0;
                        }
                        if (lenth-index == index+1)     // Soit il y a un caractère entre les deux bouts (si quantité impaire)
                        {
                                printf("\n      C'est un palyndrome!\n\n");
                                return 0;
                        }
                }
                else
                {
                        printf("\n      Ce n'est pas un palyndrome ...\n\n");
                        return 0;
                }
        }
        printf("Y'a un bug");                          // Si les caractères ne sont ni iddentiques ni différents
        return 0;                                      // C'est qu'une boucle n'a pas fonctionné
}
```

```c linenums="1" title="exo_5.c"
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
```

```c linenums="1" title="exo_6.c"
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
```

```c linenums="1" title="exo_7.c"
#include <stdio.h>

int Max_2(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int Max_4(int a, int b, int c, int d)
{
    int max1 = Max_2(a, b);
    int max2 = Max_2(c, d);
    return Max_2(max1, max2);
}

int main()
{
    int a, b, c, d;
    printf("Entrez entier 1: ");
    scanf("%d", &a);
    printf("Entrez entier 2: ");
    scanf("%d", &b);
    printf("Entrez entier 3: ");
    scanf("%d", &c);
    printf("Entrez entier 4: ");
    scanf("%d", &d);

    printf("\nLe plus grand entier est %d.\n", Max_4(a, b, c, d));

    return 0;
}
```

```c linenums="1" title="exo_8.c"
#include <stdio.h>
#include <stdlib.h>

int Lire_N()
{
    int choix;
    do
    {
        printf("Entrez la quantité d'enrtrées voulue pour le tableau: ");
        scanf("%d", &choix);
        if (choix < 1 || choix > 50)
            printf("La quantité doit être comprise entre 1 et 50!\n");
    } while (choix < 1 || choix > 50);

    return choix;
}

void Remplir_tableau(int choix, int *tableau)
{
    for (int compteur = 0; compteur < choix; compteur++)
    {
        printf("Entrez la valeur de la case %d: ", compteur + 1);
        scanf("%d", &tableau[compteur]);
    }
}

int Calculer_somme(int N, int *tableau)
{
    int *pointeur = tableau;
    int somme = 0;
    for (int compteur = 0; compteur < N; compteur++)
    {
        somme += *pointeur;
        pointeur += 1; // et non sizeof(int) car les cases mémoire sont "collées" quand attribuées à un type
        printf("%d\n", somme);
    }
    return somme;
}

int main()
{
    int N = Lire_N();
    int *tableau = malloc(sizeof(int) * N);
    Remplir_tableau(N, tableau);
    printf("La somme des éléments du tableau est : %d.\n", Calculer_somme(N, tableau));
    return 0;
}
```

```c linenums="1" title="exo_9.c"
#include <stdio.h>
#include <string.h>

int main()
{
    // Chaine entrée
    char chaine[50];
    // Clé qui sert a commencer l'affichage
    char cle;
    // position de la 1e occurence de la clé
    printf("Entrez la chaine: ");
    printf("Entrez le caractère clé: ");
    scanf(" %c", &cle);
    // POINTEUUUUUUUUR
    char * pointeur = strchr(chaine, cle);
    printf("\nLa chaine tronquée par %c est:\n%s\n", cle, pointeur);

    return 0;
}
```

!!! failure inline end "Franchement flemme"

```c linenums="1" title="exo_10.c"
```

## Ecriture de fonctions

```c linenums="1" title="exo_1.c"
#include <stdio.h>

void exercice1()
{
    int a, b, c;
    for (a = 0; a <= 9; a++)
    {
        for (b = 0; b <= 9; b++)
        {
            for (c = 0; c <= 9; c++)
            {
                if (a < b && b < c)
                {
                    printf("%03d%03d%03d, ", a, b, c);
                }
            }
        }
    }
    printf("\n");
}

```

```c linenums="1" title="exo_2.c"
#include <stdio.h>

void exercice2()
{
    for (int a = 0; a < 100; a++)
    {
        for (int b = a + 1; b < 100; b++)
        printf("%02d %02d, ", a, b);
    }
    printf("\n");
}
```

```c linenums="1" title="exo_3.c"
#include <stdio.h>

// Valeur des cellules de RAM non utilisées
#define no_display -1

void Recursif(int nombre, int *ram)
{
    // Position de la fonction dans la RAM
    int position = 9 - nombre;

    // Valeur la plus petite à afficher
    int min;

    // Si la fonction n'est pas la première de la RAM (N = 9)
    // et n'est pas la première instance (la cellule précédente n'est pas utilisée)
    if (position && (ram[position - 1] != no_display))
    {
        // La valeur minimale = précédente + 1
        min = ram[position - 1] + 1;
    }
    else
    {
        // On est la première instance donc on commence à 0
        min = 0;
    }

    // Pour chaque valeur entre min et 9
    for (int compteur = min; compteur < 10; compteur++)
    {
        // On incrémente notre propre valeur
        ram[position] = compteur;

        // Si on n'est pas en dernière position, on lance la récursivité
        if (position < 8)
        {
            Recursif(nombre - 1, ram);
        }
        // Sinon on affiche tout nous mêmes
        else
        {
            for (int compteur_ram = 0; compteur_ram <= position; compteur_ram++)
            {
                if (ram[compteur_ram] != no_display)
                {
                    printf("%d", ram[compteur_ram]);
                }
            }
            printf("\n");
        }
    }
}

void exercie3()
{
    int nombre;
    int ram[9] = {no_display, no_display, no_display, no_display, no_display, no_display, no_display, no_display, no_display};
    printf("Entrez le nombre de chiffres (1 - 9): ");
    scanf("%d", &nombre);
    printf("\n");

    Recursif(nombre, ram);
    printf("\n");
}
```

```c linenums="1" title="exo_4.c"
#include <stdio.h>

void exercice4(char *string)
{
    int compteur = 0;
    while (string[compteur] != '\0')
    {
        putchar(string[compteur]);
        compteur++;
    }
    putchar('\n');
}

```

```c linenums="1" title="exo_5.c"
#include <stdio.h>

void exercice5(char *chaine)
{
    int compteur = 0;
    while (chaine[compteur] != '\0')
        compteur++;
    printf("Cette chaine contient %d caractères.\n", compteur);
}

```

```c linenums="1" title="exo_6.c"
#include <stdio.h>

void exercice6(int *a, int *b)
{
    int buffer = *a;
    *a = *b;
    *b = buffer;
}

```

```c linenums="1" title="bonus.c"
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

```

## Dernier jour

```c title="pokemon.c" linenums="1"
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
```

!!! warning "Je n'ai pas fini l'exo de structures."
