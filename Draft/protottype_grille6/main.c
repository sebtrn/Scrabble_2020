#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

///a mettre dans le main quand on mettra le plateau en sous programme d'ailleurs faudra mettre un message pour dire de mettre en plein d'ecran sinon chelou

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

    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,14*16+0);

    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            plat[i][j]=' ';
        }
    }


    plat[7][7]='#';         ///point de depart


    for (i=1;i<15;i++)
    {
        j=i;
        plat[i][j]='@';     ///mot double
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
    plat[0][3]='&';
    plat[0][11]='&';
    plat[3][14]='&';
    plat[11][0]='&';
    plat[11][14]='&';
    plat[14][3]='&';
    plat[14][11]='&';


    plat[0][14]=245;
    plat[14][14]=245;
    plat[0][0]=245;
    plat[14][0]=245;
    plat[0][7]=245;        ///mot triple
    plat[7][0]=245;
    plat[7][7]=245;
    plat[14][7]=245;
    plat[7][14]=245;

    plat[1][5]='%';
    plat[1][9]='%';
    plat[5][1]='%';
    plat[5][5]='%';
    plat[5][9]='%';
    plat[5][13]='%';       /// lettre triple
    plat[9][1]='%';
    plat[9][5]='%';
    plat[9][9]='%';
    plat[9][13]='%';
    plat[13][5]='%';
    plat[13][9]='%';



}


int main()//void affichageplate(char plate[15][15])
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    //SetConsoleTextAttribute(H,14*16+0);

    int i,j,k;
    char plate[15][15];

    ///mise en place*/

    initialisationplateau(plate);

    ///affichage du plate
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
        if (i==0)
        {
            printf("%c",0xDA);
            for (k=0;k<29;k++)
            {
                if (k%2==1)
                {
                   printf("%c",0xC2);                   //tracer le haut
                }
                if ((k+1)%2==1)
                {
                   printf("%c%c%c",0xC4,0xC4,0xC4);
                }
            }
            printf("%c\n",0xBF);
        }
        printf("%c ",0xB3);
        for(j=0;j<15;j++)
        {
            if (plate[i][j]=='#')                        ///modif a faire pour couleur
            {
               SetConsoleTextAttribute(H,14*16+4);
            }
            if (plate[i][j]=='&')                        ///couleur lettre double
            {
                SetConsoleTextAttribute(H,14*16+11);
            }
            if (plate[i][j]=='@')                       ///couleur mot double
            {
                SetConsoleTextAttribute(H,14*16+12);
            }
            if (plate[i][j]==245)                       ///couleur mot triple
            {
                SetConsoleTextAttribute(H,14*16+4);
            }
            if (plate[i][j]=='%')                       ///couleur lettre triple
            {
                SetConsoleTextAttribute(H,14*16+1);
            }
            printf("%c ",plate[i][j]);
            SetConsoleTextAttribute(H,14*16+0);
            printf("%c ",0xB3);
        }
        printf (" %d\n",i+1);
                                                        //tracer le millieu
        if (i!=14)
        {
            printf("%c",0xC3);
            for (k=0;k<29;k++)
            {
                if (k%2==1)
                {
                    printf("%c",0xC5);
                }
                if ((k+1)%2==1)
                {
                    printf("%c%c%c",0xC4,0xC4,0xC4);
                }
            }
            printf("%c\n",0xB4);
        }
        else
        {
            printf("%c",0xC0);
            for (k=0;k<29;k++)
            {
                if (k%2==1)
                {
                    printf("%c",0xC1);
                }
                if ((k+1)%2==1)
                {
                    printf("%c%c%c",0xC4,0xC4,0xC4);
                }
            }
            printf("%c\n",0xD9);
        }
    }
    return 0;
}
