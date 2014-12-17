#ifndef H_JOUEUR
#define H_JOUEUR

typedef struct
{
	char symbole;
	char *nom;
}joueur_t;

extern void init_joueur(char *, char, joueur_t *);

/**
 *	Demande à l'utilisateur de saisir les coordonnées de la case 
 * 	à marquer. Celles-ci seront placées dans les pointeurs ssi 
 * 	elles sont valides.
 * 	Retourne 1 si c'est le cas, 0 sinon.
 */
extern int saisir_coord(unsigned int *, unsigned int *);

#endif
