//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Personnage.h"

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

std::pair<Personnage::Statut, int> Personnage::getStatut() {
    return statut;
}

std::vector<Objet *> Personnage::getSac() {
    return sac;
}

