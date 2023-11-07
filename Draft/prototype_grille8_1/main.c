#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

void Color(int texte, int fond);
void gotoligcol(int lig,int col);
void initialisationplateau(char plat[15][15]);
//void deroulementtour();
void placementmot(char tab[15][15],char *psens,char choixlettres[15], int *pligne, int *pcolo,int *pverif,int *ppasser/*,t_player*/ );
void verifmot(char place[15][15],char motaplacer[15],int lig, int col,char senspla,int *pverif/*,char mainjoueur[]*/);
void affichermotplace(char place[15][15],char motaplacer[15],int lig, int col,char senspla);
void affichageplateau(char plate[15][15]);


void Color(int texte, int fond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,fond*16+texte);
}

void effacement(int ligne,int colonne,int longeur,int largeur)
{
    int i,j;

    gotoligcol(ligne,colonne);
    for (i=0;i<ligne;i++)
    {
        for (j=0;j<largeur;j++)
        {
            printf(" ");
        }
        printf("\n");
    }
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

int main()//void deroulementtour()
{
    char sens;
    char plateau[15][15];
    char motchoisi[16];
    int ligne,i,colo,choix,lmot,verif=0,passer=0,changement=0,quitter=0,tour=0;

    initialisationplateau(plateau);
    affichageplateau(plateau);

    //do
    //{
        do
        {
            gotoligcol(38,0);
            printf("taper :\n 1. Pour placer un mot,\n 2. Pour changer des lettres,\n 3. Pour passer son tour,\n 4. Pour quitter et sauvegarder.\n");
            scanf("%d",&choix);
            if (choix<1 || choix>4)
            {
                printf("saisie incorrect recommencez\n");
            }
        }while(choix<1 || choix>4);

        if (choix==1)
        {
            placementmot(plateau,&sens,motchoisi,&ligne,&colo,&verif,&passer/*,et la main ducoup*/);
            //verifmot(plateau, motchoisi, ligne, colo, sens,&verif/*,char mainjoueur[]*/);
        }
        if (choix==2)
        {

        }
        if (choix==3)
        {

        }
        if (choix==4)
        {

        }

        for (i=0;i<7;i++)                               ///ou sous programme afficher la main
        {
            //printf("%c"//le tableau de la main);
        }
    //}while(verif!=lmot+1 || passer!=1 || quitter!=1 || changement!=1);
    affichermotplace(plateau,motchoisi,ligne,colo,sens);
    tour=tour+1;
    return 0;
}

void placementmot(char tab[15][15],char *psens,char choixlettres[15], int *pligne, int *pcolo,int *pverif,int *ppasser/*,t_player*/ )
{
        //gotoligcol(37,40);

        printf ("veullez saisir la ligne et la colonne ou vous voulez placer le mot :\n");
        do
        {
            fflush(stdin);
            printf("ligne : ");
            scanf("%d",pligne);
            printf("colonne : ");
            scanf("%d",pcolo);
            if (*pligne<0 || *pligne>15 || *pcolo<0 || *pcolo>15)
            {
                printf("saisie incorrecte recommencez :\n");
            }
        }while (*pligne<0 || *pligne>15 || *pcolo<0 || *pcolo>15);

        printf("veuillez saisir le sens, V pour vertical, H pour horizontal a partir de la ligne %d et la colonne %d:\n",*pligne,*pcolo);
        do
        {
            fflush(stdin);
            scanf("%c",psens);
            if (*psens!='V' && *psens!='H')
            {
                printf("saisie incorrecte recommencez :\n");
            }
        }while(*psens!='V' && *psens!='H');

        printf("saisisez le mots que vous creer avec vos lettres :\n");

        fflush(stdin);                                                              ///verification si les lettres sont bien dans la main et le bon nombre de fois
        scanf("%s",choixlettres);
        gotoligcol(40,0);
}

void verifmot(char place[15][15],char motaplacer[15],int lig, int col,char senspla,int *pverif/*,char mainjoueur[]*/)
{
    int i,j,lmot;
    char verification[15];
    lmot=strlen(motaplacer);

    ///verification si le mot rentre sur le plateau

    if (senspla=='V')
    {
        if((lmot+col)>15)
        {
            *pverif=*pverif-1;
            printf("le mot depasse du plateau, saisie impossible.");
        }
    }

    if (senspla=='H')
    {
        if((lmot+lig)>15)
        {
            *pverif=*pverif-1;
            printf("le mot depasse du plateau, saisie impossible.");
        }
    }

    ///verification si on est au premier 1er tour est ce quu'il y a une lettre au centre

    /*if (tour==1)
    {
        if (((lmot+col)>=8) || ((lmot+lig)>=8))
        {
            if((lig!=8 && col!=8)|| senspla!='H') && senspla!='V')
            {
                *pverif=*pverif-1;
            }
            if((col!=8 && lig!=8) || senspla!='V') && senspla!='H')
            {
                *pverif=*pverif-1;
            }
        }
    }*/



    ///verification si les lettres correspondes aux mots

    for (i=0;i<lmot;i++)
    {
       // verification[i]=/*mainjoueur[i];*/
    }

    for (i=0;i<lmot;i++)
    {
        for (j=0;j<7;j++)
        {
            if (motaplacer[i]==verification[j])
            {
                *pverif=*pverif+1;
                verification[j]=' ';
            }
        }
    }
    if (lmot!=*pverif)
    {
        printf("vous n'avez pas les lettres permettant de composer ce mot.");
    }

    ///verification si mot dans le dictionnaire

}

void affichermotplace(char place[15][15],char motaplacer[15],int lig, int col,char senspla)
{
    int lmot,k;

    lmot=strlen(motaplacer);

    Color(0,10);

    if (senspla=='H')
    {
        gotoligcol((lig*2),(col*4)-2);
        for (k=0;k<lmot;k++)
        {
            place[lig-1][col-1+k]=motaplacer[k];
            printf("%c %c ",place[lig-1][col-1+k],0xBA);                      ///Horizontalement
        }
    }

    if (senspla=='V')
    {
        for (k=0;k<lmot;k++)
        {
            place[lig-1+k][col-1]=motaplacer[k];
            gotoligcol(((lig+k)*2),(col*4)-2);                               ///vertcalement
            printf("%c",place[lig-1+k][col-1]);
            gotoligcol(((lig+k)*2+1),(col*4)-2);
            printf("%c",0xCD);
        }
    }
    Color(15,0);
}

void affichageplateau(char plate[15][15])
{
    int i=0,j=0,k=0;

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
}
