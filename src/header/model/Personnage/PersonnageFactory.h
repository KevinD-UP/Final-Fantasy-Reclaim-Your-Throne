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
    virtual Personnage* FactoryMethod(const std::string& nom) const = 0;
    static Personnage* initPersonnage(PersonnageType& personnagetype, const std::string& nom);
};

class GuerrierFactory : public PersonnageFactory {

    public:
        Personnage* FactoryMethod(const std::string& nom) const override;
};

class AmazoneFactory : public PersonnageFactory {

public:
    Personnage* FactoryMethod(const std::string& nom) const override;
};

class MoineFactory : public PersonnageFactory {

public:
    Personnage* FactoryMethod(const std::string& nom) const override;
};

class SorcierFactory : public PersonnageFactory {

public:
    Personnage* FactoryMethod(const std::string& nom) const override;
};



#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_PERSONNAGEFACTORY_H
