#include "Deplacement.h"
#include "Constante.h"

//Sous fonction du deplacement statique//
void Deplace_s(Serpent *serpent,char Tab[hauteur][longueur],char *direction,int i)
{
    if(i==serpent->taille-1)
    {
        Tab[serpent->position_y[i]][serpent->position_x[i]]=' ';
        serpent->position_x[i]=serpent->position_x[i-1];
        serpent->position_y[i]=serpent->position_y[i-1];
    }
    else if(i==0)
    {
        // La tête du serpent bouge//
        switch(*direction)
        {
        case 'z':
            // Je verifie si la case visée par le serpent lui est interdite d'accès ou non//

            if(Tab[serpent->position_y[0]-1][serpent->position_x[0]]!=' '&&Tab[serpent->position_y[0]-1][serpent->position_x[0]]!='*')
            {
                Mort(serpent,mort);
                break;
            }
            serpent->position_y[0]=serpent->position_y[0]-1;
            break;
        case 's':
            if(Tab[serpent->position_y[0]+1][serpent->position_x[0]]!=' '&&Tab[serpent->position_y[0]+1][serpent->position_x[0]]!='*')
            {
                Mort(serpent,mort);
                break;
            }
            serpent->position_y[0]=serpent->position_y[0]+1;
            break;
        case 'q':
            if(Tab[serpent->position_y[0]][serpent->position_x[0]-1]!=' '&&Tab[serpent->position_y[0]][serpent->position_x[0]-1]!='*')
            {
                Mort(serpent,mort);
                break;
            }
            serpent->position_x[0]=serpent->position_x[0]-1;
            break;
        case 'd':
            if(Tab[serpent->position_y[0]][serpent->position_x[0]+1]!=' '&&Tab[serpent->position_y[0]][serpent->position_x[0]+1]!='*')
            {
                Mort(serpent,mort);
                break;
            }
            serpent->position_x[0]=serpent->position_x[0]+1;
            break;
        }
    }
    // Je fais bouger le reste du corps en faisant prendre à chaque membre la position de l'antécédent//
    else
    {
        serpent->position_x[i]=serpent->position_x[i-1];
        serpent->position_y[i]=serpent->position_y[i-1];
    }
}

//Sous fonction du deplacement mouvement//
void Deplace_m(Serpent *serpent,char Tab[hauteur][longueur],char *direction,int i,char sauvegarde)
{
    if(i==serpent->taille-1)
    {
        Tab[serpent->position_y[i]][serpent->position_x[i]]=' ';
        serpent->position_x[i]=serpent->position_x[i-1];
        serpent->position_y[i]=serpent->position_y[i-1];
    }
    if((*direction=='z'&&sauvegarde=='s')||(*direction=='s'&&sauvegarde=='z')||(*direction=='q'&&sauvegarde=='d')||(*direction=='d'&&sauvegarde=='q'))
    {
        *direction=sauvegarde;
    }
    else if(i==0)
    {
        switch(*direction)
        {
        case 'z':
            if(Tab[serpent->position_y[0]-1][serpent->position_x[0]]!=' '&&Tab[serpent->position_y[0]-1][serpent->position_x[0]]!='*')
            {
                Mort(serpent,mort);
                break;
            }
            serpent->position_y[0]=serpent->position_y[0]-1;
            break;
        case 's':
            if(Tab[serpent->position_y[0]+1][serpent->position_x[0]]!=' '&&Tab[serpent->position_y[0]+1][serpent->position_x[0]]!='*')
            {
                Mort(serpent,mort);
                break;
            }
            serpent->position_y[0]=serpent->position_y[0]+1;
            break;
        case 'q':
            if(Tab[serpent->position_y[0]][serpent->position_x[0]-1]!=' '&&Tab[serpent->position_y[0]][serpent->position_x[0]-1]!='*')
            {
                Mort(serpent,mort);
                break;
            }
            serpent->position_x[0]=serpent->position_x[0]-1;
            break;
        case 'd':
            if(Tab[serpent->position_y[0]][serpent->position_x[0]+1]!=' '&&Tab[serpent->position_y[0]][serpent->position_x[0]+1]!='*')
            {
                Mort(serpent,mort);
                break;
            }
            serpent->position_x[0]=serpent->position_x[0]+1;
            break;
        }
    }
    else
    {
        serpent->position_x[i]=serpent->position_x[i-1];
        serpent->position_y[i]=serpent->position_y[i-1];
    }
}

//Sous fonction du crosswall//
void Deplace_c(Serpent *serpent,char Tab[hauteur][longueur],char *direction,int i,char sauvegarde)
{
    if(i==serpent->taille-1)
    {
        Tab[serpent->position_y[i]][serpent->position_x[i]]=' ';
        serpent->position_x[i]=serpent->position_x[i-1];
        serpent->position_y[i]=serpent->position_y[i-1];
    }
    else if(i==0)
    {
        switch(*direction)
        {
        case 'z':
            if(Tab[serpent->position_y[0]-1][serpent->position_x[0]]!=' '&&Tab[serpent->position_y[0]-1][serpent->position_x[0]]!='*')
            {
                if(serpent->position_y[0]-1==0)
                {
                    // Je fais reapparaitre le serpent à la case opposee du tableau tout en lui faisant perdre une vie//
                    serpent->position_y[0]=18;
                    serpent->vie=serpent->vie-1;
                    if(serpent->vie==0)
                    {
                        Mort(serpent,mort);
                    }
                    break;
                }
                serpent->vie=serpent->vie-1;
                if(serpent->vie==0)
                {
                    Mort(serpent,mort);
                }
                *direction=getch();
                while(*direction=='z'||*direction=='s')
                {
                    // Ici, on empeche le joueur de selectionner une direction opposee a  celle dans laquelle le serpent va//
                    if(Tab[serpent->position_y[0]+1][serpent->position_x[0]]!='o')
                    {
                        break;
                    }
                    *direction=getch();
                }
                break;
            }
            serpent->position_y[0]=serpent->position_y[0]-1;
            break;
        case 's':
            if(Tab[serpent->position_y[0]+1][serpent->position_x[0]]!=' '&&Tab[serpent->position_y[0]+1][serpent->position_x[0]]!='*')
            {
                if(serpent->position_y[0]+1==19)
                {
                    serpent->position_y[0]=1;
                    serpent->vie=serpent->vie-1;
                    if(serpent->vie==0)
                    {
                        Mort(serpent,1);
                    }
                    break;
                }
                serpent->vie=serpent->vie-1;
                if(serpent->vie==0)
                {
                    Mort(serpent,mort);
                }
                *direction=getch();
                while(*direction=='z'||*direction=='s')
                {
                    if(Tab[serpent->position_y[0]-1][serpent->position_x[0]]!='o')
                    {
                        break;
                    }
                    *direction=getch();
                }
                break;
            }
            serpent->position_y[0]=serpent->position_y[0]+1;
            break;
        case 'q':
            if(Tab[serpent->position_y[0]][serpent->position_x[0]-1]!=' '&&Tab[serpent->position_y[0]][serpent->position_x[0]-1]!='*')
            {
                if(serpent->position_x[0]-1==0)
                {
                    serpent->position_x[0]=38;
                    serpent->vie=serpent->vie-1;
                    if(serpent->vie==0)
                    {
                        Mort(serpent,mort);
                    }
                    break;
                }
                serpent->vie=serpent->vie-1;
                if(serpent->vie==0)
                {
                    Mort(serpent,1);
                }
                *direction=getch();
                while(*direction=='q'||*direction=='d')
                {
                    if(Tab[serpent->position_y[0]][serpent->position_x[0]+1]!='o')
                    {
                        break;
                    }
                    *direction=getch();
                }
                break;
            }
            serpent->position_x[0]=serpent->position_x[0]-1;
            break;
        case 'd':
            if(Tab[serpent->position_y[0]][serpent->position_x[0]+1]!=' '&&Tab[serpent->position_y[0]][serpent->position_x[0]+1]!='*')
            {
                if(serpent->position_x[0]+1==39)
                {
                    serpent->position_x[0]=1;
                    serpent->vie=serpent->vie-1;
                    if(serpent->vie==0)
                    {
                        Mort(serpent,mort);
                    }
                    break;
                }
                serpent->vie=serpent->vie-1;
                if(serpent->vie==0)
                {
                    Mort(serpent,mort);
                }
                *direction=getch();
                while(*direction=='q'||*direction=='d')
                {
                    if(Tab[serpent->position_y[0]][serpent->position_x[0]-1]!='o')
                    {
                        break;
                    }
                    *direction=getch();
                }
                break;
            }
            serpent->position_x[0]=serpent->position_x[0]+1;
            break;
        }
    }
    else
    {
        serpent->position_x[i]=serpent->position_x[i-1];
        serpent->position_y[i]=serpent->position_y[i-1];
    }
}

//Sous fonction du mode Joueur vs PC//
void Deplace_v(Serpent *serpent,char Tab[hauteur][longueur],char *direction,int i,char sauvegarde)
{
    if(i==serpent->taille-1)
    {
        Tab[serpent->position_y[i]][serpent->position_x[i]]=' ';
        serpent->position_x[i]=serpent->position_x[i-1];
        serpent->position_y[i]=serpent->position_y[i-1];
    }
    if((*direction=='z'&&sauvegarde=='s')||(*direction=='s'&&sauvegarde=='z')||(*direction=='q'&&sauvegarde=='d')||(*direction=='d'&&sauvegarde=='q'))
    {
        *direction=sauvegarde;
    }
    else if(i==0)
    {
        switch(*direction)
        {
        case 'z':
            if(Tab[serpent->position_y[0]-1][serpent->position_x[0]]!=' '&&Tab[serpent->position_y[0]-1][serpent->position_x[0]]!='*'&&Tab[serpent->position_y[0]-1][serpent->position_x[0]]!='x'&&Tab[serpent->position_y[0]-1][serpent->position_x[0]]!='X')
            {
                Mort(serpent,fin_partie_vspc);
                break;
            }
            serpent->position_y[0]=serpent->position_y[0]-1;
            break;
        case 's':
            if(Tab[serpent->position_y[0]+1][serpent->position_x[0]]!=' '&&Tab[serpent->position_y[0]+1][serpent->position_x[0]]!='*'&&Tab[serpent->position_y[0]+1][serpent->position_x[0]]!='x'&&Tab[serpent->position_y[0]+1][serpent->position_x[0]]!='X')
            {
                Mort(serpent,fin_partie_vspc);
                break;
            }
            serpent->position_y[0]=serpent->position_y[0]+1;
            break;
        case 'q':
            if(Tab[serpent->position_y[0]][serpent->position_x[0]-1]!=' '&&Tab[serpent->position_y[0]][serpent->position_x[0]-1]!='*'&&Tab[serpent->position_y[0]][serpent->position_x[0]-1]!='x'&&Tab[serpent->position_y[0]][serpent->position_x[0]-1]!='X')
            {
                Mort(serpent,fin_partie_vspc);
                break;
            }
            serpent->position_x[0]=serpent->position_x[0]-1;
            break;
        case 'd':
            if(Tab[serpent->position_y[0]][serpent->position_x[0]+1]!=' '&&Tab[serpent->position_y[0]][serpent->position_x[0]+1]!='*'&&Tab[serpent->position_y[0]][serpent->position_x[0]+1]!='x'&&Tab[serpent->position_y[0]][serpent->position_x[0]+1]!='X')
            {
                Mort(serpent,fin_partie_vspc);
                break;
            }
            serpent->position_x[0]=serpent->position_x[0]+1;
            break;
        }
    }
    else
    {
        serpent->position_x[i]=serpent->position_x[i-1];
        serpent->position_y[i]=serpent->position_y[i-1];
    }
}

//Sous fonction de l'IA//
void Deplace_v2(Serpent *serpent,char Tab[hauteur][longueur],Fruit *fruit,char *direction,int i,char sauvegarde)
{
    if(i==serpent->taille-1)
    {
        Tab[serpent->position_y[i]][serpent->position_x[i]]=' ';
        serpent->position_x[i]=serpent->position_x[i-1];
        serpent->position_y[i]=serpent->position_y[i-1];
    }
    if((*direction=='z'&&sauvegarde=='s')||(*direction=='s'&&sauvegarde=='z')||(*direction=='q'&&sauvegarde=='d')||(*direction=='d'&&sauvegarde=='q'))
    {
        *direction=sauvegarde;
    }
    else if(i==0)
    {
        switch(*direction)
        {
        case 'z':
            if(Tab[serpent->position_y[0]-1][serpent->position_x[0]]!=' '&&Tab[serpent->position_y[0]-1][serpent->position_x[0]]!='*'&&Tab[serpent->position_y[0]-1][serpent->position_x[0]]!='o'&&Tab[serpent->position_y[0]-1][serpent->position_x[0]]!='O')
            {
                if(Tab[serpent->position_y[0]][serpent->position_x[0]+1]!=' '&&Tab[serpent->position_y[0]][serpent->position_x[0]+1]!='*'&&Tab[serpent->position_y[0]][serpent->position_x[0]+1]!='o'&&Tab[serpent->position_y[0]][serpent->position_x[0]+1]!='O')
                {
                    *direction='q';
                    break;
                }
                else
                {
                    *direction='d';
                    break;
                }
            }
            serpent->position_y[0]=serpent->position_y[0]-1;
            chemin_plus_proche(serpent,fruit,Tab,direction,sauvegarde);
            break;
        case 's':
            if(Tab[serpent->position_y[0]+1][serpent->position_x[0]]!=' '&&Tab[serpent->position_y[0]+1][serpent->position_x[0]]!='*'&&Tab[serpent->position_y[0]+1][serpent->position_x[0]]!='o'&&Tab[serpent->position_y[0]+1][serpent->position_x[0]]!='O')
            {
                if(Tab[serpent->position_y[0]][serpent->position_x[0]-1]!=' '&&Tab[serpent->position_y[0]][serpent->position_x[0]-1]!='*'&&Tab[serpent->position_y[0]][serpent->position_x[0]-1]!='o'&&Tab[serpent->position_y[0]][serpent->position_x[0]-1]!='O')
                {
                    *direction='d';
                    break;
                }
                else
                {
                    *direction='q';
                    break;
                }
            }
            serpent->position_y[0]=serpent->position_y[0]+1;
            chemin_plus_proche(serpent,fruit,Tab,direction,sauvegarde);
            break;
        case 'q':
            if(Tab[serpent->position_y[0]][serpent->position_x[0]-1]!=' '&&Tab[serpent->position_y[0]][serpent->position_x[0]-1]!='*'&&Tab[serpent->position_y[0]][serpent->position_x[0]-1]!='o'&&Tab[serpent->position_y[0]][serpent->position_x[0]-1]!='O')
            {
                if(Tab[serpent->position_y[0]-1][serpent->position_x[0]]!=' '&&Tab[serpent->position_y[0]-1][serpent->position_x[0]]!='*'&&Tab[serpent->position_y[0]-1][serpent->position_x[0]]!='o'&&Tab[serpent->position_y[0]-1][serpent->position_x[0]]!='O')
                {
                    *direction='s';
                    break;
                }
                else
                {
                    *direction='z';
                    break;
                }
            }
            serpent->position_x[0]=serpent->position_x[0]-1;
            chemin_plus_proche(serpent,fruit,Tab,direction,sauvegarde);
            break;
        case 'd':
            if(Tab[serpent->position_y[0]][serpent->position_x[0]+1]!=' '&&Tab[serpent->position_y[0]][serpent->position_x[0]+1]!='*'&&Tab[serpent->position_y[0]][serpent->position_x[0]+1]!='o'&&Tab[serpent->position_y[0]][serpent->position_x[0]+1]!='O')
            {
                if(Tab[serpent->position_y[0]+1][serpent->position_x[0]]!=' '&&Tab[serpent->position_y[0]+1][serpent->position_x[0]]!='*'&&Tab[serpent->position_y[0]+1][serpent->position_x[0]]!='o'&&Tab[serpent->position_y[0]+1][serpent->position_x[0]]!='O')
                {
                    *direction='z';
                    break;
                }
                else
                {
                    *direction='s';
                    break;
                }
            }
            serpent->position_x[0]=serpent->position_x[0]+1;
            chemin_plus_proche(serpent,fruit,Tab,direction,sauvegarde);
            break;
        }
    }
    else
    {
        serpent->position_x[i]=serpent->position_x[i-1];
        serpent->position_y[i]=serpent->position_y[i-1];
    }
}

//Fonction responsable du deplacement du serpent dans le mode de jeu statique//
void Deplacement_statique(Serpent *serpent,char Tab[hauteur][longueur],char *direction)
{
    int i;
    // Je cree un caractere "sauvegarde" qui va permettre d'empecher le jouer de faire un retour sur lui meme, et ce sans le tuer//
    char sauvegarde;
    sauvegarde=*direction;
    *direction=getch();
    while(*direction!='z'&&*direction!='s'&&*direction!='q'&&*direction!='d')
    {
        *direction=getch();
    }
    while((*direction=='z'&&sauvegarde=='s')||(*direction=='s'&&sauvegarde=='z')||(*direction=='q'&&sauvegarde=='d')||(*direction=='d'&&sauvegarde=='q'))
    {
        *direction=getch();
    }
    for(i=serpent->taille-1; i>=0; i--)
    {
        Deplace_s(serpent,Tab,direction,i);
    }
    // J'affiche mon tableau et mon serpent//
    if(serpent->etat==1)
    {
        Afficher_tableau_serpent(Tab,*serpent);
    }
}

//Fonction responsable du deplacement du serpent dans le mode de jeu mouvement//
void Deplacement_mouvement(Serpent *serpent,char Tab[hauteur][longueur],char *direction,int niveau)
{
    int i;
    // Le Sleep me permet d'augmenter la difficulte d'un niveau a l'autre en faisant varier la vitesse. La valeur rentree dans Sleep est determinee dans la fonction qui lance le mode de jeu//
    Sleep(niveau);
    char sauvegarde;
    sauvegarde=*direction;
    // Cette fois ci, j'utilise la fonction kbhit() pour que mon serpent puisse rester dans la meme direction//
    if(kbhit())
    {
        *direction=getch();
        if(*direction!='z'&&*direction!='s'&&*direction!='q'&&*direction!='d')
        {
            *direction=sauvegarde;
        }
    }
    for(i=serpent->taille-1; i>=0; i--)
    {
        Deplace_m(serpent,Tab,direction,i,sauvegarde);
    }
    if(serpent->etat==1)
    {
        Afficher_tableau_serpent(Tab,*serpent);
    }
}

//Fonction responsable du deplacement du serpent dans le mode de jeu crosswall//
void Deplacement_crosswall(Serpent *serpent,char Tab[hauteur][longueur],char *direction)
{
    int i;
    Sleep(30);
    char sauvegarde;
    while(kbhit())
    {
        sauvegarde=*direction;
        *direction=getch();
        if(*direction!='z'&&*direction!='s'&&*direction!='q'&&*direction!='d')
        {
            *direction=sauvegarde;
        }
        if((*direction=='z'&&sauvegarde=='s')||(*direction=='s'&&sauvegarde=='z')||(*direction=='q'&&sauvegarde=='d')||(*direction=='d'&&sauvegarde=='q'))
        {
            *direction=sauvegarde;
        }
    }
    for(i=serpent->taille-1; i>=0; i--)
    {
        Deplace_c(serpent,Tab,direction,i,sauvegarde);
    }
    if(serpent->etat==1)
    {
        Afficher_tableau_serpent(Tab,*serpent);
    }
}

//Fonction responsable du deplacement du serpent du JOUEUR dans le mode de jeu Joueur vs pc et snakeparfait//
void Deplacement_vspc(Serpent *serpent,char Tab[hauteur][longueur],char *direction)
{
    // Meme fonction que pour le mode de jeu mouvement sauf qu'ici il y a pas de systeme de niveau//
    int i;
    Sleep(30);
    char sauvegarde;
    sauvegarde=*direction;
    if(kbhit())
    {
        *direction=getch();
        if(*direction!='z'&&*direction!='s'&&*direction!='q'&&*direction!='d')
        {
            *direction=sauvegarde;
        }
    }
    for(i=serpent->taille-1; i>=0; i--)
    {
        Deplace_v(serpent,Tab,direction,i,sauvegarde);
    }
    if(serpent->etat==1)
    {
        Afficher_tableau_serpent(Tab,*serpent);
    }
}

//Fonction responsable du deplacement du serpent PC dans le mode de jeu joueur vs pc//
void Deplacement_vspc2(Serpent *serpent,char Tab[hauteur][longueur],Fruit *fruit,char *direction,int p)
{
    int i;
    char sauvegarde;
    sauvegarde=*direction;
    if(kbhit())
    {
        *direction=sauvegarde;
        if(*direction!='z'&&*direction!='s'&&*direction!='q'&&*direction!='d')
        {
            *direction=sauvegarde;
        }
    }
    for(i=serpent->taille-1; i>=0; i--)
    {
        Deplace_v2(serpent,Tab,fruit,direction,i,sauvegarde);
    }
    if(serpent->etat==1)
    {
        if(p==2)
        {
            // cette fois ci ,J'utilise une autre fonction qui va fusionner le serpent au tableau sans centrer la console ni l'effacer car cela va deja etre fait par la fonction qui déplace le serpent joueur/
            Afficher_tableau_serpent2(Tab,*serpent);
        }
        if(p==3)
        {
            Afficher_tableau_serpent3(Tab,*serpent);
        }
    }
}


