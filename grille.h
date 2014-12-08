#ifndef H_GRILLE
#define H_GRILLE

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define LONGUEUR 3
#define TAILLE_GRILLE LONGUEUR * LONGUEUR
#define VIDE '_'


/* ======================  Fonctions d'édition de la grille  ===================== */

/**
 * 	Initialise une grille carré de taille TAILLE_GRILLE
 */
extern void init_grille();

/**
 *	Place le symbôle symb dans la case de coordonnées [col ; ligne]
 *	Les coordonnées sont indexées sur les indices du tableau.
 *	Retourne 0 si la case est occupée. 
 * 	On suppose les coordonnées valides.
 */
extern int placer_symbole(int col, int ligne, char symb);

/**
 *	Affiche la grille dans la console.	
 */
extern void afficher_grille();

/**
 *	Vérifie que la partie n'est pas nulle.
 *	i.e. : toutes les cases sont occupées et la partie n'est pas gagnée.
 */
extern int est_nulle();

/**
 *	Vérifie di la partie est gagnée.
 * 	i.e. : si LONGUEUR symbôles identiques sont alignés.
 *	Si la partie est gagnée, le caractère gagnant est stocké dans vainqueur
 */
extern int est_gagnee(char *vainqueur);

#endif
