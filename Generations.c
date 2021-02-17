#include "Generations.h"
#include "Constante.h"

//Fonction responsable de la generation des fruits dans la map//
void Genere_fruit(char Tab[hauteur][longueur],Fruit *fruit,Serpent *serpent,Obstacle *obstacle)
{
    int i,j;
    // Je genere une position aleatoire pour mon fruit//
    fruit->position_x=rand_a_b(1,38);
    fruit->position_y=rand_a_b(1,18);
    for(i=0; i<serpent->taille; i++)
    {
        //La position du fruit doit etre differente de celle du serpent et des obstacles//
        while(fruit->position_x==serpent->position_x[i]&&fruit->position_y==serpent->position_y[i])
        {
            fruit->position_x=rand_a_b(1,38);
            fruit->position_y=rand_a_b(1,18);
        }
        for(j=0; j<obstacle->taille; j++)
        {
            while(fruit->position_x==obstacle->position_x[i]&&fruit->position_y==obstacle->position_y[i])
            {
                fruit->position_x=rand_a_b(1,38);
                fruit->position_y=rand_a_b(1,18);
            }
        }
    }
    Tab[fruit->position_y][fruit->position_x]='*';
}

//Fonction responsable de la generation d'obstacles dans la map//
void Generer_obstacle(char Tab[hauteur][longueur],Obstacle *obstacle)
{
    int i;
    for(i=0; i<obstacle->taille; i++)
    {
        //Je genere des position aléatoire pour tout mes obstacles en faisant attention a ce qu'il ne se genere pas au centre de la map, la ou j'initialise mon serpent//
        //Les fruits se genere déjà en dehors des obstacles dans la fonctions précédentes//
        if(i<3)
        {
            obstacle->position_x[i]=rand_a_b(a_,d_);
            obstacle->position_y[i]=rand_a_b(a_,b_);
        }
        else if(i<6)
        {
            obstacle->position_x[i]=rand_a_b(d_,f_);
            obstacle->position_y[i]=rand_a_b(c_,e_);
        }
        else if(i<9)
        {
            obstacle->position_x[i]=rand_a_b(a_,d_);
            obstacle->position_y[i]=rand_a_b(c_,e_);
        }
        else if(i<12)
        {
            obstacle->position_x[i]=rand_a_b(d_,f_);
            obstacle->position_y[i]=rand_a_b(a_,b_);
        }
        Tab[obstacle->position_y[i]][obstacle->position_x[i]]=mur;
    }

}

//Fonction qui renvoie un nombre aléatoire dans un intervalle borné//
//La fonction à été prise d'internet car on ne connaissait pas les différentes commandes qui la constituent//
int rand_a_b(int min, int max)
{
    static int rand_is_seeded = 0;
    if(!rand_is_seeded)
    {
        srand(time(NULL));
        rand_is_seeded = 1;
    }
    return rand()%(max-min+1) + min;
}
