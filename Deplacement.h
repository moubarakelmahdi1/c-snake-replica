#ifndef DEPLACEMENT_H_INCLUDED
#define DEPLACEMENT_H_INCLUDED

#include "Structures.h"
#include "Constante.h"
void Deplace(Serpent *serpent,char Tab[hauteur][longueur],char *direction,int i);
void Deplace_m(Serpent *serpent,char Tab[hauteur][longueur],char *direction,int i,char sauvegarde);
void Deplace_c(Serpent *serpent,char Tab[hauteur][longueur],char *direction,int i,char sauvegarde);
void Deplace_v(Serpent *serpent,char Tab[hauteur][longueur],char *direction,int i,char sauvegarde);
void Deplace_v2(Serpent *serpent,char Tab[hauteur][longueur],Fruit *fruit,char *direction,int i,char sauvegarde);
void Deplacement_statique(Serpent *serpent,char Tab[hauteur][longueur],char *direction);
void Deplacement_mouvement(Serpent *serpent,char Tab[hauteur][longueur],char *direction,int niveau);
void Deplacement_crosswall(Serpent *serpent,char Tab[hauteur][longueur],char *direction);
void Deplacement_vspc(Serpent *serpent,char Tab[hauteur][longueur],char *direction);
void Deplacement_vspc2(Serpent *serpent,char Tab[hauteur][longueur],Fruit *fruit,char *direction,int p);

#endif // DEPLACEMENT_H_INCLUDED
