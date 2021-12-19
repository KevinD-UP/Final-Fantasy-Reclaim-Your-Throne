//
// Created by kevin on 18/12/2021.
//

#ifndef FINAL_FANTASY_RECLAIM_YOUR_THRONE_PARTIE_H
#define FINAL_FANTASY_RECLAIM_YOUR_THRONE_PARTIE_H

#include "model/Personnage/Personnage.h"
#include "model/Joueur/Joueur.h"

class Partie {

    private:
        const std::vector<Personnage*> persoEnJeu;
        const Joueur* joueur;

    public:
        const std::vector<Personnage*> getPersoEnJeu() const;
        const Joueur* getJoueur() const;
        void startToPlay();
        Partie(const std::vector<Personnage*> persoEnJeuArg, const Joueur* joueurArg);
};


#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_PARTIE_H
