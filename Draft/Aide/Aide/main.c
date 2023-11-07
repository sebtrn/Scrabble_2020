#include "fichier.h"

int main()
{
    ///Declaration des variables
    int choix;

    ///Saisie de la valeur
    do
    {
        printf(" 1. Qu'est-ce que le Scrabble ?\n 2. Comment engager la partie ?\n 3. Comment jouer au Scrabble ?\n  4. Comment contester durant la partie ?\n 5. La fin de la partie.\n 0. Retourner au menu principal.\n ");
        printf("Que voulez-vous faire ? ");
        scanf("%d", &choix);
    }
    while((choix<0)||(choix>5));

    ///Conditions
    if(choix==0)
    {
        system("CLS");
        menu();
    }
    if(choix==1)
    {
       system("CLS");
       quest_ce_que_le_scrabble();
    }
    if(choix==2)
    {
        system("CLS");
        tour_de_jeu();
    }
    if(choix==3)
    {
        system("CLS");
    }
    if(choix==4)
    {
        system("CLS");
        contester();
    }
    if(choix==5)
    {
        system("CLS");
        fin_de_partie();
    }
}
