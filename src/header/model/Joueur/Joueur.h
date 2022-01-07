//
// Created by kevin on 13/12/2021.
//

#ifndef FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H
#define FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H



#include <iostream>
class Personnage;
class Piece;

class Joueur {
    private:
        Personnage* personnageJoueur;

    public:
        explicit Joueur(Personnage* personnageJoueurArg);
        void interactionEnCombat (Personnage *cible) const;
        Piece* interactionHorsCombat() const;
        Piece* deplacementJoueur() const;
        Personnage* getPerso() const;
};

#include "../Personnage/Personnage.h"
#include "../Piece/Piece.h"
#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H
