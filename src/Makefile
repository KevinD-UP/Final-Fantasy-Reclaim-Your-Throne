CPP=g++
CFLAGS= -Wall

all : main

main: main.o PersonnageFactory.o ConsommableFactory.o Personnage.o Guerrier.o Amazone.o Moine.o Sorcier.o Consommable.o Equipement.o Objet.o Action.o Joueur.o Partie.o Piece.o
	$(CPP) $(CFLAGS) -o $@ $^

main.o : main.cpp header/model/Personnage/PersonnageFactory.h header/model/Personnage/Personnage.h header/model/Action/Action.h header/model/Joueur/Joueur.h header/Partie.h
	$(CPP) $(CFLAGS) -c $<

Guerrier.o : implem/model/Personnage/Guerrier.cpp header/model/Personnage/Guerrier.h
	$(CPP) $(CFLAGS) -c $<

Amazone.o : implem/model/Personnage/Amazone.cpp header/model/Personnage/Amazone.h
	$(CPP) $(CFLAGS) -c $<

Moine.o : implem/model/Personnage/Moine.cpp header/model/Personnage/Moine.h
	$(CPP) $(CFLAGS) -c $<

Sorcier.o : implem/model/Personnage/Sorcier.cpp header/model/Personnage/Sorcier.h
	$(CPP) $(CFLAGS) -c $<

Personnage.o : implem/model/Personnage/Personnage.cpp header/model/Personnage/Personnage.h
	$(CPP) $(CFLAGS) -c $<

PersonnageFactory.o : implem/model/Personnage/PersonnageFactory.cpp header/model/Personnage/PersonnageFactory.h
	$(CPP) $(CFLAGS) -c $<

ConsommableFactory.o : implem/model/Objet/ConsommableFactory.cpp header/model/Objet/ConsommableFactory.h
	$(CPP) $(CFLAGS) -c $<

Consommable.o : implem/model/Objet/Consommable.cpp header/model/Objet/Consommable.h
	$(CPP) $(CFLAGS) -c $<

Equipement.o : implem/model/Objet/Equipement.cpp header/model/Objet/Equipement.h
	$(CPP) $(CFLAGS) -c $<

Objet.o : implem/model/Objet/Objet.cpp header/model/Objet/Objet.h
	$(CPP) $(CFLAGS) -c $<

Action.o : implem/model/Action/Action.cpp header/model/Action/Action.h
	$(CPP) $(CFLAGS) -c $<

Joueur.o : implem/model/Joueur/Joueur.cpp header/model/Joueur/Joueur.h
	$(CPP) $(CFLAGS) -c $<

Partie.o : implem/Partie.cpp header/Partie.h
	$(CPP) $(CFLAGS) -c $<

Piece.o : implem/model/Piece/Piece.cpp header/model/Piece/Piece.h
	$(CPP) $(CFLAGS) -c $<

clean :
	rm *.o main

test: all
	./main
