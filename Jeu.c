#include "jeu.h"
#include "Constante.h"

//Fonction qui permet le switch de map dans le menu//
void Selection_map(char *selection,time_t depart)
{
    //Cette fonction me permet la création d'un menu interactif ou l'utilisateur peut se rendre dans chaque carte en appuyant sur une touche//
    //Elle me permet aussi le lancement des jeux//
    *selection=getch();
    switch(*selection)
    {
    case '1':
        system("cls");
        Affichage_map(Jeu);
        break;
    case '2':
        system("cls");
        Affichage_map(Regles);
        break;
    case '3':
        system("cls");
        Affichage_map(Score);
        Afficher_score();
        break;
    case '4':
        system("cls");
        Lance_jeu_statique(depart);
        break;
    case '5':
        system("cls");
        Affichage_map(Mouvement_niveau);
        break;
    case 'a':
        system("cls");
        Lance_jeu_mouvement(100);
        break;
    case 'b':
        system("cls");
        Lance_jeu_mouvement(50);
        break;
    case 'c':
        system("cls");
        Lance_jeu_mouvement(20);
        break;
    case '6':
        system("cls");
        Lance_jeu_crosswall();
        break;
    case '7':
        system("cls");
        Lance_jeu_vspc();
        break;
    case '8':
        system("cls");
        Lance_jeu_parfait();
        break;
    case '9':
        system("cls");
        Affichage_map(Menu);
        break;
    }

}

//Fonction permettant de lancer le mode de jeu snake statique//
void Lance_jeu_statique(time_t depart)
{
    // J'initialise toutes les structures et fonctions nécessaires au lancement du jeu//
    Serpent serpent;
    Initialiser_serpent(&serpent);
    Fruit fruit;
    Obstacle obstacle;
    obstacle.taille=Taille_max_obstacle;
    Initialisation_tableau(Labyrinthe);
    Genere_fruit(Labyrinthe,&fruit,&serpent,&obstacle);
    Generer_obstacle(Labyrinthe,&obstacle);
    Afficher_tableau_serpent(Labyrinthe,serpent);
    time_t fin;
    time(&fin);
    double temps_diff=difftime(fin,depart);
    clock_t temps;
    char direction;
    //nous avons fait un timer, le joueur a 60 secondes pour faire le meilleur score possible//
    //La condition ici est serpent.etat==1 c'est a dire que le serpent est vivant//
    while(serpent.etat==1)
    {
        temps=clock();
        temps=temps/CLOCKS_PER_SEC-temps_diff;
        printf("Score:%d         Temps:%f ",serpent.taille-3,(double) temps);
        printf("\n\nVous voila dans le mode de jeu serpent \nstatique. Le principe est simple, essayez \nd'obtenir le maximum de fruit en 60 seconde.");
        Incremente_serpent(&serpent,&fruit,Labyrinthe,&obstacle);
        Deplacement_statique(&serpent,Labyrinthe,&direction);
        if(temps>=60)
        {
            Mort(&serpent,fin_partie_statique,depart);
        }
    }
    Affichage_map(Menu);
}

//Fonction permettant de lancer le mode de jeu snake en mouvement//
void Lance_jeu_mouvement(int niveau)
{
    // La variable progression_bis est utilisée ici car elle n'est pas modifiée par le changement de niveau, elle donne le niveau initial de la partie, et donc permet d'enregistrer les scores dans le bon niveau//
    int progression_bis;
    if(niveau==lvl1)
    {
        progression_bis=1;
    }
    if(niveau==lvl2)
    {
        progression_bis=2;
    }
    if(niveau==lvl3)
    {
        progression_bis=3;
    }
    Serpent serpent;
    int progression;
    Initialiser_serpent(&serpent);
    Fruit fruit;
    Obstacle obstacle;
    obstacle.taille=taille_obstacle;
    Initialisation_tableau(Labyrinthe);
    Genere_fruit(Labyrinthe,&fruit,&serpent,&obstacle);
    Generer_obstacle(Labyrinthe,&obstacle);
    Afficher_tableau_serpent(Labyrinthe,serpent);
    char direction=getch();
    //Patch pour que la personne ne commence pas dans la direction oppose a celle de la tete du serpent//
    while(direction=='q')
    {
        direction=getch();
    }
    while(serpent.etat==1)
    {
        if(niveau==lvl1)
        {
            progression=1;
        }
        if(niveau==lvl2)
        {
            progression=2;
        }
        if(niveau==lvl3)
        {
            progression=3;
        }
        //Le niveau et la vitesse du serpent change avec le nombre de fruits mangé.s 3 fruits mangés vous font passer au niveau 2. 6 fruits au niveau 3.
        if(serpent.taille>=6&&progression==1)
        {
            niveau=lvl2;
        }
        if(serpent.taille>=9&&progression==2)
        {
            niveau=lvl3;
        }
        printf("Score:%d                         Niveau:%d",serpent.taille-3,progression);
        printf("\n\nLe serpent est en mouvement dans ce mode. Plus vous mangez de fruit, plus votre\nserpent devient rapide et le jeu difficile.\nLes meilleurs scores sont affiches dans la page de score du menu!");
        Incremente_serpent(&serpent,&fruit,Labyrinthe,&obstacle);
        Deplacement_mouvement(&serpent,Labyrinthe,&direction,niveau);
        if(serpent.taille>=6&&progression==1)
        {
            if(serpent.taille>=12)
            {
                niveau=lvl3;
            }
            else if(serpent.taille>=9)
            {
                niveau=lvl2;
            }
        }
    }
    //Je lance ma fonction "Modifier_score" a la fin de chaque partie//
    Modifier_score(&serpent,progression_bis);
    Affichage_map(Menu);
}

//Fonction permettant de lancer le jeu snake crosswall//
void Lance_jeu_crosswall()
{
    Serpent serpent;
    Initialiser_serpent(&serpent);
    Fruit fruit;
    Obstacle obstacle;
    obstacle.taille=Taille_max_obstacle;
    Initialisation_tableau(Labyrinthe);
    Genere_fruit(Labyrinthe,&fruit,&serpent,&obstacle);
    Generer_obstacle(Labyrinthe,&obstacle);
    Afficher_tableau_serpent(Labyrinthe,serpent);
    char direction=getch();
    while(direction=='q')
    {
        direction=getch();
    }
    while(serpent.etat==1)
    {
        printf("Score:%d                        Vie: %d",serpent.taille-3,serpent.vie);
        printf("\n\nVous avez 5 vies. Si vous traversez\nun mur, vous perdez une vie. Si vous percutez un obstacle, \nle jeu se met en pause pour vous laisser choisir une autre direction.");
        Incremente_serpent(&serpent,&fruit,Labyrinthe,&obstacle);
        Deplacement_crosswall(&serpent,Labyrinthe,&direction);
    }
    Affichage_map(Menu);
}

//Fonction permettant de lancer le jeu Joueur VS PC//
void Lance_jeu_vspc()
{
    //Ici , j'initialise 2 serpents et 2 fruits//
    Serpent serpent;
    Serpent serpent_ia;
    Initialiser_serpent(&serpent);
    Initialiser_serpent2(&serpent_ia);
    Fruit fruit;
    Fruit fruit2;
    Obstacle obstacle;
    obstacle.taille=0;
    Initialisation_tableau(Labyrinthe);
    Genere_fruit(Labyrinthe,&fruit,&serpent,&obstacle);
    Genere_fruit(Labyrinthe,&fruit2,&serpent_ia,&obstacle);
    //J'affiche les deux serpents dans le même tableau//
    Afficher_tableau_serpent2(Labyrinthe,serpent_ia);
    Afficher_tableau_serpent(Labyrinthe,serpent);
    char direction=getch();
    while(direction=='q')
    {
        direction=getch();
    }
    char direction_ia='z';
    while(serpent.etat==1)
    {
        printf("Score joueur:%d               Score Pc:%d",serpent.taille-3,serpent_ia.taille-3);
        printf("\n\nVous voulez defier l'ordinateur?\nEh bien bonne chance car c'est un dur a cuir!\nLes deux serpents ne peuvent pas entrer en \ncollision et doivent manger un maximum de fruit.");
        //J'incremente pour chaque serpent et avec chaque fruit//
        Incremente_serpent(&serpent,&fruit,Labyrinthe,&obstacle);
        Incremente_serpent(&serpent,&fruit2,Labyrinthe,&obstacle);
        Incremente_serpent(&serpent_ia,&fruit,Labyrinthe,&obstacle);
        Incremente_serpent(&serpent_ia,&fruit2,Labyrinthe,&obstacle);
        Deplacement_vspc2(&serpent_ia,Labyrinthe,&fruit2,&direction_ia,2);
        Deplacement_vspc(&serpent,Labyrinthe,&direction);
    }
    Affichage_map(Menu);
}

//Fonction permettant de lancer le jeu Sneak Parfait.
void Lance_jeu_parfait()
{
    Serpent serpent;
    Initialiser_serpent(&serpent);
    Fruit fruit;
    Obstacle obstacle;
    obstacle.taille=taille_obstacle;
    Initialisation_tableau(Labyrinthe);
    Generer_obstacle(Labyrinthe,&obstacle);
    Genere_fruit(Labyrinthe,&fruit,&serpent,&obstacle);
    Afficher_tableau_serpent(Labyrinthe,serpent);
    char direction='z';
    while(serpent.etat==1)
    {
        printf("Score Pc:%d",serpent.taille-3);
        Incremente_serpent(&serpent,&fruit,Labyrinthe,&obstacle);
        Deplacement_vspc2(&serpent,Labyrinthe,&fruit,&direction,3);
    }
    Affichage_map(Menu);
}

//Fonction permettant de lancer le GAME OVER//
void Mort(Serpent *serpent,int i,time_t depart)
{
    char selection;
    Sleep(temps_attente/3);
    system("cls");
    if(i==1)
    {
        Affichage_map(Game_Over);
    }
    if(i==2)
    {
        Affichage_map(Fin);
    }
    if(i==3)
    {
        Affichage_map(Fin_pc);
    }
    Sleep(temps_attente);
    printf("Appuyez sur 9 pour revenir au menu.");
    Selection_map(&selection,depart);
    serpent->etat=0;
    //Apres avoir affiché Game_over et attendu que l'utilisateur appuie sur la touche 9 pour revenir au menu, je remet l'etat du serpent à 0 pour sortir de la boucle while de la fonction du mode de jeu correspondant//
}

//Fonction permettant d'enregistrer un nouveau score//
void Modifier_score(Serpent *serpent,int i)
{
    FILE* fichier = NULL;
    int score[3] = {0};
    //j'ouvre le fichier//
    fichier = fopen("record.txt", "r+");

    if (fichier != NULL)
    {
        //je lis les scores//
        fscanf(fichier, "%d %d %d", &score[0], &score[1], &score[2]);
        //Je verifie s'il y a un nouveau record//
        if(serpent->taille-3>score[i-1])
        {
            score[i-1]=serpent->taille-3;
            fclose(fichier);
            //Si c'est le cas, je reouvre en w+ pour écraser l'ancien record avec le nouveau//
            fichier = fopen("record.txt", "w+");
            fprintf(fichier, "%d %d %d", score[0], score[1], score[2]);
        }
        fclose(fichier);
    }
}

