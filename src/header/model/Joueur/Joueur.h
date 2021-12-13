//
// Created by kevin on 13/12/2021.
//

#ifndef FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H
#define FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H

#include "../Personnage/Personnage.h"
#include "../Piece/Piece.h"

class IJoueur{

};

enum Interaction{Check, Objet, Attaque};

class Joueur : public IJoueur {
    private:
        const Personnage* personnageJoueur;
        //Piece* pieceCourante;

    public:
        Joueur(Personnage*);
        void interagir(Interaction &actionType, std::string cible);
        //Piece setPiece(Piece*);

};
#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H
