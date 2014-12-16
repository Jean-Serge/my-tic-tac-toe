#ifndef H_JOUEUR
#define H_JOUEUR

typedef struct
{
	char symbole;
	char *nom;
}joueur_t;

extern void init_joueur(char *, char, joueur_t *);

#endif
