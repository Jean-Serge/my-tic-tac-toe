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

static int index_of(int col, int ligne)
{
	return col * LONGUEUR + ligne;
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
		assert(*(grille+r) == VIDE);
	}
		
	return 1;
}


/* ============================ Main ============================== */
int main(void)
{
	init_grille();
	assert(test_init_grille()); 
	afficher_grille();

	assert(placer_symbole(0, 0, 'X'));
	assert(*grille == 'X');
	assert(!placer_symbole(0, 0, 'O'));
	assert(placer_symbole(2,2,'O'));
	assert(*(grille+8) == 'O');
	afficher_grille();
	exit(EXIT_SUCCESS); 
}
