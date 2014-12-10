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
		printf("============= Début du tour ==============\n");

		placer_symbole(rand()%LONGUEUR, rand()%LONGUEUR, courant);
		courant = courant == j1 ? j2 : j1;
		afficher_grille();

		printf("============== Fin du tour ===============\n");
	} while(!est_nulle() && !est_gagnee(&vainqueur));

	if(est_nulle())
		printf("La partie se termine par un match nul.\n");
	else
		printf("La partie a été remportée par le symbole %c.\n", vainqueur);	

	printf("Partie Terminée\n");
	exit(EXIT_SUCCESS);
}
