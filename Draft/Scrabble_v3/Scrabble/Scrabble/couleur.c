#include "fichier.h"

void couleur(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
/*  0 : Noir
    1 : Bleu fonc�
    2 : Vert fonc�
    3 : Turquoise 1
    4 : Rouge fonc�
    5 : Violet
    6 : Vert caca d'oie
    7 : Gris clair
    8 : Gris fonc�
    9 : Bleu fluo
    10 : Vert fluo
    11 : Turquoise 2
    12 : Rouge fluo
    13 : Violet 2
    14 : Jaune
    15 : Blanc
*/
