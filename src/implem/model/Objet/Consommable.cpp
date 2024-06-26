//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Objet/Consommable.h"

Consommable::Consommable( std::string nom_arg,  ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg, ConsommableCible consommableCible_arg)
: Objet(std::move(nom_arg), objetType_arg, std::move(description_arg)), typeConsommable(consommableType_arg), cibleConsommable(consommableCible_arg)
{}

void Consommable::appliquerEffet(Personnage * cible) {
    this->appliquerConsommable(cible);
}

bool Consommable::checkTp() {
    return getTypeConsommable() == CT_POTIONTELEPORTATION;
}

void Consommable::enleverEffet(Personnage * cible) {}

ConsommableType Consommable::getTypeConsommable() const {
    return typeConsommable;
}

bool Consommable::checkCible(){
    return this->cibleConsommable == CC_SELF ;
}

int Consommable::getRarete() {
    return 0;
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

PotionTeleportation::PotionTeleportation(const std::string& nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg, ConsommableCible consommableCible_arg)
        : Consommable(nom_arg, objetType_arg, std::move(description_arg), consommableType_arg, consommableCible_arg)
{}

PotionElixir::PotionElixir(const std::string& nom_arg, const ObjetType objetType_arg, std::string description_arg, ConsommableType consommableType_arg, ConsommableCible consommableCible_arg)
        : Consommable(nom_arg, objetType_arg, std::move(description_arg), consommableType_arg, consommableCible_arg)
{}

void PotionSoin::appliquerConsommable(Personnage *cible) {
    cible->setSante(cible->getSante() + cible->getSanteMax()/4);
    if(cible->getSante() > cible->getSanteMax()){
        cible->setSante(cible->getSanteMax());
    }
}

void PotionElixir::appliquerConsommable(Personnage *cible) {
    cible->setSante(cible->getSanteMax());
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

void PotionTeleportation::appliquerConsommable(Personnage *cible) {
    std::cout << "Choisir une coordonnée x y" << std::endl;
    std::string x = "";
    std::string y = "";
    std::cin >> x >> y;
    if(stoi(x) < 0 || stoi(x) > 3){
        std::cout << "Mauvaise coordonné x" << std::endl;
        return this->appliquerConsommable(cible);
    }
    else if(stoi(y) < 0 || stoi(y) > 3){
        std::cout << "Mauvaise coordonné x" << std::endl;
        return this->appliquerConsommable(cible);
    }
    else{
        cible->getPieceCour()->removePerso(cible);
        cible->getMap()->getMap()[stoi(x)][stoi(y)]->pushPerso(cible);
        cible->setPiece(cible->getMap()->getMap()[stoi(x)][stoi(y)]);
    }
}