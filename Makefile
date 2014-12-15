CC = gcc
CFLAGS = -Wall -ansi -pedantic -g

BINARIES = morpion test

all: morpion test


# Création de l'exécutable final
morpion: morpion.c grille.o joueur.o
	$(CC) $(CFLAGS) -o morpion morpion.c grille.o joueur.o

# Construction de l'exécutable de test	
test: test.c grille.o
	$(CC) $(CFLAGS) -o test test.c grille.o

# Règles de construction des dépendances
grille.o: grille.c grille.h
	$(CC) $(CFLAGS) -c grille.c
joueur.o: joueur.c joueur.h
	$(CC) $(CFLAGS) -c joueur.c

.PHONY: clean
clean: 
	rm $(BINARIES) *.o *~ 
