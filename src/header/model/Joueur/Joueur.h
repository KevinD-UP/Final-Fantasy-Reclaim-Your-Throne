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

//enum Interaction{Examine, Objet, Attaque};

class Joueur : public IJoueur {
    private:

        //Piece* pieceCourante;

    public:
        Personnage* personnageJoueur;
        Joueur(Personnage* personnageJoueurArg);
        template<class T> void interagir (T *cible) const{
            std::cout << "1 - Examiner "
            << "2 - Attaque "
            << "3 - Objet " << std::endl;
            std::string action;
            std::cin >> action;
            //T *cible;
            if(action == "1") {
                std::cout << std::endl;
                std::cout << personnageJoueur << std::endl;
                std::cout << cible << std::endl;
                this->interagir(cible);
            }
            else if(action == "2"){
                personnageJoueur->actionJoueur(this,cible);
            }
            else if(action == "3"){
                personnageJoueur->actionObjet(this,cible);
            }
        }
        const Personnage* getPerso() const;
        //Piece setPiece(Piece*);

};
#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_JOUEUR_H
