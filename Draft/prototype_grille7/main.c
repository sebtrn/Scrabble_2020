#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

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

int main () //void affichageplateau(char plate[15][15])
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    int i,j,k;
    char plate[15][15];

    initialisationplateau(plate);

    ///affichage du plateau

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
            printf("%c ",0xBA);
        }
        printf (" %d\n",i+1);
                                                        //tracer le millieu
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
}
