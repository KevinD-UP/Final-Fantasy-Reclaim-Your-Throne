//
// Created by kevin on 13/12/2021.
//

#include "../../../header/model/Joueur/Joueur.h"


Joueur::Joueur(Personnage * personnageJoueurArg) : personnageJoueur(personnageJoueurArg) {}

const Personnage* Joueur::getPerso() const {
    return personnageJoueur;
}




