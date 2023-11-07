#include "fichier.h"

///Sous-programme menu
void menu()
{
    ///Declaration de variable
    int choix;

    ///Saisie de la valeur
    do
    {
        printf(" ///////////// MENU /////////////");
        printf("\n 1. Commencer une nouvelle partie\n 2. Jouer une ancienne partie\n 3. Aide\n 4. Scores\n 5. Quitter le jeu\n \n");
        printf(" Que voulez-vous faire (Taper chiffre de 1 a 5 SVP) ? ");
        scanf("%d", &choix);
    }
    while((choix<1)||(choix>5));
    if(choix==1)
    {
        system("CLS");
        welcome();
    }
    if(choix==2)
    {
        system("CLS");
    }
    if(choix==3)
    {
        system("CLS");
        aide();
    }
    if(choix==4)
    {
        system("CLS");
    }
    if(choix==5)
    {
        printf(" Vous avez choisi de quitter le jeu. Merci d'avoir joue.\n");
        return 0;
    }
}


///Sous-programme accueillant l'utilisateur
void welcome()
{
    ///Declaration de variable
    int nombreJ;

    ///Saisie du nombre de joueurs
    printf(" //////////// NOUVELLE PARTIE ////////////");
    printf("\n Bienvenue dans le SCRABBLE\n");
    do
    {
        printf(" Veuillez entrer le nombre de joueurs: ");
        fflush(stdin);
        scanf("%d", &nombreJ);
        system("CLS");
    }
    while((nombreJ<2)||(nombreJ>4));

    ///Appel du sous-programme
    init_player(nombreJ);

}


///Sous-programme initialisant le nom des joueurs
void init_player(int nombreJ)
{
    ///Declaration des variables
    int i;

    ///Initialisation des noms
    t_player players[nombreJ];
    printf(" /////////// NOUVELLE PARTIE /////////// \n");
    for(i=0; i<nombreJ; i++)
    {
        printf(" Veuillez entrer le nom du Joueur %d : ", i+1);
        fflush(stdin);
        gets(players[i].nom);
        players[i].score = 0;
    }
    for(i=0; i<nombreJ; i++)
    {
        printf(" Le nom du joueur %d est: %s\n", i+1, players[i].nom);
    }
    sleep(5);
    system("CLS");

}
