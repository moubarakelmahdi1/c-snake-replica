#ifndef GENERATIONS_H_INCLUDED
#define GENERATIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "Structures.h"
#include "Constante.h"
void Genere_fruit(char Tab[hauteur][longueur],Fruit *fruit,Serpent *serpent,Obstacle *obstacle);
void Generer_obstacle(char Tab[hauteur][longueur],Obstacle *obstacle);
int rand_a_b(int min, int max);

#endif // GENERATIONS_H_INCLUDED
