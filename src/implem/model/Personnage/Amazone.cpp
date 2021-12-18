//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Amazone.h"

Amazone::Amazone(std::string nom, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet *> sac) :
    Personnage(nom, sante, attaque, typePersonnage ,defense, sac)
{}

void Amazone::print() {
    std::cout << "Je suis une Amazone" << std::endl;
}

void Amazone::action(std::string nom, Personnage * ennemie){

}