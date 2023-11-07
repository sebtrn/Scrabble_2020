#include "fichier.h"

///Sous-programme introdisant ce qu'est reellement le Scrabble
void quest_ce_que_le_scrabble()
{
    ///Declaration de variable
    int choix;

    printf(" Le Scrabble est un jeu de lettres que l’on peut jouer a deux, trois ou quatre joueurs. Les parties opposant deux joueurs, assis face a face, sont les seules pratiquees en compétition. C'est pourquoi le present reglement ne traite que des regles qui sont sont facilement applicables aux parties a trois ou quatre joueurs. Cela consiste a former des mots meles sur un plateau avec des lettres de valeurs différentes. Les cases de la grille, contenant des symboles, permettent de multiplier la valeur des lettres ou des mots. Le gagnant est celui qui cumule le plus grand nombre de points a la fin de la partie.\n");

    ///Quitter
    do
    {
        printf("Retourner au menu d'aide (taper 1) ? ");
        scanf("%d", &choix);
    }
    while("choix!=1");
    if(choix==1)
    {
        system("CLS");
        menu_aide();
    }
}

///Sous-programme montrant comment engager la partie
void engager_la_partie()
{
    ///Declaration de variable
    int choix;

    printf(" Quel joueur commence la partie ?\n\n Le joueur debutant la partie est, en general, designe par le logiciel d’un tournoi, dans le but d’equilibrer le nombre de fois ou chaque joueur commence. Dans le cas contraire, chaque joueur tire une lettre; celui qui obtient la lettre la plus proche de A debutera la partie. Les jokers ne comptent pas, il faut de tirer une autre lettre. De la meme façon, les deux joueurs procedent a un nouveau tirage s’ils ont tire la meme lettre. Une fois determine le joueur commencant la partie, les lettres ayant servi au tirage au sort sont remises dans la pioche.\n\n Le premier tirage\n\nLe joueur qui commence la partie tire ses sept premieres lettres. C’est ensuite aux autres joueurs de tirer a la suite leur sept lettres.\n");

    ///Quitter
    do
    {
        printf("Retourner au menu d'aide (taper 1) ? ");
        scanf("%d", &choix);
    }
    while("choix!=1");
    if(choix==1)
    {
        system("CLS");
        menu_aide();
    }
}

///Sous-programme montrant comment jouer au Scrabble
void tour_de_jeu()
{
    ///Declaration de variable
    int choix;

    printf("Le joueur selectionne parmi les lettres qu’il a tirees, dans la pioche, et pose une ou plusieurs lettres afin de former de nouveaux mots sur le plateau, horizontalement ou verticalement. Il n'est pas possible de poser un mot en diagonale. Le premier mot doit faire au moins deux lettres et recouvrir la case centrale (matérialisée par le caractère ‘#’) et les mots suivants doivent s'appuyer sur des mots deja places. Le score d'un mot est calcule en additionnant la valeur de toutes les lettres des nouveaux mots formes (y compris celles deja posées sur le plateau). Si une nouvelle lettre posee recouvre une case « lettre compte double » (caractere ‘&’) ou « lettre compte triple » (caractere ‘%’), alors la valeur de la lettre est multipliee par 2 ou par 3 ; si cette case fait partie de 2 nouveaux mots formes, horizontalement et verticalement, elle compte double ou triple dans les deux sens. Si une case « mot compte double » (caractere ‘@’) ou « mot compte triple » (caractere ‘§’) a ete recouverte, la valeur du mot est doublee ou triplee. Si en recouvrant cette case, cela forme deux mots horizontalement et verticalement, la valeur des deux mots est multipliee par 2 ou par 3. Les cases multiplicatrices ne servent plus une fois qu’elles sont recouvertes par des lettres. Placer directement ses sept lettres sur la grille apporte une prime de 50 points. Ce genre de coup est nomme « scrabble ». Après avoir pose ses lettres et annonce son score, le tour est fini. Les actions possibles sont : passer son tour, changer une ou plusieurs lettres de son jeu (dans ce cas il est impossible de poser un nouveau mot).\n");

    ///Quitter
    do
    {
        printf("Retourner au menu d'aide (taper 1) ? ");
        scanf("%d", &choix);
    }
    while("choix!=1");
    if(choix==1)
    {
        system("CLS");
        menu_aide();
    }
}

///Sous-programme montrant comment contester
void contester()
{
    ///Declaration de variable
    int choix;

    printf(" Il est possible de demander a verifier la existance d'un mot pose sur le plateau, dans le dictionnaire du logiciel, convenu entre les joueurs : le dictionnaire verifiera lui-meme la validite du mot. Si un mot conteste n'est pas valable, le joueur reprend ses lettres et ne marque aucun point pour le coup joue. A l’inverse, si le mot conteste est valable, le contestateur perd dix points.\n");

    ///Quitter
    do
    {
        printf("Retourner au menu d'aide (taper 1) ? ");
        scanf("%d", &choix);
    }
    while("choix!=1");
    if(choix==1)
    {
        system("CLS");
        menu_aide();
    }
}

///Sous-programme montrant la fin de la partie
void fin_de_partie()
{
    ///Declaration de variable
    int choix;

    printf(" La partie est finie lorsque la pioche est vide et qu'un joueur place ses dernieres lettres sur le plateau. Il peut ajouter, a son score, la valeur des lettres restant a ses adversaires, qui dans le meme temps, doivent deduire de leur score la valeur des lettres qui leur restent. Le vainqueur est celui qui a le plus de points a la fin de la partie.\n");

    ///Quitter
    do
    {
        printf("Retourner au menu d'aide (taper 1) ? ");
        scanf("%d", &choix);
    }
    while("choix!=1");
    if(choix==1)
    {
        system("CLS");
        menu_aide();
    }
}
