//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY___RECLAIM_YOUR_THRONE_PERSONNAGEFACTORY_H
#define FINAL_FANTASY___RECLAIM_YOUR_THRONE_PERSONNAGEFACTORY_H
#include "Personnage.h"
#include "Amazone.h"
#include "Guerrier.h"
#include "Moine.h"
#include "Sorcier.h"

enum PersonnageType{
    PT_Guerrier,
    PT_Amazone,
    PT_Moine,
    PT_Sorcier,
};

class PersonnageFactory {

public:
    static Personnage* initPersonnage(PersonnageType& personnagetype, const std::string& nom);
};


#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_PERSONNAGEFACTORY_H
