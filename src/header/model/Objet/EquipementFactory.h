//
// Created by kevin on 19/12/2021.
//

#ifndef FINAL_FANTASY_RECLAIM_YOUR_THRONE_EQUIPEMENTFACTORY_H
#define FINAL_FANTASY_RECLAIM_YOUR_THRONE_EQUIPEMENTFACTORY_H

#include "Equipement.h"

enum EquipementType {

};

class EquipementFactory {
public:
    virtual Equipement* FactoryMethod() const = 0;
    static Equipement* initObjet();
};

#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_EQUIPEMENTFACTORY_H
