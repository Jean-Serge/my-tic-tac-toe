#include <stdlib.h>

#include "include/joueur.h"

void init_joueur(char *nom, char symb, joueur_t *j)
{
	j->symbole = symb;
	j->nom = nom;
}
