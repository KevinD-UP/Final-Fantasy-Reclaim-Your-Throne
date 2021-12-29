//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/PersonnageFactory.h"
#include "../../../header/model/Objet/ConsommableFactory.h"
#include "../../../header/model/Objet/Equipement.h"

ConsommableType TYPE_PotionSoin = CT_POTIONSOIN;
ConsommableType TYPE_PotionBrulure = CT_POTIONBRULURE;
ConsommableType TYPE_PotionPoison = CT_POTIONPOISON;
ConsommableType TYPE_PotionSomnol = CT_POTIONSOMNOLENCE;


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
    Consommable* Potion = ConsommableFactory::initConsommable(TYPE_PotionSoin);
    auto* Epee = new Equipement("Epee", OT_Equipement, "Attaque:10 Defense:5", PT_Guerrier, false, 10, 5, 0);
    auto* Armure = new Equipement("Armure", OT_Equipement, "Defense:10 Sante:20", PT_Guerrier, false, 0, 10, 20);
    int sante = 50;
    int attaque = 10;
    int defense = 10;
    std::vector<Objet *> sac = {Potion,Epee,Armure};
    return new Guerrier(nom, sante, attaque, defense, PT_Guerrier ,sac);
}


Personnage *AmazoneFactory::FactoryMethod(const std::string &nom) const {
    Consommable* Potion = ConsommableFactory::initConsommable(TYPE_PotionSoin);
    auto* Lance = new Equipement("Lance",OT_Equipement,"Attaque:10 Defense:5",PT_Amazone,false,10,5,0);
    auto* Arc = new Equipement("Arc",OT_Equipement,"Attaque:10 Sante:10",PT_Amazone,false,10,0,10);
    int sante = 50;
    int attaque = 10;
    int defense = 10;
    std::vector<Objet *> sac = {Potion,Lance,Arc};
    return new Amazone(nom, sante, attaque, defense, PT_Amazone, sac);
}

Personnage *MoineFactory::FactoryMethod(const std::string &nom) const {
    Consommable* Potion = ConsommableFactory::initConsommable(TYPE_PotionSoin);
    auto* Toge = new Equipement("Toge",OT_Equipement,"Defense:10 Sante 30",PT_Moine,false,0,10,30);
    auto* Masse = new Equipement("Masse",OT_Equipement,"Attaque:5 Defense:5 Sante:15",PT_Moine,false,5,5,15);
    int sante = 50;
    int attaque = 10;
    int defense = 10;
    std::vector<Objet *> sac = {Potion,Toge,Masse};
    return new Moine(nom, sante, attaque, defense, PT_Moine, sac);
}

Personnage *SorcierFactory::FactoryMethod(const std::string &nom) const {
    Consommable* Potion = ConsommableFactory::initConsommable(TYPE_PotionSoin);
    auto* Baguette = new Equipement("Baguette",OT_Equipement,"Attaque:15 Sante:5",PT_Sorcier,false,15,0,5);
    auto* Robe = new Equipement("Robe",OT_Equipement,"Defense:10 Sante:15",PT_Sorcier,false,0,10,15);
    int sante = 50;
    int attaque = 10;
    int defense = 10;
    std::vector<Objet *> sac = {Potion,Baguette,Robe};
    return new Sorcier(nom, sante, attaque, defense, PT_Sorcier, sac);
}
