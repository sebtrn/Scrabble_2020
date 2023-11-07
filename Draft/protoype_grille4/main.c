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
    char plateau[16][15];

    ///mise en place

    for(i=1;i<16;i++)
    {
        for(j=0;j<16;j++)
        {
            plateau[i][j]=' ';
        }
    }

    for(j=0;j<15;j++)
    {
        plateau[0][j]='A'+j;                        //mise en place des lettres pour se reperer
    }

    ///test
    printf("Seb dany essayez de remplir la case D9 :\n");
    scanf("%c",&plateau[9][4-1]);

    ///affichage du plateau

    //gotoligcol(5,0);

    for(i=0;i<16;i++)
    {
        if (i==0)
        {
            for(j=0;j<15;j++)
            {
                printf("  %c ",plateau[i][j]);                        //affichage des lettres pour se reperer
            }
            printf("\n");
        }

        if (i==1)
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


        if(i!=0)
        {
            printf("%c ",0xB3);
            for(j=0;j<15;j++)
            {

                printf("%c %c ",plateau[i][j],0xB3);

            }
            printf (" %d\n",i);
                                                                    //tracer le millieu
            if (i!=15)
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

    }
    return 0;
}
