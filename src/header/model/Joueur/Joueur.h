//
// Created by kevin on 13/12/2021.
//

#ifndef FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H
#define FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H



#include <iostream>
class Personnage;
class Piece;
class Map;

class Joueur {
    private:
        Personnage* personnageJoueur;
        Map* carte;

    public:
        explicit Joueur(Personnage* personnageJoueurArg, Map* carte);
        void interactionEnCombat (Personnage *cible) const;
        Piece* interactionHorsCombat() const;
        Piece* deplacementJoueur() const;
        Personnage* getPerso() const;
        void swap() const;
};

#include "../Personnage/Personnage.h"
#include "../Piece/Piece.h"
#include "../Piece/Map.h"
#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H
