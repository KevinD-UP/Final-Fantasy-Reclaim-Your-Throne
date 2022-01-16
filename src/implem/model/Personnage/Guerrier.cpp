//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Guerrier.h"

Guerrier::Guerrier(const std::string& nom, int niveau, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet *> sac, const Map* carte) :
    Personnage(nom, niveau, sante, attaque, defense, typePersonnage, sac, carte)
{}

void Guerrier::print() {
    std::cout << nom <<std::endl;
    std::cout << "Guerrier de Niveau: " << getLevel()
              << " | Exp: " << getExp()
              << " | HP: " << getSante() << "/" << getSanteMax()
              << " | Attaque: " << getAttaque()
              << " | Defense: " << getDefense() <<std::endl;
    checkStatut();
}




void Guerrier::action(std::string nom, Personnage * ennemie, const Joueur * player)  {
    int dommage;
    std::string nomSort;
    Type type;
    if(nom == "0"){
        type = Offensive;
        dommage = attaque + 25 - ennemie->getDefense();
        nomSort = "Lacérage";
    }
    else if(nom == "1"){
        type = Offensive;
        buff(Berserk,3);
        dommage = attaque + 10  - ennemie->getDefense();
        nomSort = "Berserk";
    }
    else if(nom == "2"){
        type = Offensive;
        dommage = attaque + 5 + (getDefense() * 1/4) - ennemie->getDefense();
        nomSort = "Armure pointu";
    }
    else{
        std::cout<< "ECHEC cette action n'existe pas " << nom <<std::endl;
        //actionJoueur(,ennemie);
        return;
    }
    auto *x = new Action(this, ennemie, nomSort, dommage, type, player);
    x->utilisation();
}

void Guerrier::actionJoueur(const Joueur * player, Personnage * cible) {
    std::string sort;
    std::cout << "| 0 - Lacérage: Puissance:25 |" << std::endl;
    std::cout << "| 1 - Berserk: Puissance:10. Le personnage devient Berserk: augmente l'attaque selon la vie perdu |" << std::endl;
    std::cout << "| 2 - Armure pointu: Puissance:5. Inflige 25% de l'armure du personnage |" << std::endl;
    std::cout << "| 3 - Retour choix |" << std::endl;
    std::cin >> sort;
    if(sort == "3"){
        player->interactionEnCombat(cible);
    }
    else if(sort == "0" || sort == "1" || sort == "2") {
        action(sort, cible, player);
    }
    else{
        std::cout << "Cette attaque n'existe pas" << std::endl;
        player->interactionEnCombat(cible);
    }

}

void Guerrier::drop() {
    size_t i = 0;
    while(getSac().size() > i){
        getPieceCour()->pushObjet(sac[i]);
        sac[i]->enleverEffet(this);
        sac.erase(sac.begin() + i);
    }
}

Guerrier::~Guerrier() {
std::cout << nom << " est mort et ne reviendra plus." << std::endl;
}