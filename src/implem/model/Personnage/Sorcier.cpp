//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Sorcier.h"

Sorcier::Sorcier(std::string nom, int sante, int attaque, int defense, std::vector<Objet *> sac) : Personnage(nom, sante, attaque, defense, sac)
{}

void Sorcier::print() {
    std::cout << "Je suis une Sorcier" << std::endl;
}