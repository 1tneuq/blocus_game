# TP 19 Exercice 1 : fichier Makefile

# CHAPITRE 1 : BUT FINAL

but : blocus

# CHAPITRE 2 : VARIABLES

OFILES	=	./biblio/affichage/fonctionsCentrage.o \
					./biblio/souris/clickDansRectangle.o \
					./biblio/affichage/DessinerElementsPlateau.o \
					./biblio/fonctionnement/fonctionnementJeu.o \
					./biblio/fonctionnement/multijoueur.o \
					./biblio/fonctionnement/ia.o \
					./main.o

CC = gcc

CFLAGS = -Wall -ansi

# CHAPITRE 3 : DEPENDANCES (REGLES IMPLICITES)

./biblio/affichage/fonctionsCentrage.o : ./biblio/affichage/affichage.h ./biblio/souris/souris.h

./biblio/souris/clickDansRectangle.o : ./biblio/souris/souris.h ./biblio/affichage/affichage.h

./biblio/affichage/DessinerElementsPlateau.o : ./biblio/affichage/affichage.h

./biblio/fonctionnement/fonctionnementJeu.o : ./biblio/fonctionnement/fonctionnementJeu.h ./biblio/affichage/affichage.h

./biblio/fonctionnement/multijoueur.o :	./biblio/fonctionnement/fonctionnementJeu.h ./biblio/affichage/affichage.h

./biblio/fonctionnement/ia.o : ./biblio/fonctionnement/fonctionnementJeu.h ./biblio/affichage/affichage.h

./main.o : ./biblio/fonctionnement/fonctionnementJeu.h ./biblio/affichage/affichage.h


#CHAPITRE 4 : DEPENDANCES AVEC COMMANDES

blocus : $(OFILES)
	$(CC) $(CFLAGS) -o blocus $(OFILES) -lgraph

#CHAPITRE 5 : NETTOYAGE DES FICHIERS GENERES

clean :
	-rm -f $(OFILES) blocus

run :
	-./blocus

#CHAPITRE 6 : BUTS FACTICES

.PHONY : but clean
