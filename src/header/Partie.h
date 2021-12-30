//
// Created by kevin on 18/12/2021.
//

#ifndef FINAL_FANTASY_RECLAIM_YOUR_THRONE_PARTIE_H
#define FINAL_FANTASY_RECLAIM_YOUR_THRONE_PARTIE_H

#include "model/Personnage/Personnage.h"
#include "model/Joueur/Joueur.h"
#include "model/Piece/Map.h"

class Partie {

    private:
        std::vector<Personnage*> persoEnJeu;
        const Joueur* joueur;
        const Map* chateau{};

    public:
        std::vector<Personnage*> getPersoEnJeu() const;
        const Joueur* getJoueur() const;
        const Map* getChateau() const;
        void startToPlay();
        Personnage * deathBattle(Personnage *a,  Personnage *b) const;
        bool finDePartie() const;
        void routine();
        Partie(std::vector<Personnage*> persoEnJeuArg, const Joueur* joueurArg,const Map* mapArg);
};


#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_PARTIE_H
