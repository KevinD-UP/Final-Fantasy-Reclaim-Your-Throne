//
// Created by anthony on 12/01/2022.
//

#include "../../../header/model/Personnage/Loup.h"

Loup::Loup(const std::string& nom, int niveau, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet *> sac,const Map* carte) :
        Personnage(nom, niveau, sante, attaque, defense, typePersonnage, sac, carte)
{}

void Loup::action(std::string nom, Personnage *ennemie, const Joueur * player) {
    int dommage = attaque + 15 - ennemie->getDefense();
    debuff(Empoisonner,2,ennemie);
    std::string nomSort;
    Type type = Offensive;
    nomSort = "Croc";
    auto *x = new Action(this, ennemie, nomSort, dommage, type, player);
    x->utilisation();
}

void Loup::print() {
    std::cout << nom << std::endl;
    std::cout << "Loup de Niveau: " << getLevel()
              << " | Exp: " << getExp()
              << " | HP: " << getSante() << "/" << getSanteMax()
              << " | Attaque: " << getAttaque()
              << " | Defense: " << getDefense() <<std::endl;
    checkStatut();
}

void Loup::actionJoueur(const Joueur *, Personnage *) {}

void Loup::drop() {
    std::random_device seeder;
    std::mt19937 engine(seeder());
    std::uniform_int_distribution<int> dist(0, 3);
    int drop_item = dist(engine);
    if (drop_item == 0){
        auto* Armure_du_Loup = new Equipement("Armure_du_Loup", OT_Equipement, "Attaque: 15 Defense: 10 Sante: 30", PT_Guerrier, false, 15, 10, 30, 2);
        pushSac(Armure_du_Loup);
    }
    if (drop_item == 1){
        auto* Toge_du_Loup = new Equipement("Toge_du_Loup",OT_Equipement,"Attaque: 10 Defense: 10 Sante: 50",PT_Moine,false,10, 10, 50, 2);
        pushSac(Toge_du_Loup);
    }
    if (drop_item == 2){
        auto* Arc_du_Loup = new Equipement("Arc_du_Loup",OT_Equipement,"Attaque: 20 Defense: 5 Sante: 30",PT_Amazone,false,20, 5, 30, 2);
        pushSac(Arc_du_Loup);
    }
    if (drop_item == 3){
        auto* Robe_du_Loup = new Equipement("Robe_du_Loup",OT_Equipement,"Attaque: 15 Defense: 10 Sante: 20",PT_Sorcier,false,5, 10, 15, 2);
        pushSac(Robe_du_Loup);
    }
    getPieceCour()->pushObjet(sac[0]);
}

Loup::~Loup() {}