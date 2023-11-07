#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

void Color(int texte, int fond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,fond*16+texte);
}

void gotoligcol(int lig,int col)
{
    COORD mycoord;
    mycoord.X=col;
    mycoord.Y=lig;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),mycoord);
}

void initialisationplateau(char plat[15][15])
{
    ///mise en place

    int i,j;
    Color(0,10);

    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            plat[i][j]=' ';
        }
    }

    for (i=1;i<15;i++)
    {
        j=i;
        plat[i][j]='@';     ///case mot double
        plat[14-i][j]='@';
    }

    for (i=2;i<4;i++)
    {
        j=i+4;
        plat[i][j]='&';
        plat[j][i]='&';
        plat[14-i][j]='&';
        plat[14-i][14-j]='&';
        plat[14-j][14-i]='&';
        plat[14-j][i]='&';
        plat[i][14-j]='&';
        plat[j][14-i]='&';
    }
                                    ///case lettre double
    plat[0][3]='&';
    plat[0][11]='&';
    plat[3][0]='&';
    plat[3][14]='&';
    plat[11][0]='&';
    plat[11][14]='&';
    plat[14][3]='&';
    plat[14][11]='&';

    for (i=6;i<9;i++)
    {
        j=i;
        plat[i][j]='&';
        plat[14-i][j]='&';
    }

    plat[0][14]=245;
    plat[14][14]=245;
    plat[0][0]=245;
    plat[14][0]=245;
    plat[0][7]=245;        ///case mot triple
    plat[7][0]=245;
    plat[14][7]=245;
    plat[7][14]=245;

    plat[1][5]='%';
    plat[1][9]='%';
    plat[5][1]='%';
    plat[5][5]='%';
    plat[5][9]='%';
    plat[5][13]='%';       ///case lettre triple
    plat[9][1]='%';
    plat[9][5]='%';
    plat[9][9]='%';
    plat[9][13]='%';
    plat[13][5]='%';
    plat[13][9]='%';

    plat[7][7]='#';         ///case point de depart
}


void Placementmots(char tab[15][15],t_player )
{
    char sens;
    char motaplacer[16];
    int ligne,colo,i,j,lmot,verif=0;

    /*gotoligcol(40,40);
    for (i=0;i<7;i++)                               ///ou sous programme afficher la main
    {
        printf("%c"//le tableau de la main);
    }*/

    gotoligcol(37,40);
    printf ("veullez saisir la ligne et la colonne ou vous voulez placer le mot :\n");
    do
    {
        scanf("%d",&ligne);
        scanf("%d",&colo);
        if (ligne<0 || ligne>15 || colo<0 || colo>15)
        {
            printf("saisie incorrecte recommencez :\n");
        }
    }while (ligne<0 || ligne>15 || colo<0 || colo>15);
    printf("veuillez saisir le sens, V pour vertical, H pour horizontal a partir de la ligne %d et la colonne %d:\n",ligne,colo);
    do
    {
        fflush(stdin);
        scanf("%c",&sens);
        if (sens!='V' && sens!='H')
        {
            printf("saisie incorrecte recommencez :\n");
        }
    }while(sens!='V' && sens!='H');
    /*gotoligcol(37,40);
    printf("                                                                  \n                                                                   \n");
    printf("                                                                  \n                                                                   \n");
    printf("                                                                  \n                                                                   \n");
    printf("                                                                  \n                                                                   \n");
    */
    printf("saisisez le mots que vous creer avec vos lettres");
    do
    {                                                               ///verification si les lettres sont bien dans la main et le bon nombre de fois
        scanf("%s",motaplacer);


        lmot=strlen(motaplacer);
        for (i=0;i<7;i++)
        {
            for (j=0;j<7;j++)
            {
               if (motaplacer[i]==/*la main du joueur*/)           ///ou sous programme de verification en plus d'un sous programme pour passer son tour
               {
                   verif=verif+1;
                   /*la main du joueur=' ';*/
               }
            }
        }


    }while(verif!=lmot && passer!=1);
}

void affichermotplace(char place[15][15],int lig, int col)
{
    gotoligcol(lig*2,col*2);
    printf("%c %c ",place[lig-1][col-1],0xBA);
}

int main()//void affichageplateau(char plate[15][15])
{
    int i=0,j=0,k=0;
    char plate[15][15];

    initialisationplateau(plate);

    ///affichage du plateau

    //gotoligcol(i,35);
    for (k=1;k<10;k++)
    {
        printf("  %d ",k);
    }
    printf(" ");
    for (k=10;k<16;k++)
    {
        printf(" %d ",k);
    }
    printf("\n");

    for(i=0;i<15;i++)
    {
        //gotoligcol(i+1,35);
        if (i==0)
        {
            printf("%c",0xC9);
            for (k=0;k<29;k++)
            {
                if (k%2==1)
                {
                   printf("%c",0xCB);                   //tracer le haut
                }
                if ((k+1)%2==1)
                {
                   printf("%c%c%c",0xCD,0xCD,0xCD);
                }
            }
            printf("%c\n",0xBB);
        }
        printf("%c ",0xBA);
        for(j=0;j<15;j++)
        {
            if (plate[i][j]=='#')                        ///modif a faire pour couleur
            {
               Color(4,10);
            }
            if (plate[i][j]=='&')                        ///couleur lettre double
            {
                Color(11,10);
            }
            if (plate[i][j]=='@')                       ///couleur mot double
            {
                Color(12,10);
            }
            if (plate[i][j]==245)                       ///couleur mot triple
            {
                Color(4,10);
            }
            if (plate[i][j]=='%')                       ///couleur lettre triple
            {
                Color(1,10);
            }
            printf("%c ",plate[i][j]);
            Color(0,10);
            printf("%c ",0xBA);
        }
        printf (" %d\n",i+1);

        //gotoligcol(i+1,35);                                                //tracer le millieu
        if (i!=14)
        {
            printf("%c",0xCC);
            for (k=0;k<29;k++)
            {
                if (k%2==1)
                {
                    printf("%c",0xCE);
                }
                if ((k+1)%2==1)
                {
                    printf("%c%c%c",0xCD,0xCD,0xCD);
                }
            }
            printf("%c\n",0xB9);
        }
        else
        {
            printf("%c",0xC8);
            for (k=0;k<29;k++)
            {
                if (k%2==1)
                {
                    printf("%c",0xCA);
                }
                if ((k+1)%2==1)
                {
                    printf("%c%c%c",0xCD,0xCD,0xCD);
                }
            }
            printf("%c\n",0xBC);
        }
    }
    Color(15,0);
    Placementmots(plate);
}
