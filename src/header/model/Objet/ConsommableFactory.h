//
// Created by kevin on 19/12/2021.
//

#ifndef FINAL_FANTASY_RECLAIM_YOUR_THRONE_CONSOMMABLEFACTORY_H
#define FINAL_FANTASY_RECLAIM_YOUR_THRONE_CONSOMMABLEFACTORY_H

#include "Consommable.h"

class ConsommableFactory {
public:
    virtual Consommable* FactoryMethod() const = 0;
    static Consommable* initObjet();
};

class PotionSoinFactory : public ConsommableFactory {

public:
    Consommable* FactoryMethod() const override;
};

class PotionBrulureFactory : public ConsommableFactory {

public:
    Consommable* FactoryMethod() const override;
};

class PotionPoisonFactory : public ConsommableFactory {

public:
    Consommable* FactoryMethod() const override;
};

class PotionSomnolenceFactory : public ConsommableFactory {

public:
    Consommable* FactoryMethod() const override;
};
#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_CONSOMMABLEFACTORY_H
