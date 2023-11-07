void menu(int choix) //sous-programme menu du jeu (1.2.3.4.5)
{
    switch(choix)
    {

    case 1:
        welcome();
        break;
    case 2:
        printf("ancienne partie");
        break;
    case 3:
        printf("Help");
        break;
    case 4:
        printf("Scores");
        break;
    case 5:
        printf("Quit the game");
        break;
    default:
        printf("Valeur invalide");
    }
}
