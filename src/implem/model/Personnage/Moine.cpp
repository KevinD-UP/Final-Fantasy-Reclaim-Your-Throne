//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Moine.h"

Moine::Moine(std::string nom, int sante, int attaque, int defense, std::vector<Objet *> sac) : Personnage(nom, sante, attaque, defense, sac)
{}

void Moine::print() {
    std::cout << "Je suis une Moine" << std::endl;
}