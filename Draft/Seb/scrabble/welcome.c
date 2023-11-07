void welcome() //Sous-programme qui accueille l'utilisateur
{
    int nombreJ;
    printf("Bienvenue dans le SCRABBLE\n");
    printf("Veuillez entrer le nombre de joueurs: ");
    scanf("%d", &nombreJ);
    init_player(nombreJ);

}
