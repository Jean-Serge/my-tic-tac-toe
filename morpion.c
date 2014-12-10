#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "grille.h"

int main(void)
{
	/* Initialisation */
	char j1, j2, courant, vainqueur;
	j1 = 'O';
	j2 = 'X';
	courant = j1;
	srand(time(NULL));
	init_grille();

	/* Jeu */
	printf("Début de la partie\n");
	do{
		placer_symbole(rand()%LONGUEUR, rand()%LONGUEUR, courant);
		courant = courant == j1 ? j2 : j1;
	}while(!est_nulle() && !est_gagnee(&vainqueur));
	exit(EXIT_SUCCESS);
}
