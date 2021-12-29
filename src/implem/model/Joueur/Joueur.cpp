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
}

Piece* Joueur::interactionHorsCombat() const {

    try {
        std::cout << "1 - Haut " << "2 - Gauche " << "3 - Bas" << "4 - Droite" << std::endl;
        std::string action;
        std::cin >> action;
        if (action == "1") {
            std::cout << "Direction vers le haut " << std::endl;
            return personnageJoueur->deplacement(0);
        }
        if (action == "2") {
            std::cout << "Direction vers le gauche " << std::endl;
            return personnageJoueur->deplacement(1);
        }
        if (action == "3") {
            std::cout << "Direction vers le bas " << std::endl;
            return personnageJoueur->deplacement(2);
        }
        if (action == "4") {
            std::cout << "Direction vers le droite " << std::endl;
            return personnageJoueur->deplacement(3);
        } else {
            std::cout << "Choissisez un chemin valide" << std::endl;
            return this->interactionHorsCombat();
        }
    } catch (Exception e){
        std::cout << "Il semblerait que vous allez droit vers un mur, réessayer" << std::endl;
        return this->interactionHorsCombat()
    }

}






