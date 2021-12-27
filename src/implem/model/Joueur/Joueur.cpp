//
// Created by kevin on 13/12/2021.
//

#include "../../../header/model/Joueur/Joueur.h"


Joueur::Joueur(Personnage * personnageJoueurArg) : personnageJoueur(personnageJoueurArg) {}

Personnage* Joueur::getPerso() const {
    return personnageJoueur;
}

template<typename T>
void const Joueur::interactionEnCombat(T *cible) const {
    std::cout << "1 - Examiner "
              << "2 - Attaque "
              << "3 - Objet " << std::endl;
    std::string action;
    std::cin >> action;
    if(action == "1") {
        std::cout << std::endl;
        std::cout << personnageJoueur << std::endl;
        std::cout << cible << std::endl;
        this->interactionEnCombat(cible);
    }
    else if(action == "2"){
        personnageJoueur->actionJoueur(this, cible);
    }
    else if(action == "3"){
        personnageJoueur->actionObjet(this, cible);
    }
}






