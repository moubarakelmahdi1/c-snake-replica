#ifndef MENU_MAP_H_INCLUDED
#define MENU_MAP_H_INCLUDED

#include "Constante.h"
#include "Structures.h"
void centrer(int x,int y);
void color(int t,int f);
const char Labyrinthe[hauteur][longueur];
const char Game_Over[hauteur][longueur];
const char Menu[hauteur][longueur];
const char Regles[hauteur][longueur];
const char Jeu[hauteur][longueur];
const char Score[hauteur][longueur];
const char Mouvement_niveau[hauteur][longueur];
const char Fin[hauteur][longueur];
const char Fin_pc[hauteur][longueur];
void Initialisation_tableau(char Tab[hauteur][longueur]);
void Affichage_map(char map[hauteur][longueur]);
void Afficher_tableau_serpent(char Tab[hauteur][longueur],Serpent serpent);
void Afficher_tableau_serpent2(char Tab[hauteur][longueur],Serpent serpent);
void Afficher_tableau_serpent3(char Tab[hauteur][longueur],Serpent serpent);
void Afficher_score();

#endif // MENU_MAP_H_INCLUDED
