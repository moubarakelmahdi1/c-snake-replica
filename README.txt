SNAKE_README
El Mahdi Moubarak
Gabriel Rance

ORGANISATION DU PROJET :

Le fichier est organisé en .c/.h de la façon suivante :
- Menu_Map contient toutes les fonctions et d'affichages du menu et du jeu, ce fichier inclu aussi les déclarations/initialisations des différents écran.

- Deplacement contient toutes les fonctions de déplacement des différents modes de jeu, ce ne sont pas des fonctions dédiées à l'affichage bien qu'elles fassent appelle à la fonction
Afficher_Tableau_Serpent à la fin.

- Generation contient les fonctions d'initialisations des obstacles et des fruits dans le tableau.

- Serpent contient seulement l'initialisation et le grandissement du snake, sa fonction d'affichage étant dans Menu_Map et la fonction qui concerne sa mort se trouve dans Jeu parce qu'on
a jugé qu'elle y avait plus sa place. En effet l'utilité principale de la fonction mort n'est pas de modifier l'état du snake mais de fermer le jeu.

- Jeu contient toutes les fonctions de lancement des différents modes de jeu : statique pour le déplacement manuel au "coup par coup", mouvement pour le déplacement automatique, crosswall
dont le nom est suffisament explicite, vspc pour "versus pc" qui permet le jeu contre l'IA et parfait pour voir l'IA réaliser un score parfait (749).

- Structure ne contient que des déclarations de structures, nous les avons toutes regroupées dans un fichier spécial pour éviter les problèmes de récursivités dans les déclarations de
fonctions avec les #include "****.h".

Les .c/.h ont été organisés en utilisant le moins de #include pour optimiser les liens entre les différents fichiers.


ENTRONS MAINTENANT PLUS EN DETAILS DANS CERTAINES FONCTIONS

Dans Jeu.c, nous avons séparé en différentes fonctions les niveaux de difficultés :
- Niveau manuel : le plateau de jeu est constitué du serpent, des murs, d'obstacles et un fruit qui apparaissent aléatoirement en début de partie. Le serpent se déplace de case en case à 
l'aide des touches zqsd. Il grandi à chaque fruit mangé, fruit qui réapparait à une nouvelle position aléatoire. Le score augmente de 1 à chaque fois que le snake grandi et n'est pas 
enregistré.
Le joueur doit faire le meilleur score possible en 60 secondes.

- Niveau déplacement auto : ici le plateau est constitué de la même manière que pour le niveau manuel. Il y a 3 niveaux de difficultés (3 vitesses de déplacement), dans un ordre croissant
1, 2 et 3. Si l'on sélectionne les niveaux 1 et 2, au bout d'un certain score la difficulté augmente jusqu'à atteindre celle du niveau 3. Il y a ici un score qui augmente quand le serpent
grandi (à chaque fois qu'il mange un fruit). Les scores s'enregistrent en fonction du niveau de difficulté choisi lors de la sélection en menu (si on lance niveau 1, même si la difficulté
croît jusqu'au niveau 3, le score s'enregistre pour le niveau 1). Le joueur ne déplace plus le serpent mais choisi seulement sa direction toujours avec zqsd.

- Niveau Crosswall : Le plateau est toujours le même, il y a un score mais pas enregistré. On ajoute ici un système de vie, le serpent peut traverser les murs mais pas les obstacles. 
Le snake a 5 vies et en perd une à chaque fois qu'il touche un obstacle, ou qu'il traverse le mur. Le jeu s'arrête quand on a plus de vie.

- Niveau vspc : Le joueur joue contre une ia, les 2 snakes s'affrontent au score et jusqu'à mort de l'un d'eux (non enregistré) sur un même plateau de jeu sans obstacle. 
Ils peuvent se croiser, les deux snakes mangent le même fruit, il faut donc essayer de le récupérer avant l'IA à chaque fois.

- Niveau parfait : Le joueur est passif, et observent une IA faire le meilleur score possible seule sur un plateau de jeu consitué des murs, du serpent et d'un fruit à la fois.

Les conditions de morts du serpents sont : collision avec un mur, un obstacle, sa propre queue (sous reserve d'avoir ou non des vies), ne plus avoir de vie ou de ne plus avoir de mouvement.

Dans Deplacement.c :
Dans ces fonctions, nous avons cherché tous les bugs et déplacement qui ne devraient pas avoir lieu (appuyer sur la direction opposée à celle qu'il suit et percuter son corps). 
Ce mouvement est proscris à l'aide d'un patch, comme pour beaucoup d'autres cas qui sont commentés à chaque fois. 
La présence de tout ces patchs font que les fonctions de déplacement sont les plus conséquente.

DIFFERENTES FONCTIONS QUE L'ON A EMPRUNTE/DECOUVERTE SUR INTERNET :
- rand_a_b sous la bibliothèque <time.h>
- centrer (qui est un gotoxy)
- color
