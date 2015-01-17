CC = gcc
CFLAGS = -Wall -ansi -pedantic -g

INCLUDE = include
BINARIES = *.bin

all: morpion test


# Création de l'exécutable final
morpion: morpion.c grille.o joueur.o
	$(CC) $(CFLAGS) -o morpion.bin morpion.c grille.o joueur.o

# Construction de l'exécutable de test	
test: test.c grille.o
	$(CC) $(CFLAGS) -o test.bin test.c grille.o

# Règles de construction des dépendances
grille.o: grille.c $(INCLUDE)/grille.h
	$(CC) $(CFLAGS) -c grille.c
joueur.o: joueur.c $(INCLUDE)/joueur.h
	$(CC) $(CFLAGS) -c joueur.c

.PHONY: clean
clean: 
	rm -f $(BINARIES) *.o  
