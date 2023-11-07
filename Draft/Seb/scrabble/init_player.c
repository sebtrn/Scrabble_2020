void init_player(int nombreJ) //Sous-programme qui initialise le nom des joueurs
{
    struct player players[nombreJ];
    for(int i=0; i<nombreJ; i++)
    {
        printf("Veuillez entrer le nom du Joueur %d : \n", i+1);
        scanf("%s",&players[i].nom);
    }
    for(int j=0; j<nombreJ; j++)
    {
        printf("Le nom du Joueur %d est : \n", j+1);
        puts(players[j].nom);
    }
}
