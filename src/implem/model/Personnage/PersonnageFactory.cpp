//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/PersonnageFactory.h"

Personnage* PersonnageFactory::initPersonnage(const std::string& personnagetype, const std::string& nom){
    if(personnagetype == "Amazone") {
        int sante = 50;
        int attaque = 10;
        int defense = 10;
        std::vector<Objet *> sac;
        return new Amazone(nom, sante, attaque, defense, sac);
    } else if (personnagetype == "Guerrier"){
        int sante = 50;
        int attaque = 10;
        int defense = 10;
        std::vector<Objet *> sac;
        return new Guerrier(nom, sante, attaque, defense, sac);
    } else if (personnagetype == "Moine"){
        int sante = 50;
        int attaque = 10;
        int defense = 10;
        std::vector<Objet *> sac;
        return new Moine(nom, sante, attaque, defense, sac);
    } else if (personnagetype == "Sorcier"){
        int sante = 50;
        int attaque = 10;
        int defense = 10;
        std::vector<Objet *> sac;
        return new Sorcier(nom, sante, attaque, defense, sac);
    } else {
        throw std::invalid_argument( "Aucun type de personnage ne correspond, échec de la création de personnage" );
    }
}
