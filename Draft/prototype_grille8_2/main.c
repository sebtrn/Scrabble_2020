#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

void Color(int texte, int fond);
void gotoligcol(int lig,int col);
void initialisationplateau(char plat[15][15]);
void menutour(int *pchoix);
//void deroulementtour();
void placementmot(char tab[15][15],char *psens,char choixlettres[15], int *pligne, int *pcolo,int *ppasser/*,t_player*/ );
void verifmot(char place[15][15],char motaplacer[15],int lig, int col,char senspla,int *pverif,int tour/*,char mainjoueur[]*/);
void affichermotplace(char place[15][15],char motaplacer[15],int lig, int col,char senspla);
void affichageplateau(char plate[15][15]);
void passertour(int *ppasser);
void changerlettres(int *pchangement);
void sauvquitter(int *pquitter);
void contester(int *pcontestation);
int score(char pla[15][15],char motplace[15],int lig, int col,char senspla);
void grilledejeu();


void Color(int texte, int fond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,fond*16+texte);
}

void effacement(int ligne,int colonne,int longeur,int largeur)
{
    int i,j;

    gotoligcol(ligne,colonne);
    for (i=0;i<longeur;i++)
    {
        for (j=0;j<largeur;j++)
        {
            printf(" ");
        }
        gotoligcol(ligne+i,colonne);
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

    plat[0][14]='$';
    plat[14][14]='$';
    plat[0][0]='$';
    plat[14][0]='$';
    plat[0][7]='$';        ///case mot triple
    plat[7][0]='$';
    plat[14][7]='$';
    plat[7][14]='$';

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

void menutour(int *pchoix)
{
    do
    {
        gotoligcol(15,83);
        printf("taper : ");
        gotoligcol(16,83);
        printf("1. Pour placer un mot,");
        gotoligcol(17,83);
        printf("2. Pour changer des lettres,");
        gotoligcol(18,83);
        printf("3. Pour passer son tour,");
        gotoligcol(19,83);
        printf("4. Retourner au menu et sauvegarder,");
        gotoligcol(20,83);
        printf("5. Pour reafficher la grille de jeu. ");
        fflush(stdin);
        scanf("%d",pchoix);
        if (*pchoix<1 || *pchoix>5)
        {
            gotoligcol(20,83);
            printf("saisie incorrect recommencez");
            Sleep(2000);
        }
        effacement(15,83,8,65);
    }while(*pchoix<1 || *pchoix>5);

}

void passertour(int *ppasser)
{

}

void changerlettres(int *pchangement)
{

}

void sauvquitter(int *pquitter)
{

}


int main()//void deroulementtour()
{
    char sens;
    char plateau[15][15];
    char motchoisi[16];
    int ligne,i,colo,choix,lmot,verif=0,passer=0,changement=0,quitter=0,tour=0,contestation=1;
    int scorea;

    initialisationplateau(plateau);
    affichageplateau(plateau);

    //do
    //{
        menutour(&choix);

        if (choix==1)
        {
            placementmot(plateau,&sens,motchoisi,&ligne,&colo,&passer/*,et la main ducoup*/);
            lmot=strlen(motchoisi);
            //contester(&contestation);
            verifmot(plateau, motchoisi, ligne, colo, sens,&verif,tour/*, mainjoueur[]*/);
        }
        if (choix==2)
        {
            changerlettres(&changement);
        }
        if (choix==3)
        {
            passertour(&passer);
        }
        if (choix==4)
        {
            sauvquitter(&quitter);
        }
        if (choix==5)
        {
            system("CLS");
            affichageplateau(plateau);
            grilledejeu();
        }

        for (i=0;i<7;i++)                               ///ou sous programme afficher la main
        {
            //printf("%c"//le tableau de la main);
        }
    //}while(verif!=lmot+1 || passer!=1 || quitter!=1 || changement!=1 || contestation!=1);
    //sous programme pour remettre  7 lettres dans chevalet
    /*le score structure*/scorea=score(plateau,motchoisi,ligne,colo,sens);
    affichermotplace(plateau,motchoisi,ligne,colo,sens);
    ///test
    gotoligcol(16,83);
    printf("%d",scorea);

    if (quitter!=1)
    {
        tour=tour+1;
    }

    return 0;
}

void placementmot(char tab[15][15],char *psens,char choixlettres[15], int *pligne, int *pcolo,int *ppasser/*,t_player*/ )
{

        gotoligcol(16,83);
        printf ("Saisisez la ligne et la colonne ou vous voulez placer le mot : ");
        do
        {
            fflush(stdin);
            gotoligcol(17,83);
            printf("ligne : ");
            scanf("%d",pligne);
            fflush(stdin);
            gotoligcol(18,83);
            printf("colonne : ");
            scanf("%d",pcolo);
            if (*pligne<0 || *pligne>15 || *pcolo<0 || *pcolo>15)
            {
                gotoligcol(19,83);
                printf("saisie incorrecte recommencez.");
                Sleep(2000);
            }
            effacement(16,83,5,65);
        }while (*pligne<0 || *pligne>15 || *pcolo<0 || *pcolo>15);

        gotoligcol(16,83);
        printf("veuillez saisir le sens, V pour vertical, H pour horizontal");
        gotoligcol(17,83);
        printf("du mot commencant a la ligne %d et la colonne %d : ",*pligne,*pcolo);
        do
        {
            gotoligcol(18,83);
            fflush(stdin);
            scanf("%c",psens);
            if (*psens!='V' && *psens!='H')
            {
                gotoligcol(19,83);
                printf("saisie incorrecte recommencez.");
                Sleep(2000);
            }
            effacement(16,83,7,65);
        }while(*psens!='V' && *psens!='H');

        gotoligcol(16,83);
        printf("saisisez le mots que vous creer avec vos lettres");
        gotoligcol(17,83);
        printf("et celles du plateau : ");
        fflush(stdin);
        scanf("%s",choixlettres);
        Sleep(2000);
        effacement(16,83,3,65);
}

void verifmot(char place[15][15],char motaplacer[15],int lig, int col,char senspla,int *pverif,int tour/*,char mainjoueur[]*/)
{
    int i,j,lmot;
    char verificationmain[7];
    char verificationmot[15];
    lmot=strlen(motaplacer);

    ///verification si le mot rentre sur le plateau

    if (senspla=='V')
    {
        if((lmot+lig)>16)
        {
            *pverif=*pverif-1;
            gotoligcol(16,83);
            printf("le mot depasse du plateau, saisie impossible.");
            Sleep(5000);
            effacement(16,83,2,65);
        }
    }

    if (senspla=='H')
    {
        if((lmot+col)>16)
        {
            *pverif=*pverif-1;
            gotoligcol(16,83);
            printf("le mot depasse du plateau, saisie impossible.");
            Sleep(5000);
            effacement(16,83,2,65);
        }
    }

    ///verification si on est au premier 1er tour est ce quu'il y a une lettre au centre

    if (tour==1)
    {
        if ((((lmot+col)>=8) || ((lmot+lig)>=8)) && (lig!=8 || col!=8))
        {

            if(lig!=8 && senspla=='V')
            {
                *pverif=*pverif-1;
            }
            if(col!=8 && senspla=='H')
            {
                *pverif=*pverif-1;
            }
        }
    }


    ///verification si les lettres correspondes aux mots

    for (i=0;i<7;i++)
    {
       // verificationmain[i]=/*mainjoueur[i];*/
    }
    for (i=0;i<lmot;i++)
    {
        verificationmot[i]=motaplacer[i];
    }

    for (i=0;i<lmot;i++)
    {
        if ((place[lig+i-1][col-1]==verificationmot[i]) && senspla=='V')
        {
            verificationmot[i]=' ';
        }
        if ((place[lig-1][col+i-1]==verificationmot[i]) && senspla=='H')
        {
            verificationmot[i]=' ';
        }
        for (j=0;j<7;j++)
        {
            if (verificationmot[i]==verificationmain[j])
            {
                *pverif=*pverif+1;
                verificationmain[j]=' ';
            }
        }
    }
    if (lmot!=*pverif)
    {
        gotoligcol(16,83);
        printf("vous n'avez pas les lettres permettant de composer ce mot.");
        Sleep(5);
        effacement(16,83,1,65);
    }

    ///une fois veufié transformé la main (a deplacer ou deplacer la contestation)

    if(*pverif==lmot+1)
    {
        for (i=0;i<7;i++)
        {
           // /*mainjoueur[i]*/=verificationmain[i];
        }
    }
}

void contester(int *pconcestation)
{
    FILE* fic=NULL;
    fic=fopen("dictionnaire_scrabble.txt","r");

    char dico[15];
    char motaverifier[15];
    int test=1,i;

    gotoligcol(16,83);
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
        gotoligcol(17,83);
        if (test==0)
        {

            printf("le mot existe");
        }
        else
        {
            printf("le mot existe pas");
        }
        effacement(16,83,3,65);
    }
}

int score(char pla[15][15],char motplace[15],int lig, int col,char senspla/*main du joueur*/)
{
    int i,j,lmot,score,vide=0,ajout=0,multiplicateur=1;
    char lettres[27];
    int listepoints[27]= {1,3,3,2,1,4,2,4,1,8,10,1,2,1,1,3,8,1,1,1,1,4,10,10,10,10,0};

    score=0;

    for (i=0;i<26;i++)
    {
        lettres[i]='A'+i;
    }
    lettres[27]='?';

    lmot=strlen(motplace);


    /*for(i=0;i<7;i++)
    {
        if(//main==' ')
        {
            vide=vide+1;
        }
    }
    if (vide==7)
    {
        //score=score+50;
    }*/

    for (i=0;i<lmot;i++)
    {
        for (j=0;j<27;j++)
        {
            if (motplace[i]==lettres[j])
            {
                ajout=ajout+listepoints[j];

                ///si le mot est vertical

                if(senspla=='V')
                {
                    if (pla[lig+i-1][col-1]=='&')
                    {
                        ajout=ajout*2;
                    }
                    if (pla[lig+i-1][col-1]=='%')
                    {
                        ajout=ajout*3;
                    }
                    if ((pla[lig+i-1][col-1]=='@') || (pla[lig+i-1][col-1]=='#'))
                    {
                        multiplicateur= multiplicateur*2;
                    }
                    if (pla[lig+i-1][col-1]=='$')
                    {
                        multiplicateur= multiplicateur*3;
                    }
                }

                ///si le mot est horizontal

                if(senspla=='H')
                {
                    if (pla[lig-1][col+i-1]=='&')
                    {
                        ajout=ajout*2;
                    }
                    if (pla[lig-1][col+i-1]=='%')
                    {
                        ajout=ajout*3;
                    }
                    if ((pla[lig-1][col+i-1]=='@') || (pla[lig+i-1][col-1]=='#'))
                    {
                        multiplicateur=multiplicateur*2;
                    }
                    if (pla[lig-1][col+i-1]=='$')
                    {
                        multiplicateur=multiplicateur*3;
                    }
                }
            }
        }
        score=score+ajout;
        ajout=0;
    }
    gotoligcol(18,83);
    printf("%d",multiplicateur);
    score=score*multiplicateur;

    return score;
}

void affichermotplace(char place[15][15],char motaplacer[15],int lig, int col,char senspla)
{
    int lmot,k;

    lmot=strlen(motaplacer);

    Color(0,10);

    if (senspla=='H')
    {
        gotoligcol((lig*2)+6,(col*4)+11);
        for (k=0;k<lmot;k++)
        {
            place[lig-1][col-1+k]=motaplacer[k];
            printf(" %c %c",place[lig-1][col-1+k],0xBA);
            //printf("%c")                      ///Horizontalement
        }
    }

    if (senspla=='V')
    {
        for (k=0;k<lmot;k++)
        {
            place[lig-1+k][col-1]=motaplacer[k];
            gotoligcol(((lig+k)*2)+6,(col*4)-2+14-1);                               ///vertcalement
            printf(" %c ",place[lig-1+k][col-1]);
            gotoligcol(((lig+k)*2+1)+6,(col*4)-2+14);
            printf("%c",0xCD);
        }
    }
    Color(15,0);
}

/*void couleurbonus(char tab[15][15],int i, int j)
{
    if (tab[i][j]==tab[])
}*/

void grilledejeu()
{
    int i=5,j=10;

    Color(15,0);
    for(i=5;i<39;i++)
    {
        for(j=10;j<151;j++)
        {
            if (j==10 || j==80 || j==150)
            {
                gotoligcol(i,j);
                printf("%c",0xB3);
            }
            else
            {
                printf(" ");
                gotoligcol(i,j);
            }
            if ((i==9 || i==23 || i==31 || i==38) && j>=80)
            {
                gotoligcol(i,j);
                printf("%c",0xC4);
                if(j==80)
                {
                    gotoligcol(i,j);
                    printf("%c",0xC3);
                }
                if(j==150)
                {
                    gotoligcol(i,j);
                    printf("%c",0xB4);
                }

            }
            if (i==5)
            {
                gotoligcol(i,j);
                printf("%c",0xC4);

                if(j==10)
                {
                    gotoligcol(i,j);
                    printf("%c",0xDA);
                }
                if(j==80)
                {
                    gotoligcol(i,j);
                    printf("%c",0xC2);
                }
                if(j==150)
                {
                    gotoligcol(i,j);
                    printf("%c",0xBF);
                }
            }

            if (i==38)
            {
                gotoligcol(i,j);
                printf("%c",0xC4);

                if(j==10)
                {
                    gotoligcol(i,j);
                    printf("%c",0xC0);
                }
                if(j==80)
                {
                    gotoligcol(i,j);
                    printf("%c",0xC1);
                }
                if(j==150)
                {
                    gotoligcol(i,j);
                    printf("%c",0xD9);
                }
            }
            printf("\n");
        }

    }
}

void affichageplateau(char plate[15][15])
{
    int i=0,j=0,k=0;

    ///affichage du plateau

    grilledejeu();

    gotoligcol(6,14);
    for (k=1;k<10;k++)
    {
        printf("  %d ",k);
    }
    printf(" ");
    for (k=10;k<16;k++)
    {
        printf(" %d ",k);
    }

    Color(0,10);
    for(i=0;i<15;i++)
    {
        gotoligcol(7+i,14);
        if (i==0)
        {

            printf("%c",0xC9);
            for (k=0;k<29;k++)
            {
                if (k%2==1)
                {
                    printf("%c",0xCB);                    ///tracer le haut
                }
                if ((k+1)%2==1)
                {
                   printf("%c%c%c",0xCD,0xCD,0xCD);
                }
            }
            printf("%c",0xBB);

        }

        gotoligcol(8+(2*i),14);
        printf("%c",0xBA);
        for(j=0;j<15;j++)
        {

            if (plate[i][j]=='#')                        ///modif a faire pour couleur
            {
               Color(12,4);
            }
            if (plate[i][j]=='&')                        ///couleur lettre double
            {
                Color(11,9);
            }
            if (plate[i][j]=='@')                       ///couleur mot double
            {
                Color(4,12);
            }
            if (plate[i][j]=='$')                       ///couleur mot triple
            {
                Color(13,5);
            }
            if (plate[i][j]=='%')                       ///couleur lettre triple
            {
                Color(9,1);
            }
            printf(" %c ",plate[i][j]);
            Color(0,10);
            printf("%c",0xBA);
        }
        Color(15,0);
        printf (" %d",i+1);

        Color(0,10);
        gotoligcol(9+(2*i),14);
        if (i!=14)                                  //tracer le millieu
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
