//
// Created by kevin on 13/12/2021.
//

#ifndef FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H
#define FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H



#include <iostream>
#include "../Personnage/Personnage.h"

class Joueur {
    private:
        Personnage* personnageJoueur;

    public:
        Joueur(Personnage* personnageJoueurArg);
        void interactionEnCombat (Personnage *cible) const;
        void interactionHorsCombat() const;
        Personnage* getPerso() const;
};

#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H
