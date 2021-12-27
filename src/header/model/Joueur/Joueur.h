//
// Created by kevin on 13/12/2021.
//

#ifndef FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H
#define FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H

#include "../Personnage/Personnage.h"

class Joueur {
    private:
        Personnage* personnageJoueur;

    public:
        Joueur(Personnage* personnageJoueurArg);
        template<typename T> const void interactionEnCombat (T *cible) const;
        void interactionHorsCombat() const;
        Personnage* getPerso() const;
};

#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H
