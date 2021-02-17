#include "Serpent.h"
#include "Constante.h"

//Initialisation du serpent Joueur//
void Initialiser_serpent(Serpent *serpent)
{
    serpent->position_x[0]=19;
    serpent->position_y[0]=9;
    serpent->position_x[1]=18;
    serpent->position_y[1]=9;
    serpent->position_x[2]=17;
    serpent->position_y[2]=9;
    serpent->taille=3;
    serpent->etat=1;
    serpent->vie=5;
    //Cette fonction place mon serpent au centre de la map avec 2 morceau de queue.//
}

//Initialisation du serpent PC//
void Initialiser_serpent2(Serpent *serpent)
{
    serpent->position_x[0]=19;
    serpent->position_y[0]=8;
    serpent->position_x[1]=18;
    serpent->position_y[1]=8;
    serpent->position_x[2]=17;
    serpent->position_y[2]=8;
    serpent->taille=3;
    serpent->etat=1;
    //Meme fonction qu'avant sauf que celle ci est destinée au serpent de l'IA du mode Joueur vs PC. Ce serpent a une position de départ différente//
}

//Fonction permettant d'afficher le serpent Joueur//
void Afficher_Serpent(char Tab[hauteur][longueur],Serpent serpent)
{
    int i;
    //Le serpent joueur est représenté par des 'o' pour le corps et un 'O' pour la tête//
    for(i=serpent.taille-1; i>0; i--)
    {
        Tab[serpent.position_y[i]][serpent.position_x[i]]='o';
    }
    Tab[serpent.position_y[0]][serpent.position_x[0]]='O';
}

//Fonction permettant d'afficher le serpent PC du mode joueur VS pc//
void Afficher_Serpent2(char Tab[hauteur][longueur],Serpent serpent)
{
    int i;
    //Le serpent joueur est représenté par des 'x' pour le corps et un 'X' pour la tête//
    for(i=serpent.taille-1; i>0; i--)
    {
        Tab[serpent.position_y[i]][serpent.position_x[i]]='x';
    }
    Tab[serpent.position_y[0]][serpent.position_x[0]]='X';
}

//Fonction qui augmente la taille d'un serpent quand celui ci mange un fruit//
void Incremente_serpent(Serpent *serpent,Fruit *fruit,char Tab[hauteur][longueur],Obstacle *obstacle)
{
    if(serpent->position_x[0]==fruit->position_x&&serpent->position_y[0]==fruit->position_y)
    {
        //Cette fonction permet d'incrémenter la taille de mon serpent s'il se trouve dans la même position qu'un fruit, et change les coordonnées du fruit en réutilisant la fonction Genere_fruit//
        serpent->taille=serpent->taille+1;
        serpent->position_y[serpent->taille-1]=serpent->position_y[serpent->taille-2];
        serpent->position_x[serpent->taille-1]=serpent->position_x[serpent->taille-2];
        Genere_fruit(Tab,fruit,serpent,obstacle);
    }
}

//Fonction qui permet de selectionner la direction qui permet d'aller le plus rapidement vers le fruit//
void chemin_plus_proche(Serpent *serpent,Fruit *fruit,char Tab[hauteur][longueur],char *direction,char sauvegarde)
{
    float distance1;
    float distance2;
    float distance3;
    float distance4;
    //Je me sert du principe d'inégalité triangulère pour calculer la distance minimale.//
    //Elle correspond au plus petit hypothénus des différents triangles formés par le fruit et les éventuelles positions du serpent//
    // Formule: Dab=sqrt((xb-xa)²+(yb-ya)²)//
    distance1=sqrt((serpent->position_x[0]-fruit->position_x)*(serpent->position_x[0]-fruit->position_x)+(serpent->position_y[0]-1-fruit->position_y)*(serpent->position_y[0]-1-fruit->position_y));
    distance2=sqrt((serpent->position_x[0]-fruit->position_x)*(serpent->position_x[0]-fruit->position_x)+(serpent->position_y[0]+1-fruit->position_y)*(serpent->position_y[0]+1-fruit->position_y));
    distance3=sqrt((serpent->position_x[0]-1-fruit->position_x)*(serpent->position_x[0]-1-fruit->position_x)+(serpent->position_y[0]-fruit->position_y)*(serpent->position_y[0]-fruit->position_y));
    distance4=sqrt((serpent->position_x[0]+1-fruit->position_x)*(serpent->position_x[0]+1-fruit->position_x)+(serpent->position_y[0]-fruit->position_y)*(serpent->position_y[0]-fruit->position_y));
    int i;
    //Ici, je vérifie si il y a des morceaux de queu entre le serpent et le fruit pour decider de prendre un autre chemin. Cela permet à mon IA de durer plus longtemps//
    for(i=serpent->position_y[0]; i<fruit->position_y; i++)
    {
        if(Tab[i][fruit->position_x]=='x')
        {
            //Je change la plus petite distance minimale en une plus grande si je ne veux pas l'utiliser//
            distance1=distance1+10;
            break;
        }
    }
    for(i=fruit->position_y; i<serpent->position_y[0]; i++)
    {
        if(Tab[i][fruit->position_x]=='x')
        {
            distance2=distance2+10;
            break;
        }
    }
    for(i=serpent->position_x[0]; i<fruit->position_x; i++)
    {
        if(Tab[fruit->position_x][i]=='x')
        {
            distance3=distance3+10;
            break;
        }
    }
    for(i=fruit->position_x; i<serpent->position_x[0]; i++)
    {
        if(Tab[fruit->position_x][i]=='x')
        {
            distance4=distance4+10;
            break;
        }
    }
    //Je décide de la nouvelles position de mon serpent en fonction de la distance minimale//
    if(distance1<=distance2&&distance1<=distance3&&distance1<=distance4&&sauvegarde!='s'&&*direction!='s')
    {
        *direction='z';
    }
    if(distance2<=distance1&&distance2<=distance3&&distance2<=distance4&&sauvegarde!='z'&&*direction!='z')
    {
        *direction='s';
    }
    if(distance3<=distance1&&distance3<=distance2&&distance3<=distance4&&sauvegarde!='d'&&*direction!='d')
    {
        *direction='q';
    }
    if(distance4<=distance1&&distance4<=distance2&&distance4<=distance3&&sauvegarde!='q'&&*direction!='q')
    {
        *direction='d';
    }
}

