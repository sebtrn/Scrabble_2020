void afficher_menu(char input) //Sous-programme qui affiche le menu
{
    int choix;
    if(input=='m')
    {
        pause=true;
        printf("MENU: \n");
        printf("1. Lancer une nouvelle partie \n2. Reprendre une partie sauvegardee \n3. Afficher l’aide \n4. Afficher les scores des joueurs \n5. Quitter le jeu \n");
        printf("Veuillez entrer votre choix: \n");
        scanf("%d", &choix);
        menu(choix);
    }
    else
    {
        printf("valeur invalide");
    }

    return choix;
}

/*
void restart()
{
  //relancer la partie
}
void help()
{
    //Afficher l'aide
}
void score()
{
    //Afficher les scores des joueurs
}
*/
