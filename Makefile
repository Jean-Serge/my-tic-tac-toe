CC = gcc
CFLAGS = -Wall -ansi -pedantic -g



grille.bin: grille.c grille.h
	$(CC) $(CFLAGS) -o grille.bin grille.c


.PHONY: clean
clean: 
	rm *.bin
