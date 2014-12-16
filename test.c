#include <assert.h>
#include <time.h>

#include "include/grille.h"


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
