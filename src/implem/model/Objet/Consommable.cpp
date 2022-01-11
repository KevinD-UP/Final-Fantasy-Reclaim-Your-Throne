//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Objet/Consommable.h"

#include <utility>

Consommable::Consommable( std::string nom_arg,  ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg, ConsommableCible consommableCible_arg)
: Objet(std::move(nom_arg), objetType_arg, std::move(description_arg)), typeConsommable(consommableType_arg), cibleConsommable(consommableCible_arg)
{}

void Consommable::appliquerEffet(Personnage * cible) {
    this->appliquerConsommable(cible);
}

void Consommable::enleverEffet(Personnage * cible) {}

__attribute__((unused)) ConsommableType Consommable::getTypeConsommable() const {
    return typeConsommable;
}

bool Consommable::checkCible(){
    return this->cibleConsommable == CC_SELF ;
}

PotionSoin::PotionSoin(const std::string& nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg, ConsommableCible consommableCible_arg)
: Consommable(nom_arg, objetType_arg, std::move(description_arg), consommableType_arg, consommableCible_arg)
{}

PotionBrulure::PotionBrulure(const std::string& nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg, ConsommableCible consommableCible_arg)
        : Consommable(nom_arg, objetType_arg, std::move(description_arg), consommableType_arg, consommableCible_arg)
{}

PotionPoison::PotionPoison(const std::string& nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg, ConsommableCible consommableCible_arg)
        : Consommable(nom_arg, objetType_arg, std::move(description_arg), consommableType_arg, consommableCible_arg)
{}

PotionSomnolence::PotionSomnolence(const std::string& nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg, ConsommableCible consommableCible_arg)
        : Consommable(nom_arg, objetType_arg, std::move(description_arg), consommableType_arg, consommableCible_arg)
{}

PotionBerserk::PotionBerserk(const std::string& nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg, ConsommableCible consommableCible_arg)
        : Consommable(nom_arg, objetType_arg, std::move(description_arg), consommableType_arg, consommableCible_arg)
{}

PotionAffaiblie::PotionAffaiblie(const std::string& nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg, ConsommableCible consommableCible_arg)
        : Consommable(nom_arg, objetType_arg, std::move(description_arg), consommableType_arg, consommableCible_arg)
{}

PotionEcorcher::PotionEcorcher(const std::string& nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg, ConsommableCible consommableCible_arg)
        : Consommable(nom_arg, objetType_arg, std::move(description_arg), consommableType_arg, consommableCible_arg)
{}

PotionProteger::PotionProteger(const std::string& nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg, ConsommableCible consommableCible_arg)
        : Consommable(nom_arg, objetType_arg, std::move(description_arg), consommableType_arg, consommableCible_arg)
{}

PotionChallenge::PotionChallenge(const std::string& nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg, ConsommableCible consommableCible_arg)
        : Consommable(nom_arg, objetType_arg, std::move(description_arg), consommableType_arg, consommableCible_arg){}

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
    cible->debuff(Etourdit,3,cible);
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
    cible->buff(Proteger,3);
}

void PotionChallenge::appliquerConsommable(Personnage *cible) {
    cible->buff(Proteger,2);
}