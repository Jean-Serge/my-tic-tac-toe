#include "include/joueur.h"

void init_joueur(char *nom, char symb, joueur_t *j)
{
	j->symbole = symb;
	j->nom = nom;
}

/**
 *	Permet de lire un entier valide sur l'entrée standard.
 * 	Retourne la valeur saisie si elle est correcte, -1 sinon.
 *	Les caractères suivant un chiffres seront ignorés (jusqu'au 
 *	saut de ligne).
 */
static int saisir_int()
{
	char c;
	int valeur = 0;

	c = getchar();
	/* On ignore les caractères suivants. */
	while(getchar() != '\n');

	/* On cherche une valeur à 1 chiffre */
	if(!isdigit(c))
	{
		printf("Veuillez saisir un chiffre.\n");
		return -1;
	}
	valeur = c - '0';

	/* On vérifie que ce chiffre est valide. */
	if(valeur >= 1 && valeur <= LONGUEUR)
		return valeur;

	printf("Veuillez saisir une valeur valide (entre 1 et %d).\n", LONGUEUR);
	return -1;
}

int saisir_coord(unsigned int *col, unsigned int *ligne)
{
	printf("Veuillez saisir les coordonnées de la case à marquer sous la forme 'X Y' : \n");
	printf("Colonne : ");
	while((*col = saisir_int()) == -1);

	printf("\nLigne : ");
	while((*ligne = saisir_int()) == -1);
		
	return 1;
}

