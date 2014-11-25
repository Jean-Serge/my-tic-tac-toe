#ifndef H_GRILLE
#define H_GRILLE

#define TAILLE_GRILLE 3;

extern int grille [TAILLE_GRILLE][TAILLE_GRILLE];


/* ======================  Fonctions d'édition de la grille  ===================== */

/* Initialise une grille carré de taille TAILLE_GRILLE */
extern void init_grille();

extern int placer_symbole(int col, int ligne, char symb);

#endif
