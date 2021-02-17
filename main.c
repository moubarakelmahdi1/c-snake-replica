#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include "Structures.h"
#include "Generations.h"
#include "Deplacement.h"
#include "Jeu.h"
#include "Menu_Map.h"
#include "Constante.h"

int main()
{
    time_t depart;
    time(&depart);
    color(2,0);
    char selection;
    Affichage_map(Menu);
    while(selection!='0')
    {
        Selection_map(&selection,depart);
    }
}
