//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/PersonnageFactory.h"
#include "../../../header/model/Objet/ConsommableFactory.h"


Personnage* PersonnageFactory::initPersonnage(PersonnageType & personnagetype, const std::string& nom, const Map* carte){
    if(personnagetype == PT_Amazone) {
        return (new AmazoneFactory)->FactoryMethod(nom,carte);
    } else if (personnagetype == PT_Guerrier){
        return (new GuerrierFactory)->FactoryMethod(nom,carte);
    } else if (personnagetype == PT_Moine){
        return (new MoineFactory)->FactoryMethod(nom,carte);
    } else if (personnagetype == PT_Sorcier){
        return (new SorcierFactory)->FactoryMethod(nom,carte);
    } else if (personnagetype == PT_Gobelin){
        return (new GobelinFactory)->FactoryMethod(nom,carte);
    } else if (personnagetype == PT_Loup){
        return (new LoupFactory)->FactoryMethod(nom,carte);
    } else if (personnagetype == PT_Dragon){
        return (new DragonFactory)->FactoryMethod(nom,carte);
    } else {
        throw std::invalid_argument( "Aucun type de personnage ne correspond, échec de la création de personnage");
    }
}

Personnage *GuerrierFactory::FactoryMethod(const std::string &nom,const Map* carte) const {
    auto* Epee = new Equipement("Epee", OT_Equipement, "Attaque: 10 Defense: 7", PT_Guerrier, false, 10, 7, 0, 0);
    auto* Armure = new Equipement("Armure", OT_Equipement, "Defense: 10 Sante: 20", PT_Guerrier, false, 0, 10, 20, 0);
    int sante = 95;
    int attaque = 20;
    int defense = 20;
    std::vector<Objet *> sac = {Epee,Armure};
    return new Guerrier(nom, 1, sante, attaque, defense, PT_Guerrier, sac, carte);
}


Personnage *AmazoneFactory::FactoryMethod(const std::string &nom, const Map* carte) const {
    auto* Lance = new Equipement("Lance",OT_Equipement,"Attaque: 10 Defense: 5 Sante: 5",PT_Amazone,false,10, 5, 5, 0);
    auto* Arc = new Equipement("Arc",OT_Equipement,"Attaque: 10 Sante: 20",PT_Amazone,false,10, 0, 20, 0);
    int sante = 95;
    int attaque = 25;
    int defense = 15;
    std::vector<Objet *> sac = {Lance,Arc};
    return new Amazone(nom, 1, sante, attaque, defense, PT_Amazone, sac, carte);
}

Personnage *MoineFactory::FactoryMethod(const std::string &nom, const Map* carte) const {
    auto* Toge = new Equipement("Toge",OT_Equipement,"Defense: 10 Sante: 30",PT_Moine,false,0, 10, 30, 0);
    auto* Masse = new Equipement("Masse",OT_Equipement,"Attaque: 5 Defense: 5 Sante: 15",PT_Moine,false,5, 5, 15, 0);
    int sante = 95;
    int attaque = 15;
    int defense = 20;
    std::vector<Objet *> sac = {Toge,Masse};
    return new Moine(nom, 1, sante, attaque, defense, PT_Moine, sac, carte);
}

Personnage *SorcierFactory::FactoryMethod(const std::string &nom, const Map* carte) const {
    auto* Baguette = new Equipement("Baguette",OT_Equipement,"Attaque: 15 Sante: 5",PT_Sorcier,false,15, 0, 5, 0);
    auto* Robe = new Equipement("Robe",OT_Equipement,"Attaque: 5 Defense: 10 Sante: 15",PT_Sorcier,false,5, 10, 15, 0);
    int sante = 90;
    int attaque = 30;
    int defense = 10;
    std::vector<Objet *> sac = {Baguette,Robe};
    return new Sorcier(nom, 1, sante, attaque, defense, PT_Sorcier, sac, carte);
}

Personnage *GobelinFactory::FactoryMethod(const std::string &nom, const Map* carte) const {
    int sante = 100;
    int attaque = 40;
    int defense = 10;
    std::vector<Objet *> sac;
    return new Gobelin(nom, 1, sante, attaque, defense, PT_Gobelin, sac, carte);
}

Personnage *LoupFactory::FactoryMethod(const std::string &nom, const Map* carte) const {
    int sante = 130;
    int attaque = 55;
    int defense = 25;
    std::vector<Objet *> sac;
    return new Loup(nom, 2, sante, attaque, defense, PT_Loup, sac, carte);
}

Personnage *DragonFactory::FactoryMethod(const std::string &nom, const Map* carte) const {
    int sante = 180;
    int attaque = 75;
    int defense = 60;
    std::vector<Objet *> sac;
    return new Dragon(nom, 5, sante, attaque, defense, PT_Dragon, sac, carte);
}