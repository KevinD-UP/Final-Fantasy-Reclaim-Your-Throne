//
// Created by kevin on 13/12/2021.
//

#ifndef FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H
#define FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H



#include <iostream>
class Personnage;

class Joueur {
    private:
        Personnage* personnageJoueur;

    public:
        explicit Joueur(Personnage* personnageJoueurArg);
        void interactionEnCombat (Personnage *cible) const;
        void interactionHorsCombat() const;
        Personnage* getPerso() const;
};

#include "../Personnage/Personnage.h"
#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H
