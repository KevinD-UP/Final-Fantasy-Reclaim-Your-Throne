//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Objet/Objet.h"

#include <utility>

Objet::Objet(std::string nom_arg, ObjetType objetType_arg, std::string description_arg) :
nom(std::move(nom_arg)), objetType(objetType_arg), description(std::move(description_arg)){}

Objet::~Objet() {
    std::cout << nom << " a été utilisé." << std::endl;
}

std::string Objet::getDescription() const {
    return description;
}

std::string Objet::getNom() const {
    return nom;
}

ObjetType Objet::getObjetType() const {
    return objetType;
}