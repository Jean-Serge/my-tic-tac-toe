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
- README.md : ce fichier
- grille.h : fichier contenant les prototypes des fonctions pour
la manipulation d'une grille.
- grille.c : implémentation des fonctions définies dans grille.h


Implémentation 1 :
==================
Implémentation de la grille et de ses fonctionnalités (notamment un affichage en mode console).

Le but étant de pouvoir :
- créer la grille
- y placer un symbôle voulu à un emplacement voulu
- savoir si elle est gagnée ou nulle
- afficher la grille

Il faut également être en mesure de tester ces fonctionnalités.
