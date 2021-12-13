//
// Created by kevin on 11/12/2021.
//

#include "header/model/Personnage/Personnage.h"
#include "header/model/Personnage/PersonnageFactory.h"

int main(){

    PersonnageType TYPE_Guerrier = PT_Guerrier;
    PersonnageType TYPE_Amazone = PT_Amazone;
    PersonnageType TYPE_Moine = PT_Moine;
    PersonnageType TYPE_Sorcier = PT_Sorcier;

    Personnage* guerrier = PersonnageFactory::initPersonnage(TYPE_Guerrier,"Test");
    Personnage* sorcier = PersonnageFactory::initPersonnage(TYPE_Sorcier,"Test2");
    Personnage* moine = PersonnageFactory::initPersonnage(TYPE_Moine,"Test3");
    Personnage* amazone = PersonnageFactory::initPersonnage(TYPE_Amazone,"Test4");

    guerrier->print();
    sorcier->print();
    moine->print();
    amazone->print();
}