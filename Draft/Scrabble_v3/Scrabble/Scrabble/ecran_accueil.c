#include "fichier.h"

///Sous-programme pour la premiere page de presentation
void ecran_accueil()
{
    couleur(15,3);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t   ////////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t\t\t\t\t   ///                                                                          ///\n");
    printf("\t\t\t\t\t\t\t   ///   _____    _____    _____    _____    _____    _____             _____   ///\n");
    printf("\t\t\t\t\t\t\t   ///  |        |        |     |  |     |  |     |  |     |  |        |        ///\n");
    printf("\t\t\t\t\t\t\t   ///  |__ __   |        |_____|  |_____|  |____/   |____/   |        |_____   ///\n");
    printf("\t\t\t\t\t\t\t   ///        |  |        |    |   |     |  |     |  |     |  |        |        ///\n");
    printf("\t\t\t\t\t\t\t   ///   _____|  |_____   |     |  |     |  |_____|  |_____|  |_____   |_____   ///\n");
    printf("\t\t\t\t\t\t\t   ///                                                                          ///\n");
    printf("\t\t\t\t\t\t\t   ///                                                                          ///\n");
    printf("\t\t\t\t\t\t\t   ////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t Waldeck-L-ernst FELIX");
    printf(" %c ", 126);
    printf("Sebastien TRAN");
    printf(" %c ", 126);
    printf("Dany KUOY");
    sleep(7);
    couleur(15,0);
    system("CLS");
    menu();
}
