//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Objet/Consommable.h"

Consommable::Consommable( std::string nom_arg,  ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg)
: Objet(nom_arg, objetType_arg, description_arg), typeConsommable(consommableType_arg)
{}

void Consommable::appliquerEffet(Personnage * cible) {
    this->appliquerConsommable(cible);
}


PotionSoin::PotionSoin(const std::string nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg, int pouvoirDeSoin_arg)
: Consommable(nom_arg, objetType_arg, description_arg, consommableType_arg), pouvoirDeSoin(pouvoirDeSoin_arg)
{}

PotionBrulure::PotionBrulure(const std::string nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg)
        : Consommable(nom_arg, objetType_arg, description_arg, consommableType_arg)
{}

PotionPoison::PotionPoison(const std::string nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg)
        : Consommable(nom_arg, objetType_arg, description_arg, consommableType_arg)
{}

PotionSomnolence::PotionSomnolence(const std::string nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg)
        : Consommable(nom_arg, objetType_arg, description_arg, consommableType_arg)
{}

void PotionSoin::appliquerConsommable(Personnage *cible) {
    cible->setSante(cible->getSante()+pouvoirDeSoin);
    if(cible->getSante() > cible->getSanteMax()){
        cible->setSante(cible->getSanteMax());
    }
}

void PotionBrulure::appliquerConsommable(Personnage *cible) {

}


void PotionPoison::appliquerConsommable(Personnage *cible) {

}


void PotionSomnolence::appliquerConsommable(Personnage *cible) {

}