//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Personnage.h"
#include "../../../header/model/Action/Action.h"

#include <utility>

Personnage::Personnage(std::string nom_arg,
                       const int &sante_arg,
                       const int &attaque_arg,
                       const int &defense_arg,
                       std::vector<Objet*> sac_arg) : nom(std::move(nom_arg)), indice_de_sante(sante_arg), attaque(attaque_arg), defense(defense_arg), sac(std::move(sac_arg))
{}

std::string Personnage::getNom() const {
    return nom;
}

int Personnage::getAttaque() const {
    return attaque;
}

int Personnage::getDefense() const {
    return defense;
}

int Personnage::getSante() const {
    return indice_de_sante;
}


std::vector<Objet *> Personnage::getSac() {
    return sac;
}

void Personnage::setSante(int x) {
    indice_de_sante = x;
}

void Personnage::setAttaque(int x) {
    attaque = x;
}

void Personnage::setDefense(int x) {
    defense = x;
}

void Personnage::pushSac(Objet * x) {
    sac.push_back(x);
}

void Personnage::action(std::string, Personnage *) {}
/*void Personnage::pushStatut(std::pair<Personnage::Statut, int> x) {
    statut.push_back(x);
}*/