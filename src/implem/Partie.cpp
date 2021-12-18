//
// Created by kevin on 18/12/2021.
//

#include "../header/Partie.h"

void Partie::startToPlay() {
    std::cout << "Partie Lancée" << std::endl;
    for (auto & personnage: persoEnJeu) {
        personnage->print();
    }
}

const std::vector<Personnage *> Partie::getPersoEnJeu() const {
    return persoEnJeu;
}

const Joueur *Partie::getJoueur() const {
    return joueur;
}