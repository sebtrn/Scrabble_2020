#include "fichier.h"

///Sous-programme chronometrant
void chronometre(int *N)            //N= temps max saisi préalablement
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
