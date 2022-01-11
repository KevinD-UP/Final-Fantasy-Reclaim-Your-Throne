//
// Created by kevin on 11/01/2022.
//

#include "../../../header/model/Personnage/Mob.h"

Mob::Mob(const std::string& nom, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet *> sac) :
        Personnage(nom, sante, attaque, defense, typePersonnage, sac)
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

Mob::~Mob()

noexcept {}