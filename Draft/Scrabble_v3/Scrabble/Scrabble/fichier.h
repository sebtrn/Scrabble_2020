#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED

///Bibliotheques utilisees

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>


///Definitions de structures

//Menu
typedef struct player                   //structure d'un joueur (nom, ses points, sa pioche et indique son tour)
{
    char nom[256]; //son nom
    int score; //son score
    char pioche[7]; //sa pioche de 7 lettres
    int tour; //au tour du joueur
}t_player;


///Liste des sous-programmes

//Aide
void aide();
void quest_ce_que_le_scrabble();
void engager_la_partie();
void tour_de_jeu();
void contester();
void fin_de_partie();

//Ecran d'accueil
void ecran_accueil();

//Chronometre
void chronometre(int *N);                //N= temps max saisi préalablement

//Couleur
void couleur(int couleurDuTexte,int couleurDeFond);

//Pioche
void pioche(char *jeton_tire, int *nb_total_jetons);

//Plateau
void initialisationplateau(char plat[15][15]);
void gotoligcol(int lig,int col);
void affichageplateau(char plate[15][15]);

//Menu
void menu();
void welcome();
void init_player(int nombreJ);


///Sources
/*
Couleur: https://www.developpez.net/forums/d309614/c-cpp/c/couleurs-c/
Dictionnaire: https://www.freelang.com/dictionnaire/dic-francais.php


*/
#endif // FICHIER_H_INCLUDED
