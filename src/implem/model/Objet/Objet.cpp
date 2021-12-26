//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Objet/Objet.h"

Objet::Objet(std::string nom_arg, ObjetType objetType_arg, std::string description_arg) :
nom(nom_arg), objetType(objetType_arg), description(description_arg){}

std::string Objet::getDescription() const {
    return description;
}

std::string Objet::getNom() const {
    return nom;
}

ObjetType Objet::getObjetType() const {
    return objetType;
}