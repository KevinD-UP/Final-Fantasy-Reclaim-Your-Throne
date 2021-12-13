//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/PersonnageFactory.h"

Personnage* PersonnageFactory::initPersonnage(PersonnageType & personnagetype, const std::string& nom){
    if(personnagetype == PT_Amazone) {
        return (new AmazoneFactory)->FactoryMethod(nom);
    } else if (personnagetype == PT_Guerrier){
        return (new GuerrierFactory)->FactoryMethod(nom);
    } else if (personnagetype == PT_Moine){
        return (new MoineFactory)->FactoryMethod(nom);
    } else if (personnagetype == PT_Sorcier){
        return (new SorcierFactory)->FactoryMethod(nom);
    } else {
        throw std::invalid_argument( "Aucun type de personnage ne correspond, échec de la création de personnage");
    }
}

Personnage *GuerrierFactory::FactoryMethod(const std::string &nom) const {
    int sante = 50;
    int attaque = 10;
    int defense = 10;
    std::vector<Objet *> sac;
    return new Guerrier(nom, sante, attaque, defense, sac);
}


Personnage *AmazoneFactory::FactoryMethod(const std::string &nom) const {
    int sante = 50;
    int attaque = 10;
    int defense = 10;
    std::vector<Objet *> sac;
    return new Amazone(nom, sante, attaque, defense, sac);
}

Personnage *MoineFactory::FactoryMethod(const std::string &nom) const {
    int sante = 50;
    int attaque = 10;
    int defense = 10;
    std::vector<Objet *> sac;
    return new Moine(nom, sante, attaque, defense, sac);
}

Personnage *SorcierFactory::FactoryMethod(const std::string &nom) const {
    int sante = 50;
    int attaque = 10;
    int defense = 10;
    std::vector<Objet *> sac;
    return new Sorcier(nom, sante, attaque, defense, sac);
}
