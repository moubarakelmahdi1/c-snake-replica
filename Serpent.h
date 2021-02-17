#ifndef SERPENT_H_INCLUDED
#define SERPENT_H_INCLUDED

#include "Structures.h"
#include "Constante.h"
void Initialiser_serpent(Serpent *serpent);
void Afficher_Serpent(char Tab[hauteur][longueur],Serpent serpent);
void Afficher_Serpent2(char Tab[hauteur][longueur],Serpent serpent);
void Incremente_serpent(Serpent *serpent,Fruit *fruit,char Tab[hauteur][longueur],Obstacle *obstacle);
void Initialiser_serpent2(Serpent *serpent);
void chemin_plus_proche(Serpent *serpent,Fruit *fruit,char Tab[hauteur][longueur],char *direction,char sauvegarde);

#endif // SERPENT_H_INCLUDED
