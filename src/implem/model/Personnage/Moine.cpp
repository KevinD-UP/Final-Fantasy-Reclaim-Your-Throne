//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Moine.h"

Moine::Moine(std::string nom, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet *> sac) :
    Personnage(nom, sante, attaque, typePersonnage ,defense, sac)
{}

void Moine::print() {
    std::cout << "Je suis une Moine" << std::endl;
}

void Moine::action(std::string nom, Personnage * ennemie){}