//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Moine.h"

Moine::Moine(std::string nom, int sante, int attaque, int defense, std::vector<Objet *> sac) : Personnage(std::move(nom), sante, attaque, defense, std::move(sac))
{}

void Moine::print() {
    std::cout << "Je suis une Moine" << std::endl;
}

void Moine::action(std::string nom, Personnage * ennemie){}