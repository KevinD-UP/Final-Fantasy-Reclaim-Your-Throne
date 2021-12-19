//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Sorcier.h"
#include "../../../header/model/Action/Action.h"

Sorcier::Sorcier(std::string nom, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet *> sac) :
    Personnage(nom, sante, attaque, defense, typePersonnage, sac)
{}

void Sorcier::print() {
    std::cout << "Je suis une Sorcier" << std::endl;
}

void Sorcier::action(std::string nom, Personnage * ennemie){
    std::cout<< "La sorciere utilise " << nom << std::endl;
    int dommage = 0;
    Type type;
    if(nom == "boule_de_feu"){
            type = Offensive;
            dommage = attaque + 10 - ennemie->getDefense();
    }
    else{
        std::cout<< "ECHEC cette action n'existe pas" << nom <<std::endl;
    }
    //std::pair<Statut,int> effet = std::pair<Bruler,2>;
    Action *x = new Action(this, ennemie, nom, dommage, type);
    x->utilisation();
}