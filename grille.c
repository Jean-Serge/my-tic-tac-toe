#include "grille.h"

void init_grille()
{
	int i, j;

	for(i =0 ; i < TAILLE_GRILLE ; i++)
	{
		for(j = 0 ; i < TAILLE_GRILLE ; j++)
		{
			grille[i] [j] = ' ';
		}
	}
}
