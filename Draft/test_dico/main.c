#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
     FILE* fic=NULL;
     fic=fopen("dictionnaire_scrabble.txt","r");
    //fic=fopen("dico_francais.txt","r");

     char dico[15];
     char motaverifier[15];
     int test=1,i;

     printf("Choisisez le mot a verifier : ");
     gets(motaverifier);

    if (fic==NULL)
    {
        printf("erreur");
    }
    else
    {
        while ((!feof(fic)) && test!=0)
        {
            fgets(dico,15,fic);
            for(i=0;i<15;i++)
            {
                if ((dico[i]==' ') || (dico[i]=='\n'))
                {
                    dico[i]='\0';
                }
            }
            test=strcmp(motaverifier,dico);
        }
        fclose(fic);
        if (test==0)
        {
            printf("le mot existe");
        }
        else
        {
            printf("le mot existe pas");
        }
    }
    return 0;
}
