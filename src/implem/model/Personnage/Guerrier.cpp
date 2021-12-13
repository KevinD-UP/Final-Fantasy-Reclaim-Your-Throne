//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Guerrier.h"

Guerrier::Guerrier(std::string nom, int sante, int attaque, int defense, std::vector<Objet *> sac) : Personnage(nom, sante, attaque, defense, sac)
{}

void Guerrier::print() {
    std::cout << "Je suis une Guerrier" << std::endl;
    std::cout << "J'ai " << getSante() << "HP" << std::endl;
}

void Guerrier::action(std::string nom, Personnage * ennemie){}