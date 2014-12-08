#include <time.h>

#include "grille.h"

char *grille;

/* =============  Fonctions de Manipulation de grille  ============= */

/**
 * 	Initialise la grille avec des '_'.
 */ 
void init_grille()
{
	int i;
	
	grille = (char *)malloc(TAILLE_GRILLE);
	for(i =0 ; i < TAILLE_GRILLE ; i++)
		*(grille+i) = VIDE;
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
static int verifier_ligne(int l, char *vainqueur)
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
static int verifier_colonne(int l, char *vainqueur)
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

static int verifier_diagonales(char *vainqueur)
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

/* =======================  Fonctions de Test  ===================== */

#define N 100

static int test_init_grille()
{
	int i, r;
	srand(time(NULL));

	/* On teste aléatoirement chaque case et on vérifie le contenue. */
	r = rand() % (TAILLE_GRILLE); 
	for(i = 0 ; i < N ; i++, r=rand() % TAILLE_GRILLE)
	{
		assert(*(grille+r) == VIDE);
	}
		
	return 1;
}

static int test_placer_symbole()
{
	init_grille();

	assert(placer_symbole(0, 0, 'X'));
	assert(*grille == 'X');
	assert(!placer_symbole(0, 0, 'O'));
	assert(placer_symbole(2,2,'O'));
	assert(*(grille+8) == 'O');
	assert(placer_symbole(1,2,'X'));
	assert(*(grille+1+2*LONGUEUR) == 'X');

	return 1;
}

static int test_est_nulle()
{
	int i;
	init_grille();

	for(i = 0 ; i < TAILLE_GRILLE ; i++)
	{
		assert(!est_nulle());
		*(grille+i) = 'X';		
	}
	assert(est_nulle());

	return 1;
}

static int test_verifier_ligne()
{
	int i;
	char vainqueur;
	init_grille();

	for(i = 0 ; i < LONGUEUR ; i++)
	{
		assert(!verifier_ligne(0, &vainqueur));
		placer_symbole(i, 0, 'X');
	}
	assert(verifier_ligne(0, &vainqueur));
	assert(vainqueur == 'X');

	return 1;
}

static int test_verifier_colonne()
{
	int i;
	char vainqueur;
	init_grille();

	for(i = 0 ; i < LONGUEUR ; i++)
	{
		assert(!verifier_colonne(1, &vainqueur));
		placer_symbole(1, i, 'O');
	}
	assert(verifier_colonne(1, &vainqueur));
	assert(vainqueur == 'O');

	return 1;
}

static int test_verifier_diagonales()
{
	char vainqueur;
	init_grille();

	assert(!verifier_diagonales(&vainqueur));
	placer_symbole(0, 0, 'O');
	placer_symbole(1, 1, 'O');
	placer_symbole(2, 0, 'X');
	placer_symbole(0, 2, 'W');
	assert(!verifier_diagonales(&vainqueur));
	placer_symbole(2, 2, 'O');
	assert(verifier_diagonales(&vainqueur));
	assert(vainqueur == 'O');

	return 1;
}

static int test_est_gagnee()
{
	char vainqueur;
	init_grille();
	assert(!est_gagnee(&vainqueur));

	placer_symbole(0, 0, 'X');
	placer_symbole(0, 1, 'O');
	placer_symbole(0, 2, 'X');
	assert(!est_gagnee(&vainqueur));
	placer_symbole(1, 1, 'O');
	placer_symbole(2, 1, 'O');
	assert(est_gagnee(&vainqueur));
	assert(vainqueur == 'O');

	return 1;
}

/* ============================ Main ============================== */

/**
 *	Test l'ensemble des fonctions écrites dans ce fichier.
 */
int main(void)
{
	init_grille();
	assert(test_init_grille()); 
	assert(test_placer_symbole());
	assert(test_est_nulle());
	assert(test_verifier_ligne());
	assert(test_verifier_colonne());
	assert(test_verifier_diagonales());
	assert(test_est_gagnee());
	free(grille);
	exit(EXIT_SUCCESS); 
}
