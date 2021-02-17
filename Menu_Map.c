#include "Menu_Map.h"
#include "Constante.h"

//Fonction permettant de centrer le curseur de notre console à une position x_y et donc permettant de ne pas avoir à reafficher tout les caractères de la map//
void centrer(int x,int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

//Fonction permettant de changer la couleur//
void color(int t,int f)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}

//Map game over//
const char Game_Over[hauteur][longueur]=
{
    "=======================================",
    "===============  MORT   ===============",
    "=======================================",
    "=--..,_                   _,.--.      =",
    "=   '.'.                .'_  X  `;.__.=",
    "=      '.'.            .'.'`'---'`   '=",
    "=        '.`'--....--'`.'             =",
    "=          '--....--'                 =",
    "=                                     =",
    "=          // Game Over //            =",
    "=                                     =",
    "=                                     =",
    "=                                     =",
    "=                                     =",
    "=                                     =",
    "=              9-RETOUR               =",
    "=                                     =",
    "=======================================",
};

//Map menu//
const char Menu[hauteur][longueur]=
{
    "=======================================",
    "===============  SNAKE  ===============",
    "=======================================",
    "=--..,_                   _,.--.      =",
    "=   '.'.                .'_  o  `;.__.=",
    "=      '.'.            .'.'`'---'`   '=",
    "=        '.`'--....--'`.'             =",
    "=          '--....--'                 =",
    "=                                     =",
    "=              1-JOUER                =",
    "=                                     =",
    "=              2-REGLES               =",
    "=                                     =",
    "=              3-SCORE                =",
    "=                                     =",
    "=              0-QUITTER              =",
    "=                                     =",
    "=======================================",
};

//Map Règles//
const char Regles[hauteur][longueur]=
{
    "=======================================",
    "===============  REGLES ===============",
    "=======================================",
    "=--..,_                   _,.--.      =",
    "=   '.'.                .'_  o  `;.__.=",
    "=      '.'.            .'.'`'---'`   '=",
    "=        '.`'--....--'`.'             =",
    "=          '--....--'                 =",
    "=                                     =",
    "=  Touches: z//q//s//d                =",
    "=                                     =",
    "=  Objectif: Ramassez le plus de      =",
    "=  fruit tout en evitant les          =",
    "=  obstacles!                         =",
    "=  Les obstacles sont modelises par   =",
    "=  petits carres,les fruits par des *.=",
    "=              9-RETOUR               =",
    "=                                     =",
    "=======================================",
};

//Map de choix de jeu//
const char Jeu[hauteur][longueur]=
{
    "=======================================",
    "===============  JOUER  ===============",
    "=======================================",
    "=--..,_                   _,.--.      =",
    "=   '.'.                .'_  o  `;.__.=",
    "=      '.'.            .'.'`'---'`   '=",
    "=        '.`'--....--'`.'             =",
    "=          '--....--'                 =",
    "=                                     =",
    "=        4-Snake statique             =",
    "=        5-Snake en mouvement         =",
    "=        6-Crosswall                  =",
    "=        7-Joueur VS PC               =",
    "=        8-Snake Parfait              =",
    "=                                     =",
    "=              9-RETOUR               =",
    "=                                     =",
    "=======================================",
};

//Map de galerie des scores//
const char Score[hauteur][longueur]=
{
    "=======================================",
    "===============  SCORE  ===============",
    "=======================================",
    "=--..,_                   _,.--.      =",
    "=   '.'.                .'_  o  `;.__.=",
    "=      '.'.            .'.'`'---'`   '=",
    "=        '.`'--....--'`.'             =",
    "=          '--....--'                 =",
    "=                                     =",
    "=                                     =",
    "=                                     =",
    "=                                     =",
    "=                                     =",
    "=                                     =",
    "=                                     =",
    "=                                     =",
    "=               9-Retour              =",
    "=======================================",
};

//Map choix des niveaux du mode de jeu serpent en mouvement//
const char Mouvement_niveau[hauteur][longueur]=
{
    "=======================================",
    "===============  JOUER  ===============",
    "=======================================",
    "=--..,_                   _,.--.      =",
    "=   '.'.                .'_  o  `;.__.=",
    "=      '.'.            .'.'`'---'`   '=",
    "=        '.`'--....--'`.'             =",
    "=          '--....--'                 =",
    "=                                     =",
    "=               a-Niveau 1            =",
    "=                                     =",
    "=               b-Niveau 2            =",
    "=                                     =",
    "=               c-Niveau 3            =",
    "=                                     =",
    "=               9-Retour              =",
    "=                                     =",
    "=======================================",
};

//Map fin du mode statique//
const char Fin[hauteur][longueur]=
{
    "=======================================",
    "===============  FIN    ===============",
    "=======================================",
    "=--..,_                   _,.--.      =",
    "=   '.'.                .'_  o  `;.__.=",
    "=      '.'.            .'.'`'---'`   '=",
    "=        '.`'--....--'`.'             =",
    "=          '--....--'                 =",
    "=                                     =",
    "=         Le temps est ecoule         =",
    "=                                     =",
    "=                                     =",
    "=                                     =",
    "=                                     =",
    "=                                     =",
    "=                                     =",
    "=               9-Retour              =",
    "=======================================",
};

//Map fin du mode Joueur vs PC//
const char Fin_pc[hauteur][longueur]=
{
    "=======================================",
    "===============  FIN    ===============",
    "=======================================",
    "=--..,_                   _,.--.      =",
    "=   '.'.                .'_  o  `;.__.=",
    "=      '.'.            .'.'`'---'`   '=",
    "=        '.`'--....--'`.'             =",
    "=          '--....--'                 =",
    "=                                     =",
    "=                                     =",
    "=      Fin du combat Joueur vs PC     =",
    "=                                     =",
    "=                                     =",
    "=                                     =",
    "=                                     =",
    "=                                     =",
    "=               9-Retour              =",
    "=======================================",
};

//Fonction qui initialise le labyrinthe//
void Initialisation_tableau(char Tab[hauteur][longueur])
{
    int i,j;
    centrer(0,0);
    for (i=0; i<hauteur; i++)
    {
        for(j=0; j<longueur; j++)
        {
            if(i==0||j==0||j==longueur-1||i==hauteur-1)
            {
                //Cette fonction rempli les bords de mon tableau par des rectangles compacts//
                Tab[i][j]=Bordure;
            }
            else
            {
                Tab[i][j]=' ';
            }
        }
    }
}

//Fonction qui affiche une map prise en paramètre//
void Affichage_map(char map[hauteur][longueur])
{
    centrer(0,0);
    int i,j;
    for (i=0; i<hauteur; i++)
    {
        for(j=0; j<longueur; j++)
        {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}

//Fonction permettant de fusionner la Map et le serpent//
void Afficher_tableau_serpent(char Tab[hauteur][longueur],Serpent serpent)
{
    centrer(0,0);
    Afficher_Serpent(Tab,serpent);
    int i,j;
    for (i=0; i<hauteur; i++)
    {
        for(j=0; j<longueur; j++)
        {
            printf("%c",Tab[i][j]);
        }
        printf("\n");
    }
}

//Fonction permettant de fusionner la map et le deuxieme serpent pour le mode de jeu Joueur vs PC//
void Afficher_tableau_serpent2(char Tab[hauteur][longueur],Serpent serpent)
{
    centrer(0,0);
    Afficher_Serpent2(Tab,serpent);
}

//Fonction permettant de fusionner la map et le serpent Snake Parfait//
void Afficher_tableau_serpent3(char Tab[hauteur][longueur],Serpent serpent)
{
    centrer(0,0);
    Afficher_Serpent2(Tab,serpent);
    int i,j;
    for (i=0; i<hauteur; i++)
    {
        for(j=0; j<longueur; j++)
        {
            printf("%c",Tab[i][j]);
        }
        printf("\n");
    }
}

//Fonction permettant d'afficher un record dans la galerie des scores//
void Afficher_score()
{
    FILE* fichier = NULL;
    int score[3] = {0};
    int i;
    int j=1;
    fichier = fopen("record.txt", "r");

    if (fichier != NULL)
    {
        //Les scores sont lus et enregistrés à partir d'un fichier texte se trouvant dans le même dossier que le main.c//
        fscanf(fichier, "%d %d %d", &score[0], &score[1], &score[2]);
        Affichage_map(Score);
        for(i=0; i<3; i++)
        {
            centrer(5,9+i+j);
            j=j+1;
            printf("Meilleur score niveau %d: %d",i+1,score[i]);
        }
        centrer(0,0);
        fclose(fichier);
    }
}
