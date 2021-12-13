//
// Created by kevin on 13/12/2021.
//

#include "../../../header/model/Joueur/Joueur.h"

Joueur::Joueur(Personnage * personnageJoueurArg) : personnageJoueur(personnageJoueurArg) {}

void Joueur::interagir(Interaction& actionType, std::string cible) {
    if(actionType == Check){
        //std::cout << cible << std::endl;
    } else if(actionType == Objet){

    } else if(actionType == Attaque){

    }
}
