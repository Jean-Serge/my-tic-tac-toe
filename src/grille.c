#include <time.h>

#include "grille.h"

/* =============  Fonctions de Manipulation de grille  ============= */

void init_grille()
{
	int i;
	
	grille = (char *)malloc(TAILLE_GRILLE);
	for(i =0 ; i < TAILLE_GRILLE ; i++)
		*(grille+i) = VIDE;
}

void free_grille()
{
	free(grille);
}

void afficher_grille()
{
	int i;

	for(i = 0 ; i < TAILLE_GRILLE ; i++)
	{
		printf("%c", *(grille+i));
		if(i % LONGUEUR == LONGUEUR-1)
			printf("\n");
	}
}

/**
 *	Retourne l'index correspondant aux coordonnées 
 *	indiquées.
 */
static int index_of(int col, int ligne)
{
	return col + LONGUEUR * ligne;
}

int placer_symbole(int col, int ligne, char symb)
{
	const int index = index_of(col, ligne);
	
	/* Vérifie que la case est vide */
	if(*(grille+index) != VIDE)
		return 0;

	*(grille+index) = symb;
	return 1;
}

int est_nulle()
{
		int i;

		for(i = 0 ; i < TAILLE_GRILLE ; i++)
			if(*(grille+i) == VIDE) 
				return 0;
		return 1;
}

/**
 *	Vérifie si la ligne indiquée est gagnée.
 *	i.e. : vérifie que tous les caractères de la ligne sont les même.
 */
int verifier_ligne(int l, char *vainqueur)
{
	char c = *(grille + l * LONGUEUR);
	int i;

	if(c == VIDE)
		return 0;

	for(i = 0 ; i < LONGUEUR ; i++)
	{
		if(*(grille + l * LONGUEUR + i) != c)
			return 0;
	}

	*vainqueur = c;
	return 1;
}

/**
 *	Vérifier si la colonne indiquée est gagnante.
 * 	i.e. : vérifie que la ligne est remplie avec le même symbôle non VIDE.
 */
int verifier_colonne(int l, char *vainqueur)
{
	char c = *(grille + l);
	int i;

	if(c == VIDE)
		return 0;

	for(i = 0 ; i < LONGUEUR ; i++)
	{
		if(*(grille + l + i * LONGUEUR) != c)
			return 0;
	}

	*vainqueur = c;
	return 1;
}

int verifier_diagonales(char *vainqueur)
{
	/* On vérifie la 1ère diagonale */
	char c = *(grille);
	int i, est_gagne = 1;

	if(c != VIDE)
	{
		for(i = LONGUEUR+1 ; i < TAILLE_GRILLE ; i+= LONGUEUR +1)
		{
			if(*(grille+i) != c)
			{
				est_gagne = 0;
				break;
			}	
		}
		if(est_gagne)
		{
			*vainqueur = c;
			return 1;
		}
	}

	c = *(grille + LONGUEUR - 1);
	if(c == VIDE)
		return 0;

	for(i = 2 * LONGUEUR -1 ; i < TAILLE_GRILLE ; i += LONGUEUR - 1)
	{
		if(*(grille + i) != c)
		{
			est_gagne = 0;
			break;
		}
	}

	if(est_gagne)
		*vainqueur = c;
	return est_gagne;
}

int est_gagnee(char *vainqueur)
{
	int i, gagnee = 0;

	/* On vérifie les lignes */
	for(i = 0 ; i < LONGUEUR ; i++)
	{
		gagnee |= verifier_ligne(i, vainqueur);
		gagnee |= verifier_colonne(i, vainqueur);
		if(gagnee) 
			return gagnee;
	}
	gagnee = verifier_diagonales(vainqueur);

	return gagnee;
}

