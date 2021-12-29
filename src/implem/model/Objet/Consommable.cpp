//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Objet/Consommable.h"

#include <utility>

Consommable::Consommable( std::string nom_arg,  ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg)
: Objet(std::move(nom_arg), objetType_arg, std::move(description_arg)), typeConsommable(consommableType_arg)
{}

void Consommable::appliquerEffet(Personnage * cible) {
    this->appliquerConsommable(cible);
}

void Consommable::enleverEffet(Personnage * cible) {}

__attribute__((unused)) ConsommableType Consommable::getTypeConsommable() const {
    return typeConsommable;
}

PotionSoin::PotionSoin(const std::string& nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg, int pouvoirDeSoin_arg)
: Consommable(nom_arg, objetType_arg, std::move(description_arg), consommableType_arg)
{}

PotionBrulure::PotionBrulure(const std::string& nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg)
        : Consommable(nom_arg, objetType_arg, std::move(description_arg), consommableType_arg)
{}

PotionPoison::PotionPoison(const std::string& nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg)
        : Consommable(nom_arg, objetType_arg, std::move(description_arg), consommableType_arg)
{}

PotionSomnolence::PotionSomnolence(const std::string& nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg)
        : Consommable(nom_arg, objetType_arg, std::move(description_arg), consommableType_arg)
{}

PotionBerserk::PotionBerserk(const std::string& nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg)
        : Consommable(nom_arg, objetType_arg, description_arg, consommableType_arg)
{}

PotionAffaiblie::PotionAffaiblie(const std::string& nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg)
        : Consommable(nom_arg, objetType_arg, description_arg, consommableType_arg)
{}

PotionEcorcher::PotionEcorcher(const std::string& nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg)
        : Consommable(nom_arg, objetType_arg, description_arg, consommableType_arg)
{}

PotionProteger::PotionProteger(const std::string& nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg)
        : Consommable(nom_arg, objetType_arg, description_arg, consommableType_arg)
{}

PotionChallenge::PotionChallenge(const std::string& nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg)
        : Consommable(nom_arg, objetType_arg, description_arg, consommableType_arg)
{}

void PotionSoin::appliquerConsommable(Personnage *cible) {
    cible->setSante(cible->getSante() + cible->getSanteMax()/4);
    if(cible->getSante() > cible->getSanteMax()){
        cible->setSante(cible->getSanteMax());
    }
}

void PotionBrulure::appliquerConsommable(Personnage *cible) {
    cible->debuff(Bruler,3,cible);
}


void PotionPoison::appliquerConsommable(Personnage *cible) {
    cible->debuff(Empoisonner,3,cible);
}


void PotionSomnolence::appliquerConsommable(Personnage *cible) {
    cible->debuff(Etourdit,2,cible);
}

void PotionBerserk::appliquerConsommable(Personnage *cible) {
    cible->buff(Berserk,3);
}

void PotionAffaiblie::appliquerConsommable(Personnage *cible) {
    cible->debuff(Affaiblie,3,cible);
}

void PotionEcorcher::appliquerConsommable(Personnage *cible) {
    cible->debuff(Ecorcher,3,cible);
}

void PotionProteger::appliquerConsommable(Personnage *cible) {
    cible->buff(Proteger,2);
}

void PotionChallenge::appliquerConsommable(Personnage *cible) {
    cible->buff(Proteger,2);
}