#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>

typedef struct player{          //structure d'un joueur (nom, ses points, sa pioche et indique son tour)
    char nom[50];               //son nom
    int score;                  //son score
    char pioche[7];             //sa pioche de 7 lettres
    int tourpasse;              //tour passé
    }t_player;

void Color(int texte, int fond);
void gotoligcol(int lig,int col);
void initialisationplateau(char plat[15][15]);
void menutour(int *pchoix);
void deroulementtour(t_player joueurj[4],int tourde,int *pnbtotaljetons, char ptab[27], int ptab2[27],char plateau[15][15],int nombreJ,int *ptourj);
void placementmot(char tab[15][15],char *psens,char choixlettres[15], int *pligne, int *pcolo,int *ppasser);
void verifmot(char place[15][15],char motaplacer[15],int lig, int col,char senspla,int *pverif,int tour,t_player *pptjoueur);
void affichermotplace(char place[15][15],char motaplacer[15],int lig, int col,char senspla);
void affichageplateau(char plate[15][15]);
void passertour(int *ppasser, t_player *pptjoueur);
void changerlettres(int *pchangement, int *nb_total_jetons, t_player *pptjoueur, char ptab[27], int ptab2[27]);
void sauvquitter(int *pquitter);
void contester(int *pcontestation,t_player *pptjoueur,int tourde);
void pioche(char *jetontire, int *nbtotaljetons, char tab[27],int tab2[27]);
void score(char pla[15][15],char motplace[15],int lig, int col,char senspla,t_player *pptjoueur);
void grilledejeu();
void afficher_main(t_player *pptjoueur);
void afficher_bonus(t_player *pptjoueur,int nombreJ);
void recap(int tourj, int lettresrest);
void remplissagemain(int *nb_total_jetons, t_player *pptjoueur, char ptab[27], int ptab2[27]);
void couleurbonus(char tab[15][15],int i, int j);
void recap_finpartie(t_player *pptjoueur,int nombreJ);
void conditionvictoire( t_player *pptjoueur, int nb_total_jetons,int nombreJ);
void affichermotprovi(char place[15][15],char motaplacer[15],int lig, int col,char senspla);

int main()
{
    t_player joueurs[4];
    int nombreJ,i,j,condition_victoire=0,nbtotaljetons=102, tourjoue=1;
    char tab[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','?'};
    int tab2[27] = {9,2,2,3,15,2,2,2,8,1,1,5,3,6,6,2,1,6,6,6,6,2,1,1,1,1,2};
    char jetontire;
    char plateaui[15][15];
    srand(time(NULL));

    printf("Veuillez saisir le nombre de joueurs (entre 2 et 4) : \n");
    do
    {
        fflush(stdin);
        scanf("%d",&nombreJ);
        if (nombreJ<2 || nombreJ>4)
        {
            printf ("saisie incorrecte, recommencez (entre 2 et 4) : ");
        }
    }while(nombreJ<2 || nombreJ>4);


    for(i=0; i<nombreJ; i++)
    {
        printf("Veuillez entrer le nom du Joueur %d : ", i+1);
        fflush(stdin);
        gets(joueurs[i].nom);
        joueurs[i].score = 0;
        joueurs[i].tourpasse=0;
    }

    ///Initialisation de la main des joueurs

    for(i=0;i<nombreJ;i++)
    {
        for(j=0;j<7;j++)
        {
            pioche(&jetontire, &nbtotaljetons,tab,tab2);
            joueurs[i].pioche[j] = jetontire;
        }
    }

    /*printf("\n");
    for(i=0; i<nombreJ; i++)
    {
        printf("Le nom du joueur %d est: %s\n", i+1, joueurs[i].nom);
    }
    sleep(5);*/
    system("CLS");

    ///initialisation jeu

    initialisationplateau(plateaui);
    affichageplateau(plateaui);

    ///Changement de joueur

    do
    {
        for(i=0;i<nombreJ;i++)
        {
            if (condition_victoire==0)
            {
                deroulementtour(joueurs,i,&nbtotaljetons,tab,tab2,plateaui,nombreJ,&tourjoue);
            }
            //players[i].tour = players[i].tour+1;
        }
        tourjoue=tourjoue+1;
        conditionvictoire(joueurs,nbtotaljetons,nombreJ);
    }
    while(condition_victoire==0);

}

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

void pioche(char *jetontire, int *nbtotaljetons, char tab[27],int tab2[27])
{
    ///Declaration des variables

    int ASCII;

    ///Affectation de la valeur
    if(nbtotaljetons>0)
    {
        do
        {
            ASCII = rand()%(27-1+1)+(1);

            ///Affectation de la lettre
            if(tab2[ASCII-1]>0)
            {
                *jetontire = tab[ASCII-1];
                tab2[ASCII-1] = tab2[ASCII-1] - 1;
                *nbtotaljetons = *nbtotaljetons - 1;
            }
            else
            {
                ASCII = 0;
            }
        }while(ASCII==0);
    }
    else
    {
        printf("Il n'y a plus de jetons !");
    }
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
        printf("Taper : ");
        gotoligcol(16,83);
        printf("1. Pour placer un mot");
        gotoligcol(17,83);
        printf("2. Pour changer des lettres");
        gotoligcol(18,83);
        printf("3. Pour passer son tour");
        gotoligcol(19,83);
        printf("4. Retourner au menu et sauvegarder");
        gotoligcol(20,83);
        printf("5. Pour reafficher la grille de jeu");
        gotoligcol(21,83);
        printf("Que voulez-vous faire ?  ");
        fflush(stdin);
        scanf("%d",pchoix);
        if (*pchoix<1 || *pchoix>5)
        {
            gotoligcol(22,83);
            printf("Saisie incorrect. Recommencez");
            Sleep(2000);
        }
        effacement(15,83,9,65);
    }while(*pchoix<1 || *pchoix>5);

}

void passertour(int *ppasser, t_player *pptjoueur)
{
    int choix3;

    do
    {
        gotoligcol(16,83);
        printf("Etes-vous sur de passer votre tour (1 = OUI, 0 = NON)? ");
        fflush(stdin);
        scanf("%d",&choix3);
        if(choix3==1)
        {
            *ppasser=1;
            pptjoueur->tourpasse=pptjoueur->tourpasse+1;
        }
    }
    while(choix3!=1 && choix3!=0);
    effacement(16,83,1,60);
}

void changerlettres(int *pchangement, int *nb_total_jetons, t_player *pptjoueur, char ptab[27], int ptab2[27])
{
    ///Declaration de variables
    int k, l, m;
    int lettre_a_changer;
    int nb_lettres;
    char jeton_tire;
    char temp;

    ///Saisie du nombres de lettres a changer
    gotoligcol(16,83);
    printf("Combien de lettres voulez-vous changer ? ");
    do
    {
        fflush(stdin);
        scanf("%d", &nb_lettres);
        if (nb_lettres<1 || nb_lettres>7)
        {
            gotoligcol(17,83);
            printf("saisie incorrect recommencez (entre 1 et 7)");
            effacement(16,83,3,65);
        }
    }while(nb_lettres<1 || nb_lettres>7);
    effacement(16,83,3,65);

    gotoligcol(16,83);
    printf("Quelles sont les %d lettres que vous voulez changer ? ", nb_lettres);
    for(k=0;k<nb_lettres;k++)
    {
        gotoligcol(16,83);
        printf(" la %de lettre a changer ou a rechanger est la combientieme ? ",k+1);
        do
        {
            fflush(stdin);
            scanf("%d",&lettre_a_changer);
            if(lettre_a_changer<1 || lettre_a_changer>7)
            {
                gotoligcol(18,83);
                printf("Saisie incorrect. Recommencez (entre 1 et 7) ");
                effacement(16,83,4,65);
            }
        }while (lettre_a_changer<1 || lettre_a_changer>7);
        effacement(16,83,4,65);
        temp = pptjoueur->pioche[lettre_a_changer-1];
        pptjoueur->pioche[lettre_a_changer-1] = ' ';

        ///Remise de la lettre dans la pioche
        for(m=0;m<27;m++)
        {
            if(temp==ptab[m])
            {
                ptab2[m] = ptab2[m]+1;
                *nb_total_jetons=*nb_total_jetons+1;
            }
        }
    }

    ///Changement des lettres
    for(l=0;l<7;l++)
    {
        if(pptjoueur->pioche[l]==' ')
        {
            pioche(&jeton_tire,nb_total_jetons,ptab,ptab2);
            pptjoueur->pioche[l] = jeton_tire;
        }
    }
    *pchangement = 1;
}
void sauvquitter(int *pquitter)
{

}



void deroulementtour(t_player joueurj[4],int tourde,int *pnbtotaljetons, char ptab[27], int ptab2[27],char plateau[15][15],int nombreJ,int *ptourj)
{
    char sens;
    char motchoisi[15];
    int ligne,colo,choix,lmot,verif=0,passer=0,changement=0,quitter=0,contestation=0;

    do
    {

        afficher_main(&joueurj[tourde]);
        recap(*ptourj,*pnbtotaljetons);
        afficher_bonus(joueurj,nombreJ);
        menutour(&choix);

        if (choix==1)
        {
            placementmot(plateau,&sens,motchoisi,&ligne,&colo,&passer);
            lmot=strlen(motchoisi);
            Color(0,15);
            affichermotprovi(plateau,motchoisi,ligne,colo,sens);
            contester(&contestation,joueurj,tourde);
            if (contestation==1)
            {
                affichageplateau(plateau);
                return;
            }
            verifmot(plateau, motchoisi, ligne, colo, sens,&verif,*ptourj,&joueurj[tourde]);
        }
         if (choix==2)
        {
            changerlettres(&changement,pnbtotaljetons,&joueurj[tourde],ptab,ptab2);
        }
         if (choix==3)
        {
            passertour(&passer,&joueurj[tourde]);
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
            afficher_bonus(joueurj,nombreJ);
            menutour(&choix);
            afficher_main(&joueurj[tourde]);
            recap(*ptourj,*pnbtotaljetons);
        }
        affichageplateau(plateau);
    }while(verif!=lmot && passer!=1 && quitter!=1 && changement!=1 && contestation!=1);

    score(plateau,motchoisi,ligne,colo,sens,&joueurj[tourde]);
    Color(0,10);
    affichermotplace(plateau,motchoisi,ligne,colo,sens);
    remplissagemain(pnbtotaljetons,&joueurj[tourde],ptab,ptab2);        ///sous programme pour remettre  7 lettres dans chevalet
    afficher_bonus(joueurj,nombreJ);


    if (passer!=1)
    {
        joueurj[tourde].tourpasse=0;
    }

}

void placementmot(char tab[15][15],char *psens,char choixlettres[15], int *pligne, int *pcolo,int *ppasser/*,t_player *pptjoueur*/)
{

        gotoligcol(16,83);
        printf ("Saisisez la ligne et la colonne ou vous voulez placer le mot : ");
        do
        {
            fflush(stdin);
            gotoligcol(17,83);
            printf("Ligne : ");
            scanf("%d",pligne);
            fflush(stdin);
            gotoligcol(18,83);
            printf("Colonne : ");
            scanf("%d",pcolo);
            if (*pligne<0 || *pligne>15 || *pcolo<0 || *pcolo>15)
            {
                gotoligcol(19,83);
                printf("Saisie incorrecte. Recommencez.");
                Sleep(2000);
            }
            effacement(16,83,5,65);
        }while (*pligne<0 || *pligne>15 || *pcolo<0 || *pcolo>15);


        do
        {
            gotoligcol(16,83);
            printf("Veuillez saisir le sens (V pour vertical, H pour horizontal)");
            gotoligcol(17,83);
            printf("du mot commencant a la ligne %d et la colonne %d : ",*pligne,*pcolo);
            gotoligcol(18,83);
            fflush(stdin);
            scanf("%c",psens);
            if (*psens!='V' && *psens!='H')
            {
                gotoligcol(19,83);
                printf("Saisie incorrecte. Recommencez.");
                Sleep(2000);
            }
            effacement(16,83,7,65);
        }while(*psens!='V' && *psens!='H');

        gotoligcol(16,83);
        printf("Saisissez le mot que vous voulez creer avec vos lettres");
        gotoligcol(17,83);
        printf("et celles du plateau : ");
        fflush(stdin);
        scanf("%s",choixlettres);
        Sleep(2000);
        effacement(16,83,3,65);
}

void verifmot(char place[15][15],char motaplacer[15],int lig, int col,char senspla,int *pverif,int tour,t_player *pptjoueur)
{
    int i,j,lmot,dejateste,surmot=0;
    char verificationmain[7];
    char verificationmot[15];
    lmot=strlen(motaplacer);
    *pverif=0;

    ///verification si le mot rentre sur le plateau

    if (senspla=='V')
    {
        if((lmot+lig)>16)
        {
            *pverif=*pverif-1;
            gotoligcol(16,83);
            printf("Le mot depasse du plateau. Saisie impossible.");
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
            printf("Le mot depasse du plateau. Saisie impossible.");
            Sleep(5000);
            effacement(16,83,2,65);
        }
    }

    ///verification si on est au premier 1er tour est ce qu'il y a une lettre au centre

    if (place[7][7]=='#')
    {
        if (( ((lig<8 || col<8) &&(((lmot+col-1)<=8) || ((lmot+lig-1)<=8)))  ||  ((lig>8 || col>8) && (((lmot+col-1)>=8) || ((lmot+lig-1)>=8))) )  ||  (lig!=8 || col!=8))
        {

            if(lig!=8 && senspla=='H')
            {
                *pverif=*pverif-1;
                gotoligcol(16,83);
                printf("Impossible, pas de lettres au centre.");
                Sleep(3000);
                effacement(16,83,1,60);
            }
            if(col!=8 && senspla=='V')
            {
                *pverif=*pverif-1;
                gotoligcol(16,83);
                printf("Impossible, pas de lettres au centre.");
                Sleep(3000);
                effacement(16,83,1,60);
            }
        }

        /*if ((lig>8 || col>8) || ((lig<=8 && col!=8) || ((lmot+lig-1)<8)) || ((col<=8 && lig!=8) || ((lmot+col-1)<8)))
        {
                *pverif=*pverif-1;
                gotoligcol(16,83);
                printf("Impossible, pas de lettres au centre.");
                Sleep(3000);
                effacement(16,83,1,60);
        }*/
    }

    ///verification si les lettres correspondent aux mots

    for (i=0;i<7;i++)
    {
        verificationmain[i]=pptjoueur->pioche[i];
    }
    for (i=0;i<lmot;i++)
    {
        verificationmot[i]=motaplacer[i];
    }



    for (i=0;i<lmot;i++)
    {
        dejateste=0;
        for (j=0;j<7;j++)
        {
            ///verification si une lettre du mot est dans le plateau

            if (place[7][7]!='#')
            {
                if ((place[lig+i-1][col-1]==verificationmot[i]) && (senspla=='V'))
                {
                    verificationmot[i]=' ';
                    *pverif=*pverif+1;
                    dejateste=1;
                    surmot=1;       ///dire que le mot est bien en commun avec les autres mot du plateau
                }
                else if ((dejateste==0) && ((place[lig+i-1][col-1]!=verificationmot[i]) && (place[lig+i-1][col-1]!=' ' ) && (place[lig+i-1][col-1]!='%') && (place[lig+i-1][col-1]!='&')&& (place[lig+i-1][col-1]!='@')&& (place[lig+i-1][col-1]!='$')) && (senspla=='V'))
                {
                    *pverif=*pverif-1;                  ///verification si la lettre est la bonne
                }

                if ((place[lig-1][col+i-1]==verificationmot[i]) && (senspla=='H'))
                {
                    verificationmot[i]=' ';
                    *pverif=*pverif+1;
                    dejateste=1;
                    surmot=1;      ///dire que le mot est bien en commun avec les autres mot du plateau
                }
                else if ((dejateste==0) && ((place[lig-1][col+i-1]!=verificationmot[i]) && (place[lig-1][col+i-1]!=' ' ) && (place[lig-1][col+i-1]!='%') && (place[lig-1][col+i-1]!='&')&& (place[lig-1][col+i-1]!='@')&& (place[lig-1][col+i-1]!='$')) && (senspla=='H'))
                {
                    *pverif=*pverif-1;      ///verification si la lettre est la bonne
                }
            }

            ///verification

            /*if (verificationmot[i]==' ')
            {
                *pverif=*pverif+1;
                dejateste=1;
            }

            else*/
            if (((verificationmot[i]==verificationmain[j]) || (verificationmain[j]=='?')) && (dejateste==0))
            {
                *pverif=*pverif+1;
                verificationmain[j]=' ';
                dejateste=1;
            }
        }
    }


    ///verification si le mot a bien été posé a partir d'un autre

    if(place[7][7]!='#')
    {
        if(surmot==0)
        {
            *pverif=*pverif-1;
        }
    }

    if (lmot!=*pverif)
    {
        gotoligcol(16,83);
        printf("Vous ne pouvez pas placer ce mot !");
        Sleep(2500);
        effacement(16,83,1,65);
    }



    ///une fois verifié transformé la main (a deplacer ou deplacer la contestation)

    if(*pverif==lmot)
    {
        for (i=0;i<7;i++)
        {

            /*printf("test");
            Sleep(20000);*/
           pptjoueur->pioche[i]=verificationmain[i];
        }
    }

    /*afficher_main(pptjoueur);

    for (i=0;i<7;i++)
    {
        printf("%c",pptjoueur->pioche[i]);
        Sleep(500);
    }*/

}

void remplissagemain(int *nb_total_jetons, t_player *pptjoueur, char ptab[27], int ptab2[27])
{
    char lettrerempli;
    int i;

    for(i=0;i<7;i++)
    {
        if(pptjoueur->pioche[i]==' ')
        {
            pioche(&lettrerempli,nb_total_jetons,ptab,ptab2);
            pptjoueur->pioche[i] = lettrerempli;
        }
    }

}

void contester(int *pconcestation,t_player *joueur,int tourde)
{
    FILE* fic=NULL;
    fic=fopen("dictionnaire_scrabble.txt","r");

    char dico[15];
    char motaverifier[15];
    int test=1,i,jcontest,choix2;

    gotoligcol(16,83);
    printf("Un joueur souhaite t'il contester ?(1 pour oui 0 pour non)");
    do
    {
        gotoligcol(17,83);
        scanf("%d",&choix2);
        if(choix2 != 0 && choix2 !=1)
        {
            printf("Un joueur souhaite t'il contester ?(1 pour oui 0 pour non)");
            printf("Saisie incorrecte recommencez.(1 pour oui 0 pour non)");
            Sleep(2500);
            effacement(16,83,3,60);
        }
    }while(choix2 != 0 && choix2 !=1);
    effacement(16,83,3,60);

    if (choix2==1)
    {
        gotoligcol(16,83);
        fflush(stdin);
        do
        {
            printf("quelle joueur veut contester ? (1er, 2eme, 3eme ou 4eme) ");
            fflush(stdin);
            scanf("%d",&jcontest);

            if(jcontest-1 == tourde)
            {
                gotoligcol(18,83);
                printf("saisie incorrecte recommencez");
                effacement(16,83,4,60);
            }
        }while (jcontest == tourde);


        gotoligcol(17,83);
        printf("Choisisez le mot a verifier : ");
        scanf("%s",motaverifier);
        effacement(17,83,2,60);

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
                printf("Le mot existe. Aie, %s qui a conteste perd 5 points",joueur[jcontest-1].nom);
                joueur[jcontest-1].score=joueur[jcontest-1].score-5;
                Sleep(3000);
            }
            else
            {
                *pconcestation=1;
                printf("%s, votre mot n'existe pas, votre tour est passe",joueur[tourde].nom);
                Sleep(3000);
            }
            effacement(16,83,3,65);
        }
    }
}

void conditionvictoire(t_player *pptjoueur, int nb_total_jetons,int nombreJ)
{
    int nb_espace=0,totalpasser=0,i,j;

    if(nb_total_jetons == 0)
    {
        for(i=0; i<nombreJ; i++)
        {
            nb_espace=0;
            {
                for(j=0; j<7; i++)
                {
                    if(pptjoueur[i].pioche[j]==' ')
                    {
                        nb_espace = nb_espace+1;
                    }
                    if(nb_espace==7)
                    {
                        effacement(16,83,9,60);
                        gotoligcol(16,83);
                        printf("La pioche est vide et un joueur a vide son chevalet, la partie est donc terminee.");
                        Sleep(5000);
                        recap_finpartie(pptjoueur,nombreJ);
                    }
                }
            }
        }
    }

    for(i=0; i<nombreJ; i++)
    {
        if(pptjoueur[i].tourpasse == 3)
        {
            totalpasser=totalpasser + 1;
        }
    }


    if(totalpasser==nombreJ)
    {
        effacement(16,83,8,60);
        gotoligcol(16,83);
        printf("Les joueurs sont bloques, la partie est donc terminee.");
        Sleep(5000);
        recap_finpartie(pptjoueur,nombreJ);
    }
}

void recap_finpartie(t_player *pptjoueur,int nombreJ)
{

    effacement(6,81,33,69);
    gotoligcol(15,100);
    printf("RESUME DE LA PARTIE : ");
    Color(0,12);
    gotoligcol(17,83);
    printf("SCORES : ");
    Color(15,0);
    gotoligcol(19,90);
    for(int i=0; i<nombreJ; i++)
    {
        printf("%s : %d   ", pptjoueur[i].nom, pptjoueur[i].score);
    }

    gotoligcol(21,83);
    printf("Merci d'avoir joue !  ");
    system("PAUSE");
   // menu();
}

void afficher_main(t_player *pptjoueur)
{
    int i,j;
    char lettres[27];
    int listepoints[27]= {1,3,3,2,1,4,2,4,1,8,10,1,2,1,1,3,8,1,1,1,1,4,10,10,10,10,0};

    for (i=0; i<26; i++)
    {
        lettres[i]='A'+i;
    }
    lettres[26]='?';

    effacement(7,83,1,60);
    gotoligcol(7,95);
    printf(" Au tour de : ");
    puts(pptjoueur->nom);
    gotoligcol(11,82);
    printf("Vos lettres sont :");
    gotoligcol(13,82);
    for(i=0; i<7; i++)
    {
        for (j=0; j<27; j++)
        {
            if (pptjoueur->pioche[i]==lettres[j])
            {
                printf("%c(%d PTS) ", pptjoueur->pioche[i],listepoints[j]);
            }
        }
    }
}

void score(char pla[15][15],char motplace[15],int lig, int col,char senspla,t_player *pptjoueur)
{
    int i,j,lmot,scoret,vide=0,ajout=0,multiplicateur=1;
    char lettres[27];
    int listepoints[27]= {1,3,3,2,1,4,2,4,1,8,10,1,2,1,1,3,8,1,1,1,1,4,10,10,10,10,0};

    scoret=0;

    for (i=0;i<26;i++)
    {
        lettres[i]='A'+i;
    }
    lettres[27]='?';

    lmot=strlen(motplace);


    for(i=0;i<7;i++)
    {
        if(pptjoueur->pioche[i]==' ')
        {
            vide=vide+1;
        }
    }
    if (vide==7)
    {
        scoret=scoret+50;
    }

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
        scoret=scoret+ajout;
        ajout=0;
    }

    scoret=scoret*multiplicateur;
    pptjoueur->score=pptjoueur->score+scoret;
}

void affichermotplace(char place[15][15],char motaplacer[15],int lig, int col,char senspla)
{
    int lmot,k;

    lmot=strlen(motaplacer);

    if (senspla=='H')
    {
        gotoligcol((lig*2)+6,(col*4)+11);
        for (k=0;k<lmot;k++)
        {
            place[lig-1][col-1+k]=motaplacer[k];
            printf(" %c ",place[lig-1][col-1+k]);
            printf("%c",0xBA);                      ///Horizontalement
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


void affichermotprovi(char place[15][15],char motaplacer[15],int lig, int col,char senspla)
{
    int lmot,k;

    lmot=strlen(motaplacer);

    if (senspla=='H')
    {
        gotoligcol((lig*2)+6,(col*4)+11);
        for (k=0;k<lmot;k++)
        {
            Color(0,15);
            printf(" %c ",motaplacer[k]);
            Color(0,10);
            printf("%c",0xBA);                      ///Horizontalement
        }
    }

    if (senspla=='V')
    {
        for (k=0;k<lmot;k++)
        {
            Color(0,15);
            gotoligcol(((lig+k)*2)+6,(col*4)-2+14-1);                               ///vertcalement
            printf(" %c ",motaplacer[k]);
            gotoligcol(((lig+k)*2+1)+6,(col*4)+14-3);
            Color(0,10);
            printf("%c%c%c",0xCD,0xCD,0xCD);
        }
    }
    Color(15,0);
}


void afficher_bonus(t_player *pptjoueur,int nombreJ)
{
    gotoligcol(28,83);

    for(int i=0; i<nombreJ; i++)
    {
        printf("Score %s : %d  ", pptjoueur[i].nom, pptjoueur[i].score);
    }

    gotoligcol(33,83);
    printf("Systeme de points :");

    Color(11,9);
    gotoligcol(35,85);
    printf(" & ");
    Color(15,0);
    printf(": lettre double");

    Color(9,1);
    gotoligcol(35,125);
    printf(" %c ",37);
    Color(15,0);
    printf(": lettre triple");

    gotoligcol(36,85);
    Color(4,12);
    printf(" @ ");
    Color(15,0);
    printf(": mot double");

    gotoligcol(36,125);
    Color(13,5);
    printf(" $ ");
    Color(15,0);
    printf(": mot triple");

}

void recap(int tourj, int lettresrest)
{
    gotoligcol(25,83);
    printf(" Tour : %d",tourj);
    gotoligcol(25,99);
    printf("%d lettre(s) restante(s)",lettresrest);
}

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
        if (i!=14)                                  ///tracer le millieu
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

void couleurbonus(char tab[15][15],int i, int j)
{
    if (tab[i][j]==tab[1][4] || tab[i][j]==tab[1][12] || tab[i][j]==tab[3][7] || tab[i][j]==tab[3][9] ||
            tab[i][j]==tab[4][1]|| tab[i][j]==tab[4][8] || tab[i][j]==tab[4][15] || tab[i][j]==tab[7][3] ||
            tab[i][j]==tab[7][7] || tab[i][j]==tab[7][9] || tab[i][j]==tab[7][13] || tab[i][j]==tab[8][4] ||
            tab[i][j]==tab[8][12] || tab[i][j]==tab[9][3] || tab[i][j]==tab[9][7] || tab[i][j]==tab[9][9] ||
            tab[i][j]==tab[9][13] || tab[i][j]==tab[12][1]|| tab[i][j]==tab[12][8] || tab[i][j]==tab[12][15]||
            tab[i][j]==tab[13][7] || tab[i][j]==tab[13][9] || tab[i][j]==tab[15][4] || tab[i][j]==tab[15][12])
    {
        Color(0,9);
    }

    else if (tab[i][j]==tab[1][1] || tab[i][j]==tab[1][8] || tab[i][j]==tab[1][15] || tab[i][j]==tab[8][1] ||
            tab[i][j]==tab[8][15]|| tab[i][j]==tab[15][1] || tab[i][j]==tab[15][8] || tab[i][j]==tab[15][15])
    {
        Color(0,13);
    }

    else if (tab[i][j]==tab[2][6] || tab[i][j]==tab[2][10] || tab[i][j]==tab[6][2] || tab[i][j]==tab[6][6] ||
            tab[i][j]==tab[6][10]|| tab[i][j]==tab[6][14] || tab[i][j]==tab[10][2] || tab[i][j]==tab[10][6] ||
            tab[i][j]==tab[10][10]|| tab[i][j]==tab[10][14])
    {
        Color(0,1);
    }

    else if (tab[i][j]==tab[2][2] || tab[i][j]==tab[2][14] || tab[i][j]==tab[3][3] || tab[i][j]==tab[3][13] || tab[i][j]==tab[4][4]|| tab[i][j]==tab[4][12] || tab[i][j]==tab[5][5] || tab[i][j]==tab[5][11] || tab[i][j]==tab[11][5]|| tab[i][j]==tab[11][11] || tab[i][j]==tab[12][4]|| tab[i][j]==tab[12][12] || tab[i][j]==tab[13][3] || tab[i][j]==tab[13][13] || tab[i][j]==tab[14][2]|| tab[i][j]==tab[14][14])

    {
        Color(0,12);
    }
    else
    {
        Color(0,15);
    }
}
