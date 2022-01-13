//
// Created by anthony on 13/01/2022.
//

#include "../../../header/model/Personnage/Dragon.h"

Dragon::Dragon(const std::string& nom, int niveau, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet *> sac) :
        Personnage(nom, niveau, sante, attaque, defense, typePersonnage, sac)
{}

void Dragon::action(std::string nom, Personnage *ennemie, const Joueur * player) {
    int dommage = attaque + 40 - ennemie->getDefense();
    debuff(Bruler,4,ennemie);
    std::string nomSort;
    Type type = Offensive;
    nomSort = "Souffle de Feu";
    auto *x = new Action(this, ennemie, nomSort, dommage, type, player);
    x->utilisation();
}

void Dragon::print() {
    std::cout << nom <<std::endl;
    std::cout << getNom() << "de Niveau:" << getLevel()
              << " " << getExp() << "Exp "
              << getSante() << "/" << getSanteMax()<< "HP "
              << getAttaque() << ":Attaque "
              << getDefense() << ":Defense" <<std::endl;
    checkStatut();
}

void Dragon::actionJoueur(const Joueur *, Personnage *) {}

void Dragon::drop() {
    std::random_device seeder;
    std::mt19937 engine(seeder());
    std::uniform_int_distribution<int> dist(0, 3);
    int drop_item = dist(engine);
    if (drop_item == 0){
        auto* Epee_du_Dragon = new Equipement("Epee_du_Dragon", OT_Equipement, "Attaque:40 Defense:25 Sante:50", PT_Guerrier, false, 40, 25, 50);
        pushSac(Epee_du_Dragon);
    }
    if (drop_item == 1){
        auto* Toge_du_Dragon = new Equipement("Toge_du_Dragon",OT_Equipement,"Attaque:20 Defense:30 Sante 80",PT_Moine,false,20,30,80);
        pushSac(Toge_du_Dragon);
    }
    if (drop_item == 2){
        auto* Griffe_du_Dragon = new Equipement("Griffe_du_Dragon",OT_Equipement,"Attaque:35 Deffense:35 Sante:40",PT_Amazone,false,35,35,40);
        pushSac(Griffe_du_Dragon);
    }
    if (drop_item == 3){
        auto* Oeil_du_Dragon = new Equipement("Oeil_du_Dragon",OT_Equipement,"Attaque:30 Defense:30 Sante:60",PT_Sorcier,false,30,30,60);
        pushSac(Oeil_du_Dragon);
    }
    getPieceCour()->pushObjet(sac[0]);
}

Dragon::~Dragon()
noexcept {}