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

class PersonnageFactory {


public:
    static Personnage* initPersonnage(const std::string& personnagetype, const std::string& nom);
};


#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_PERSONNAGEFACTORY_H
