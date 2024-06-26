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
#include "Gobelin.h"
#include "Loup.h"
#include "Dragon.h"
class PersonnageFactory {

public:
    virtual Personnage* FactoryMethod(const std::string& nom, const Map* carte) const = 0;
    static Personnage* initPersonnage(PersonnageType& personnagetype, const std::string& nom, const Map* carte);
};

class GuerrierFactory : public PersonnageFactory {

    public:
        Personnage* FactoryMethod(const std::string& nom, const Map* carte) const override;
};

class AmazoneFactory : public PersonnageFactory {

    public:
        Personnage* FactoryMethod(const std::string& nom, const Map* carte) const override;
};

class MoineFactory : public PersonnageFactory {

    public:
        Personnage* FactoryMethod(const std::string& nom, const Map* carte) const override;
};

class SorcierFactory : public PersonnageFactory {

    public:
        Personnage* FactoryMethod(const std::string& nom, const Map* carte) const override;
};

class GobelinFactory : public PersonnageFactory {

public:
    Personnage* FactoryMethod(const std::string& nom, const Map* carte) const override;
};

class LoupFactory: public PersonnageFactory {

public:
    Personnage* FactoryMethod(const std::string& nom, const Map* carte) const override;
};

class DragonFactory: public PersonnageFactory {

public:
    Personnage* FactoryMethod(const std::string& nom, const Map* carte) const override;
};


#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_PERSONNAGEFACTORY_H
