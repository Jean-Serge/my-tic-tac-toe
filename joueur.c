#include <stdlib.h>
#include <stdio.h>

#include "include/joueur.h"

void init_joueur(char *nom, char symb, joueur_t *j)
{
	j->symbole = symb;
	j->nom = nom;
}

int saisir_coord(unsigned int *col, unsigned int *ligne)
{
	printf("Veuillez saisir les coordonnées de la case à marquer sous la forme 'X Y' : \n");

	return 1;
}
