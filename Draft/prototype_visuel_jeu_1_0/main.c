#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

void gotoligcol(int lig,int col);

void gotoligcol(int lig,int col)
{
    COORD mycoord;
    mycoord.X=col;
    mycoord.Y=lig;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),mycoord);
}
int main()
{
    int i,j;

    /*gotoligcol(5,10);
    printf("%c",0xDA);
    for (j=11;j<150;j++)
    {
        gotoligcol(5,j);
        printf("%c",0xC4);
    }
    gotoligcol(5,151);
    printf("%c",0xBF);*/

    for(i=5;i<35;i++)
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
            if ((i==10 || i==25 || i==30 || i==34) && j>=80)
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

            if (i==34)
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
    return 0;
}
