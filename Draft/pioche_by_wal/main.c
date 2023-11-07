#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    ///Declaration des variables

    srand(time(NULL));
    int i,j;
    int nb_total_jetons = 102;
    char lettrespioche[27];
    int nblettresrestantes[27] = {9, 2, 2, 3, 15, 2, 2, 2, 8, 1, 1, 5, 3, 6, 6, 2, 1, 6, 6, 6, 6, 2, 1, 1, 1, 1, 2};

    for (i=0;i<26;i++)
    {
        lettrespioche[i]='A'+i;
    }
    lettrespioche[27]='!';

    j = rand()%(27-1+1)+(1);
    if (nblettresrestantes[j]!=0)
    {
        *jeton_tire=lettrespioche[j];
        nblettresrestantes[j]=nblettresrestantes[j]-1;
    }


    return 0;
}
