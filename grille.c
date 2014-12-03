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
		*(grille+i) = '_';
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

/* =======================  Fonctions de Test  ===================== */

#define N 100

int test_init_grille()
{
	int i, r;
	srand(time(NULL));

	/* On teste aléatoirement chaque case et on vérifie le contenue. */
	r = rand() % (TAILLE_GRILLE); 
	for(i = 0 ; i < N ; i++, r=rand() % TAILLE_GRILLE)
	{
		assert(*(grille+r) == '_');
	}
		
	return 1;
}


/* ============================ Main ============================== */
int main(void)
{
	init_grille();
	assert(test_init_grille()); 
	afficher_grille();
	exit(EXIT_SUCCESS); 
}
