#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void chronometre(int *N)            //N= temps max saisi pr�alablement
{
    ///Declaration de variable
    int i;

    ///Chronometre
    for(i=(*N);i>0;i--)
    {
        system("CLS");
        printf("Il vous reste %dsecondes", i);
        sleep(1);
    }
}
