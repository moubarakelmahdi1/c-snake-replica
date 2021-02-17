#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "Structures.h"
#include "Menu_Map.h"
#include "Constante.h"

void Selection_map(char *selection,time_t depart);
void Lance_jeu_statique(time_t depart);
void Lance_jeu_mouvement(int niveau);
void Lance_jeu_crosswall();
void Lance_jeu_vspc();
void Lance_jeu_parfait();
void Mort(Serpent *serpent,int i,time_t depart);
void Modifier_score(Serpent *serpent,int i);

#endif // JEU_H_INCLUDED
