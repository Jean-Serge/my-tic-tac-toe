#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "include/grille.h"
#include "include/joueur.h"

int main(void)
{
	joueur_t *j1, *j2, *courant;
	char vainqueur;

	/* Initialisation */
	j1 = (joueur_t *) malloc(sizeof(joueur_t *));
	j2 = (joueur_t *) malloc(sizeof(joueur_t *));

	init_joueur("Joueur 1", 'X', j1);
	init_joueur("Joueur 2", 'O', j2);
	courant = j1;

	srand(time(NULL));
	init_grille();

	/* Jeu */
	printf("Début de la partie\n");
	do{
		printf("============= Début du tour ==============\n");

		placer_symbole(rand()%LONGUEUR, rand()%LONGUEUR, courant->symbole);
		courant = courant == j1 ? j2 : j1;
		afficher_grille();

		printf("============== Fin du tour ===============\n");
	} while(!est_nulle() && !est_gagnee(&vainqueur));

	if(est_nulle())
		printf("La partie se termine par un match nul.\n");
	else
		printf("La partie a été remportée par le symbole %c.\n", vainqueur);	

	printf("Partie Terminée\n");

	/* Libération mémoire */
	free_grille();
	free(j1);
	free(j2);

	exit(EXIT_SUCCESS);
}
