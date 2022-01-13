//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Sorcier.h"
#include "../../../header/model/Action/Action.h"
#include<string>
#include <utility>
Sorcier::Sorcier(std::string nom, int niveau, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet *> sac, const Map* carte) :
    Personnage(std::move(nom), niveau, sante, attaque, defense, typePersonnage, sac, carte)
{}

void Sorcier::print() {
    std::cout << nom <<std::endl;
    std::cout << "Sorcier de Niveau: " << getLevel()
              << " " << getExp() << "Exp: "
              << getSante() << "/" << getSanteMax() << "HP "
              << getAttaque() << ":Attaque "
              << getDefense() << ":Defense" <<std::endl;
    checkStatut();

}


void Sorcier::action(std::string nom, Personnage * ennemie, const Joueur * player)  {
    //std::cout<< "La sorciere utilise " << nom << std::endl;
    int dommage = 0;
    std::string nomSort;
    Type type;
    if(nom == "0"){
        type = Offensive;
        dommage = attaque + 15 - ennemie->getDefense();
        //inflige statut
        ennemie->pushStatut(Bruler,2);
        nomSort = "Boule de Feu";
    }
    else if(nom == "1"){
        type = Offensive;
        dommage = attaque*2/3  - ennemie->getDefense()/2 ;
        nomSort = "Eclair";
    }
    else if(nom == "2"){
        type = Offensive;
        dommage = attaque + 10 - ennemie->getDefense();
        setSante(getSante() + dommage/2);
        debuff(Affaiblie,2,ennemie);
        nomSort = "Drain";
    }
    else{
        std::cout<< "ECHEC cette action n'existe pas " << nom <<std::endl;
        return;
    }
    //std::pair<Statut,int> effet = std::pair<Bruler,2>;
    auto *x = new Action(this, ennemie, nomSort, dommage, type, player);
    x->utilisation();
}

void Sorcier::actionJoueur(const Joueur * player,Personnage * cible) {
    std::string sort;
    std::cout << "0 - Boule de feu: Puissance:15. " << std::endl;
    std::cout << "1 - Eclair: Puissance: 2/3 de l'attaque. Ignore 50% de l'armure ennemie" << std::endl;
    std::cout << "2 - Drain: Puissance:5. Regenere 25% des dommages infligés et applique Affaiblie" << std::endl;
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

void Sorcier::drop() {
    size_t i = 0;
    while(getSac().size() > i){
        getPieceCour()->pushObjet(sac[i]);
        sac[i]->enleverEffet(this);
        sac.erase(sac.begin() + i);
    }
}

Sorcier::~Sorcier() {
std::cout << nom << " est mort et ne reviendra plus." << std::endl;
}