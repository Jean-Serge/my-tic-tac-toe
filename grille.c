#include "grille.h"

char *grille;

/* =============  Fonctions de Manipulation de grille  ============= */

/**
 * 	Initialise la grille avec des espaces.
 */ 
void init_grille()
{
	int i;
	
	grille = (char *)malloc(TAILLE_GRILLE);
	for(i =0 ; i < TAILLE_GRILLE ; i++)
		*(grille+i) = ' ';
}

/* =======================  Fonctions de Test  ===================== */

#define N 100

int test_init_grille()
{
	int i, r, r2;
	srand(time(NULL));

	/* On teste aléatoirement chaque case et on vérifie le contenue. */
	r = rand() % (TAILLE_GRILLE); 
	for(i = 0 ; i < N ; i++, r=rand() % TAILLE_GRILLE)
	{
		assert(*(grille+r) == ' ');
	}
		
	return 1;
}


/* ============================ Main ============================== */
int main(void)
{
	init_grille();
	assert(test_init_grille()); 
	exit(EXIT_SUCCESS); 
}
