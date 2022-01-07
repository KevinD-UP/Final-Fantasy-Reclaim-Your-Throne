//
// Created by kevin on 13/12/2021.
//

#include "../../../header/model/Joueur/Joueur.h"


Joueur::Joueur(Personnage * personnageJoueurArg) : personnageJoueur(personnageJoueurArg) {}

Personnage* Joueur::getPerso() const {
    return personnageJoueur;
}

void Joueur::interactionEnCombat(Personnage *cible) const {
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
    else {
        std::cout << "Action non existante, rééssayer" << std::endl;
        return interactionEnCombat(cible);
    }
}

Piece* Joueur::interactionHorsCombat() const {
    std::cout << "1 - Deplacement "
              << "2 - Objet " << std::endl;
    std::string action;
    std::cin >> action;
    if(action == "1") {
        return deplacementJoueur();
    }
    else if(action == "2"){
        //personnageJoueur->actionObjet(this);
        return interactionHorsCombat();
    }
    else {
        std::cout << "Action non existante, rééssayer" << std::endl;
        return interactionHorsCombat();
    }
}

Piece* Joueur::deplacementJoueur() const {
    std::cout << "1 - Haut " << "2 - Gauche " << "3 - Bas " << "4 - Droite " << "5 - Retour";
    std::cout << std::endl;
    std::string action;
    std::cin >> action;
    if (action == "1") {
        if(getPerso()->getPieceCour()->getVecPieceAdjacentes()[0] != nullptr) {
            std::cout << "Direction vers le haut " << std::endl;
            return personnageJoueur->deplacement(0);
        }
    }
    else if (action == "2") {
        if (getPerso()->getPieceCour()->getVecPieceAdjacentes()[1] != nullptr) {
            std::cout << "Direction vers le gauche " << std::endl;
            return personnageJoueur->deplacement(1);
        }
    }
    else if (action == "3") {
        if (getPerso()->getPieceCour()->getVecPieceAdjacentes()[2] != nullptr) {
            std::cout << "Direction vers le bas " << std::endl;
            return personnageJoueur->deplacement(2);
        }
    }
    else if (action == "4") {
        if (getPerso()->getPieceCour()->getVecPieceAdjacentes()[3] != nullptr) {
            std::cout << "Direction vers le droite " << std::endl;
            return personnageJoueur->deplacement(3);
        }
    }
    else if (action == "5") {
        return this->interactionHorsCombat();
    }
    std::cout << "Il semblerait que vous allez droit vers un mur, réessayer" << std::endl;
    return this->deplacementJoueur();
}





