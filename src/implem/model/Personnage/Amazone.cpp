//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Amazone.h"
#include "../../../header/model/Action/Action.h"
#include<string>
Amazone::Amazone(const std::string& nom, int niveau, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet*> sac, const Map* carte) :
    Personnage(nom, niveau, sante, attaque, defense, typePersonnage, sac, carte)
{}

void Amazone::print() {
    std::cout << nom <<std::endl;
    std::cout << "Amazone de Niveau:" << getLevel()
              << " " << getExp() << "Exp: "
              << getSante() << "/" << getSanteMax() << "HP "
              << getAttaque() << ":Attaque "
              << getDefense() << ":Defense" <<std::endl;
    checkStatut();

}



void Amazone::action(std::string nom, Personnage * ennemie, const Joueur * player)  {
    //std::cout<< "La sorciere utilise " << nom << std::endl;
    int dommage;
    std::string nomSort;
    Type type;
    if(nom == "0"){
        type = Offensive;
        ennemie->pushStatut(Ecorcher,2);
        dommage = attaque + 20 - ennemie->getDefense();
        debuff(Ecorcher,2,ennemie);
        //inflige statut
        nomSort = "Ecorcher";
    }
    else if(nom == "1"){
        type = Offensive;
        dommage = attaque + 5 + ((ennemie->getSanteMax() - ennemie->getSante()) /2) - ennemie->getDefense();
        nomSort = "Execution";
    }
    else if(nom == "2"){
        type = Offensive;
        dommage = (attaque + 5 - ennemie->getDefense()) *2;
        nomSort = "Double attaque";
    }
    else{
        std::cout<< "ECHEC cette action n'existe pas " << nom <<std::endl;
        return;
    }
    auto *x = new Action(this, ennemie, nomSort, dommage, type, player);
    x->utilisation();
}

void Amazone::actionJoueur(const Joueur * player,Personnage * cible) {
    std::string sort;
    std::cout << "0 - Ecorcher: Puissance:20. Reduit l'armure de l'ennemie" << std::endl;
    std::cout << "1 - Execution: Puissance:10. Inflige 50% des PV manquant de la cible" << std::endl;
    std::cout << "2 - Double attaque: Puissance:5. Attaque 2 fois" << std::endl;
    std::cout << "3 - Retour choix" << std::endl;
    std::cin >> sort;
    if(sort == "3"){
        player->interactionEnCombat(cible);
    }
    else if(sort == "0" || sort == "1" || sort == "2" ) {
        action(sort, cible, player);
    }
    else{
        std::cout << "Cette attaque n'existe pas" << std::endl;
        player->interactionEnCombat(cible);
    }
}

void Amazone::drop() {
    size_t i = 0;
    while(getSac().size() > i){
        getPieceCour()->pushObjet(sac[i]);
        sac[0]->enleverEffet(this);
        sac.erase(sac.begin() + i);
    }
}

Amazone::~Amazone()
noexcept {
    std::cout << nom << " est mort et ne reviendra plus." << std::endl;
}