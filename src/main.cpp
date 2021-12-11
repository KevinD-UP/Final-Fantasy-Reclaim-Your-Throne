//
// Created by kevin on 11/12/2021.
//

#include "header/model/Personnage/Personnage.h"
#include "header/model/Personnage/PersonnageFactory.h"

int main(){

    Personnage* guerrier = PersonnageFactory::initPersonnage("Guerrier","Test");
    Personnage* sorcier = PersonnageFactory::initPersonnage("Sorcier","Test2");
    Personnage* moine = PersonnageFactory::initPersonnage("Moine","Test3");
    Personnage* amazone = PersonnageFactory::initPersonnage("Amazone","Test4");

    guerrier->print();
    sorcier->print();
    moine->print();
    amazone->print();
}