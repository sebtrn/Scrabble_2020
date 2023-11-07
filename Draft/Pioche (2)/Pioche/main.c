#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///Sous-programme pour la pioche
void pioche(char *jeton_tire)
{
    ///Declaration des variables
    srand(time(NULL));
    int nb_total_jetons = 102;
    int ASCII;
    int nbA=9, nbB=2, nbC=2, nbD=3, nbE=15, nbF=2, nbG=2, nbH=2, nbI=8, nbJ=1, nbK=1, nbL=5, nbM=3, nbN=6, nbO=6, nbP=2, nbQ=1, nbR=6, nbS=6, nbT=6, nbU=6, nbV=2, nbW=1, nbX=1, nbY=1, nbZ=1, nbJOKER=2;

    ///Affectation de la valeur
    do
    {
    ASCII = rand()%(27-1+1)+(1);

    ///Conversion valeur-lettre
    if(ASCII==1)
    {
        if(nbA>0)
        {
            *jeton_tire = 'A';
            nbA = nbA - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==2)
    {
        if(nbB>0)
        {
            *jeton_tire = 'B';
            nbB = nbB - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==3)
    {
        if(nbC>0)
        {
            *jeton_tire = 'C';
            nbC = nbC - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==4)
    {
        if(nbD>0)
        {
            *jeton_tire = 'D';
            nbD = nbD - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==5)
    {
        if(nbE>0)
        {
            *jeton_tire = 'E';
            nbE = nbE - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==6)
    {
        if(nbF>0)
        {
            *jeton_tire = 'F';
            nbF = nbF - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==7)
    {
        if(nbG>0)
        {
            *jeton_tire = 'G';
            nbG = nbG - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==8)
    {
        if(nbH>0)
        {
            *jeton_tire = 'H';
            nbH = nbH - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==9)
    {
        if(nbI>0)
        {
            *jeton_tire = 'I';
            nbI = nbI - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==10)
    {
        if(nbJ>0)
        {
            *jeton_tire = 'J';
            nbJ = nbJ - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==11)
    {
        if(nbK>0)
        {
            *jeton_tire = 'K';
            nbK = nbK - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==12)
    {
        if(nbL>0)
        {
            *jeton_tire = 'L';
            nbL = nbL - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==13)
    {
        if(nbM>0)
        {
            *jeton_tire = 'M';
            nbM = nbM - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==14)
    {
        if(nbN>0)
        {
            *jeton_tire = 'N';
            nbN = nbN - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==15)
    {
        if(nbO>0)
        {
            *jeton_tire = 'O';
            nbO = nbO - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==16)
    {
        if(nbP>0)
        {
            *jeton_tire = 'P';
            nbP = nbP - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==17)
    {
        if(nbQ>0)
        {
            *jeton_tire = 'Q';
            nbQ = nbQ - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==18)
    {
        if(nbR>0)
        {
            *jeton_tire = 'R';
            nbR = nbR - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==19)
    {
        if(nbS>0)
        {
            *jeton_tire = 'S';
            nbS = nbS - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==20)
    {
        if(nbT>0)
        {
            *jeton_tire = 'T';
            nbT = nbT - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==21)
    {
        if(nbU>0)
        {
            *jeton_tire = 'U';
            nbU = nbU - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==22)
    {
        if(nbV>0)
        {
            *jeton_tire = 'V';
            nbV = nbV - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==23)
    {
        if(nbW>0)
        {
            *jeton_tire = 'W';
            nbW = nbW - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==24)
    {
        if(nbX>0)
        {
            *jeton_tire = 'X';
            nbX = nbX - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==25)
    {
        if(nbY>0)
        {
            *jeton_tire = 'Y';
            nbY = nbY - 1;
        }

    }
    if(ASCII==26)
    {
        if(nbZ>0)
        {
            *jeton_tire = 'Z';
            nbZ = nbZ - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    if(ASCII==27)
    {
        if(nbJOKER>0)
        {
            *jeton_tire = 'JOKER';
            nbJOKER = nbJOKER - 1;
        }
        else
        {
            ASCII = 0;
        }
    }
    }
    while(ASCII==0);
}
