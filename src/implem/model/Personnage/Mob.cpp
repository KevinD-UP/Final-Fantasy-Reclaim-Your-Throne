//
// Created by kevin on 11/01/2022.
//

#include "../../../header/model/Personnage/Mob.h"

Mob::Mob(const std::string& nom, int niveau, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet *> sac, const Map* carte) :
        Personnage(nom, niveau, sante, attaque, defense, typePersonnage, sac, carte)
{}

void Mob::action(std::string nom, Personnage *ennemie, const Joueur * player) {
    int dommage = attaque + 5 - ennemie->getDefense();
    std::string nomSort;
    Type type = Offensive;
    nomSort = "Griffe";
    auto *x = new Action(this, ennemie, nomSort, dommage, type, player);
    x->utilisation();
}

void Mob::print() {
    std::cout << nom <<std::endl;
    std::cout << getNom() << "de Niveau:" << getLevel()
              << " " << getExp() << "Exp "
              << getSante() << "/" << getSanteMax()<< "HP "
              << getAttaque() << ":Attaque "
              << getDefense() << ":Defense" <<std::endl;
    checkStatut();
}

void Mob::actionJoueur(const Joueur *, Personnage *) {}

void Mob::drop() {
    std::random_device seeder;
    std::mt19937 engine(seeder());
    std::uniform_int_distribution<int> dist(0, 3);
    int drop_item = dist(engine);
    if (drop_item == 0){
        auto* Epee_Gobelin = new Equipement("Epee_Gobelin", OT_Equipement, "Attaque:15 Defense:10", PT_Guerrier, false, 15, 10, 0);
        pushSac(Epee_Gobelin);
    }
    if (drop_item == 1){
        auto* Lance_Gobelin = new Equipement("Lance_Gobelin",OT_Equipement,"Attaque:10 Defense:5 Sante:15",PT_Amazone,false,10,5,15);
        pushSac(Lance_Gobelin);
    }
    if (drop_item == 2){
        auto* Masse_Gobelin = new Equipement("Masse_Gobelin",OT_Equipement,"Attaque:5 Defense:10 Sante:15",PT_Moine,false,5,5,15);
        pushSac(Masse_Gobelin);
    }
    if (drop_item == 3){
        auto* Baguette_Gobelin = new Equipement("Baguette_Gobelin",OT_Equipement,"Attaque:15 Defense:5 Sante:5",PT_Sorcier,false,15,5,5);
        pushSac(Baguette_Gobelin);
    }
    getPieceCour()->pushObjet(sac[0]);
}

Mob::~Mob() {}




