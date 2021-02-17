SNAKE_README
El Mahdi Moubarak
Gabriel Rance

ORGANISATION DU PROJET :

Le fichier est organis� en .c/.h de la fa�on suivante :
- Menu_Map contient toutes les fonctions et d'affichages du menu et du jeu, ce fichier inclu aussi les d�clarations/initialisations des diff�rents �cran.

- Deplacement contient toutes les fonctions de d�placement des diff�rents modes de jeu, ce ne sont pas des fonctions d�di�es � l'affichage bien qu'elles fassent appelle � la fonction
Afficher_Tableau_Serpent � la fin.

- Generation contient les fonctions d'initialisations des obstacles et des fruits dans le tableau.

- Serpent contient seulement l'initialisation et le grandissement du snake, sa fonction d'affichage �tant dans Menu_Map et la fonction qui concerne sa mort se trouve dans Jeu parce qu'on
a jug� qu'elle y avait plus sa place. En effet l'utilit� principale de la fonction mort n'est pas de modifier l'�tat du snake mais de fermer le jeu.

- Jeu contient toutes les fonctions de lancement des diff�rents modes de jeu : statique pour le d�placement manuel au "coup par coup", mouvement pour le d�placement automatique, crosswall
dont le nom est suffisament explicite, vspc pour "versus pc" qui permet le jeu contre l'IA et parfait pour voir l'IA r�aliser un score parfait (749).

- Structure ne contient que des d�clarations de structures, nous les avons toutes regroup�es dans un fichier sp�cial pour �viter les probl�mes de r�cursivit�s dans les d�clarations de
fonctions avec les #include "****.h".

Les .c/.h ont �t� organis�s en utilisant le moins de #include pour optimiser les liens entre les diff�rents fichiers.


ENTRONS MAINTENANT PLUS EN DETAILS DANS CERTAINES FONCTIONS

Dans Jeu.c, nous avons s�par� en diff�rentes fonctions les niveaux de difficult�s :
- Niveau manuel : le plateau de jeu est constitu� du serpent, des murs, d'obstacles et un fruit qui apparaissent al�atoirement en d�but de partie. Le serpent se d�place de case en case � 
l'aide des touches zqsd. Il grandi � chaque fruit mang�, fruit qui r�apparait � une nouvelle position al�atoire. Le score augmente de 1 � chaque fois que le snake grandi et n'est pas 
enregistr�.
Le joueur doit faire le meilleur score possible en 60 secondes.

- Niveau d�placement auto : ici le plateau est constitu� de la m�me mani�re que pour le niveau manuel. Il y a 3 niveaux de difficult�s (3 vitesses de d�placement), dans un ordre croissant
1, 2 et 3. Si l'on s�lectionne les niveaux 1 et 2, au bout d'un certain score la difficult� augmente jusqu'� atteindre celle du niveau 3. Il y a ici un score qui augmente quand le serpent
grandi (� chaque fois qu'il mange un fruit). Les scores s'enregistrent en fonction du niveau de difficult� choisi lors de la s�lection en menu (si on lance niveau 1, m�me si la difficult�
cro�t jusqu'au niveau 3, le score s'enregistre pour le niveau 1). Le joueur ne d�place plus le serpent mais choisi seulement sa direction toujours avec zqsd.

- Niveau Crosswall : Le plateau est toujours le m�me, il y a un score mais pas enregistr�. On ajoute ici un syst�me de vie, le serpent peut traverser les murs mais pas les obstacles. 
Le snake a 5 vies et en perd une � chaque fois qu'il touche un obstacle, ou qu'il traverse le mur. Le jeu s'arr�te quand on a plus de vie.

- Niveau vspc : Le joueur joue contre une ia, les 2 snakes s'affrontent au score et jusqu'� mort de l'un d'eux (non enregistr�) sur un m�me plateau de jeu sans obstacle. 
Ils peuvent se croiser, les deux snakes mangent le m�me fruit, il faut donc essayer de le r�cup�rer avant l'IA � chaque fois.

- Niveau parfait : Le joueur est passif, et observent une IA faire le meilleur score possible seule sur un plateau de jeu consitu� des murs, du serpent et d'un fruit � la fois.

Les conditions de morts du serpents sont : collision avec un mur, un obstacle, sa propre queue (sous reserve d'avoir ou non des vies), ne plus avoir de vie ou de ne plus avoir de mouvement.

Dans Deplacement.c :
Dans ces fonctions, nous avons cherch� tous les bugs et d�placement qui ne devraient pas avoir lieu (appuyer sur la direction oppos�e � celle qu'il suit et percuter son corps). 
Ce mouvement est proscris � l'aide d'un patch, comme pour beaucoup d'autres cas qui sont comment�s � chaque fois. 
La pr�sence de tout ces patchs font que les fonctions de d�placement sont les plus cons�quente.

DIFFERENTES FONCTIONS QUE L'ON A EMPRUNTE/DECOUVERTE SUR INTERNET :
- rand_a_b sous la biblioth�que <time.h>
- centrer (qui est un gotoxy)
- color
