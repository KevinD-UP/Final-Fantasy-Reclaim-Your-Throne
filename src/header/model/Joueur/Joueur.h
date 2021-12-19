//
// Created by kevin on 13/12/2021.
//

#ifndef FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H
#define FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H

#include "../Personnage/Personnage.h"
#include <iostream>
using namespace std;
class IJoueur{

};

enum Interaction{Examine, Objet, Attaque};

class Joueur : public IJoueur {
    private:
        Personnage* personnageJoueur;
        //Piece* pieceCourante;

    public:
        Joueur(Personnage* personnageJoueurArg);
        template<class T> void interagir (Interaction actionType, T *cible){
            if(actionType == Examine){
                std::cout << "CHECKING" << std::endl;
                std::cout << cible << std::endl;
            } else if(actionType == Objet){

            } else if(actionType == Attaque){
                std::string attaque;
                std::cout << "Attaqué avec ";
                std::cin >> attaque;
                std::cout << std::endl;
                personnageJoueur->action(attaque,cible);
            }
        }
        //Piece setPiece(Piece*);

};
#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H
