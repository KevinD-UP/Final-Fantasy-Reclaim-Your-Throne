//
// Created by kevin on 11/12/2021.
//

#include "header/model/Personnage/Personnage.h"
#include "header/model/Personnage/PersonnageFactory.h"
#include "header/model/Joueur/Joueur.h"

int main(){

    PersonnageType TYPE_Guerrier = PT_Guerrier;
    //PersonnageType TYPE_Amazone = PT_Amazone;
    //PersonnageType TYPE_Moine = PT_Moine;
    PersonnageType TYPE_Sorcier = PT_Sorcier;

    Personnage* guerrier = PersonnageFactory::initPersonnage(TYPE_Guerrier,"Test");
    Personnage* sorcier = PersonnageFactory::initPersonnage(TYPE_Sorcier,"Test2");
   // Personnage* moine = PersonnageFactory::initPersonnage(TYPE_Moine,"Test3");
   // Personnage* amazone = PersonnageFactory::initPersonnage(TYPE_Amazone,"Test4");

    sorcier->action("boule de feu", guerrier);

    Joueur *A = new Joueur (sorcier);
    A->interagir<Personnage>(Examine,guerrier);
    A->interagir<Personnage>(Attaque,guerrier);
    guerrier->print();
    /*sorcier->print();
    moine->print();
    amazone->print();
     */


}