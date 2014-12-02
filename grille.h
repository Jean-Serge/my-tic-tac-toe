#ifndef H_GRILLE
#define H_GRILLE

#define TAILLE_GRILLE 3

int grille[TAILLE_GRILLE][TAILLE_GRILLE];


/* ======================  Fonctions d'édition de la grille  ===================== */

/**
 * 	Initialise une grille carré de taille TAILLE_GRILLE
 */
extern void init_grille();

/**
 *	Place le symbôle symb dans la case de coordonnées [col ; ligne]
 *	Les coordonnées sont indexées sur les indices du tableau.
 */
extern int placer_symbole(int col, int ligne, char symb);

/**
 *	Affiche la grille dans la console.	
 */
extern void afficher_grille();

/**
 *	Vérifie que la partie n'est pas nulle.
 *	i.e. : toutes les cases sont occupées 
 *	et la partie n'est pas gagnée.
 */
extern int est_nulle();

#endif
