project
=======

Spécifications :
================
L'application permet de jouer au morpion.
Elle affiche une grille vierge.
Tour à tour, chacun des 2 joueurs indique les coordonnées
de la case à marquée.
La case en question sera marquée avec le symbôle associé au joueur.
La partie sera terminée par une victoire (alignement de 3 symbôles identiques)
ou par une défaite (toutes les cases sont remplies).

- L'application sera réalisée en mode console.
- Les symbôles utilisés seront les caractère 'X' et 'O'
- Les cases vides seront représentées par un underscore
- La grille sera une grille de caractères
- Les joueurs seront créés automatiquement par le programme
- La grille sera affichée à chaque tour
- Le jeu continuera tant que la partie n'est ni gagnée ni nulle


Fichiers présents :
===================
- README.md 	: ce fichier
- TODO.md 		: fichier contenant les prochaines tâches à effectuer
- grille.h 		: fichier contenant les prototypes des fonctions pour
la manipulation d'une grille.
- grille.c 		: implémentation des fonctions définies dans grille.h
- morpion.c (m) : implémentation de la partie de morpion
- test.c (m)	: implémentation des fonctions de test


Implémentation 1 :
==================
Implémentation de la grille et de ses fonctionnalités (notamment un affichage en mode console).

Le but étant de pouvoir :
- créer la grille
- y placer un symbôle voulu à un emplacement voulu
- savoir si elle est gagnée ou nulle
- afficher la grille

Pour savoir si une grille est gagnante, il faut regarder si il y a un alignement
de 3 symbôles identiques à l'intérieur (ligne, colonne, diagonale).
Si la partie est gagnante on devra également savoir quel est le vainqueur (ou son symbôle).
Il faut également être en mesure de tester ces fonctionnalités.


Implémentation 2 :
==================
Implémentation d'un main permettant de simuler un partie en choisissant aléatoirement 
la case à marquer.
Cette implémentation permet d'avoir le squelette d'une partie standard, celui-ci pourra 
ensuite être modifié pour prendre en compte de nouvelles fonctionnalités.

Algorithme d'une partie :
- Initialisation d'une partie
- Tant que la partie n'est ni gagnée ni nulle :
	- Détermine aléatoirement les coordonnées de la case à marquer
	- Place le symbôle courant dans la case correspondante
	- Change le symbôle courant
	- Affiche la grille
- Affiche le résultat de la partie (et le caractère gagnant le cas échéant)


Implémentation 3 :
==================
Modification du code pour ajouter la notion de joueur dans la partie.
