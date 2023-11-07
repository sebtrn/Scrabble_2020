#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//appeler le menu
bool pause=false;
char input;

typedef struct //structure du plateau de jeu (carreau, lettre et mot)
{
    char carreau;
    char lettre;
    char mot;
} plateau_t;

struct plateau plateau[256];

struct plateau init_plateau() //initialisation du plateau
{
    plateau_t NouveauPlateau[15][15];
    for(int i=0; i<15; i++)
    {
        for(int j=0; j<15; j++)
        {
            if(i==1 || j==1)
            {
                NouveauPlateau[i][j].lettre='';
                NouveauPlateau[i][j].mot='';
                NouveauPlateau[i][j].carreau='';
            }
        }

    }
    return Nouveau_Plateau
};


typedef struct player //structure d'un joueur (nom, ses points, sa pioche et indique son tour)
{

    char nom[256]; //son nom
    int score; //son score
    char pioche[7]; //sa pioche de 7 lettres
    int tour; //au tour du joueur
};





int main()
{

    int choix;
    char input;
    welcome();

    /*
    scanf("%c", &input);
    afficher_menu(input);
    */

    printf(players[2].nom);
    /*players[2].nom utiliser le nom du joueur 2 (exemple)
    players[2].score utiliser le score du joueur 2 (exemple) */


    return 0;
}
