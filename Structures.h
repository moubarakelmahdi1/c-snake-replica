#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "Constante.h"
//Structure du serpent//
struct Serpent
{
    int position_x[max_tab];
    int position_y[max_tab];
    int taille;
    int etat;
    int vie;
};
typedef struct Serpent Serpent;

//Structure du fruit//
struct Fruit
{
    int position_x;
    int position_y;
};
typedef struct Fruit Fruit;

//Structure de l'obstacle//
struct Obstacle
{
    int position_x[max_tab];
    int position_y[max_tab];
    int taille;
};
typedef struct Obstacle Obstacle;

#endif // STRUCTURES_H_INCLUDED
