//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Objet/Equipement.h"

Equipement::Equipement
    (std::string nom_arg,
     ObjetType objetType_arg,
     std::string description_arg,
     PersonnageType personnageType_arg,
     bool estEquipe_arg, int buffAttaque_arg, int buffDefense_arg, int buffSante_arg, int rarete_arg)
    : Objet(std::move(nom_arg), objetType_arg, std::move(description_arg)),
    bonusClass(personnageType_arg),
    estEquipe(estEquipe_arg),
    buffAttaque(buffAttaque_arg),
    buffDefense(buffDefense_arg),
    buffSante(buffSante_arg),
    rarete(rarete_arg)
{}

bool Equipement::checkCible() {
    return false;
}

bool Equipement::checkTp() {
    return false;
}

int Equipement::getRarete(){
    return rarete;
}
void Equipement::appliquerEffet(Personnage *cible) {
    if(!estEquipe) {
        if (this->bonusClass == cible->getPersonnageType()) {
            cible->setMaxAttaque(cible->getAttaqueMax() + buffAttaque);
            cible->setAttaque(cible->getAttaqueMax());

            cible->setMaxDefense(cible->getDefenseMax() + buffDefense);
            cible->setDefense(cible->getDefenseMax());

            cible->setMaxSante(cible->getSanteMax() + buffSante);
            cible->setSante(cible->getSante() + buffSante);
        } else {
            cible->setMaxAttaque(cible->getAttaqueMax() + buffAttaque/2);
            cible->setAttaque(cible->getAttaqueMax());

            cible->setMaxDefense(cible->getDefenseMax() + buffDefense/2);
            cible->setDefense(cible->getDefenseMax());

            cible->setMaxSante(cible->getSanteMax() + buffSante/2);
            cible->setSante(cible->getSante() + buffSante);
        }
        estEquipe = true;
    }
}

void Equipement::enleverEffet(Personnage *cible){
    if(estEquipe) {
        if (this->bonusClass == cible->getPersonnageType()) {
            cible->setMaxAttaque(cible->getAttaqueMax() - buffAttaque);
            cible->setAttaque(cible->getAttaqueMax());

            cible->setMaxDefense(cible->getDefenseMax() - buffDefense);
            cible->setDefense(cible->getDefenseMax());

            cible->setMaxSante(cible->getSanteMax() - buffSante);
            cible->setSante(cible->getSante() - buffSante);
        } else {
            cible->setMaxAttaque(cible->getAttaqueMax() - buffAttaque/2);
            cible->setAttaque(cible->getAttaqueMax());

            cible->setMaxDefense(cible->getDefenseMax() - buffDefense/2);
            cible->setDefense(cible->getDefenseMax());

            cible->setMaxSante(cible->getSanteMax() - buffSante/2);
            cible->setSante(cible->getSante() - buffSante);
        }
        estEquipe = false;
    }
}

