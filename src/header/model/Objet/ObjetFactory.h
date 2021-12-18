//
// Created by kevin on 18/12/2021.
//

#ifndef FINAL_FANTASY_RECLAIM_YOUR_THRONE_OBJETFACTORY_H
#define FINAL_FANTASY_RECLAIM_YOUR_THRONE_OBJETFACTORY_H

#include "Objet.h"

class ObjetFactory {

public:
    virtual Objet* FactoryMethod() const = 0;
    static Objet* initObjet();
};

class EquipementFactory : public ObjetFactory {

public:
    Objet* FactoryMethod() const override;
};

class ConsommableFactory : public ObjetFactory {

public:
    Objet* FactoryMethod() const override;
};

#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_OBJETFACTORY_H
