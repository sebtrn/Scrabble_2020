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

int main()
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,14*16+0);

    int i,j,k;
    char plateau[15][15];

    ///mise en place


    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            plateau[i][j]='*';
        }
    }

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
            printf("%c %c ",plateau[i][j],0xB3);
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
