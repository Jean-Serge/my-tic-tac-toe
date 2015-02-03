CC = gcc
CFLAGS = -Wall -ansi -pedantic -g

INCLUDE = ./include/
BINARIES = *.bin
SRCDIR = src/
BINDIR = bin/
LIBS = -I${INCLUDE}

all: morpion test


# Création de l'exécutable final
morpion: ${SRCDIR}morpion.c grille joueur
	$(CC) $(CFLAGS) -o morpion.bin ${SRCDIR}morpion.c ${BINDIR}grille.o ${BINDIR}joueur.o ${LIBS}

# Construction de l'exécutable de test	
test: ${SRCDIR}test.c grille
	$(CC) $(CFLAGS) -o test.bin ${SRCDIR}test.c ${BINDIR}grille.o ${LIBS}

# Règles de construction des dépendances
grille: ${SRCDIR}grille.c $(INCLUDE)grille.h
	$(CC) $(CFLAGS) -c ${SRCDIR}grille.c -o ${BINDIR}grille.o ${LIBS}
joueur: ${SRCDIR}joueur.c $(INCLUDE)joueur.h
	$(CC) $(CFLAGS) -c ${SRCDIR}joueur.c -o ${BINDIR}joueur.o ${LIBS}

.PHONY: clean
clean: 
	rm -f $(BINARIES) ${BINDIR}*.o  
