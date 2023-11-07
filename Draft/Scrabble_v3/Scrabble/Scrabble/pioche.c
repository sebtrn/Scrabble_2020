#include "fichier.h"

void pioche(char *jeton_tire, int *nb_total_jetons)
{
    ///Declaration des variables
    srand(time(NULL));
    char tab[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','JOKER'};
    int tab2[27] = {9,2,2,3,15,2,2,2,8,1,1,5,3,6,6,2,1,6,6,6,6,2,1,1,1,1,2};
    int ASCII;

    ///Affectation de la valeur
    if(nb_total_jetons>0)
    {
    do
    {
        ASCII = rand()%(27-1+1)+(1);

        ///Affectation de la lettre
        if(tab2[ASCII-1]>0)
        {
            *jeton_tire = tab[ASCII-1];
            tab2[ASCII-1] = tab2[ASCII-1] - 1;
            *nb_total_jetons = *nb_total_jetons - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    while(ASCII==0);
    }
    else
    {
        printf("Il n'y a plus de jetons !");
    }
}
