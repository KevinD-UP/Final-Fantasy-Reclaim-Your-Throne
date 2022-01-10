//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Amazone.h"
#include "../../../header/model/Action/Action.h"
#include<string>
Amazone::Amazone(const std::string& nom, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet*> sac) :
    Personnage(nom, sante, attaque, defense, typePersonnage, sac)
{}

void Amazone::print() {
    std::cout << nom <<std::endl;
    std::cout << getSante() << "HP "
      << getAttaque() << ":Attaque "
      << getDefense() << ":Defense" <<std::endl;
    checkStatut();

}



void Amazone::action(std::string nom, Personnage * ennemie)  {
    //std::cout<< "La sorciere utilise " << nom << std::endl;
    int dommage;
    std::string nomSort;
    Type type;
    if(nom == "0"){
        type = Offensive;
        ennemie->pushStatut(Ecorcher,2);
        dommage = attaque + 10 - ennemie->getDefense();
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
    auto *x = new Action(this, ennemie, nomSort, dommage, type);
    x->utilisation();
}

void Amazone::actionJoueur(const Joueur * player,Personnage * cible) {
    std::string sort;
    std::cout << "0 - Ecorcher: Puissance:10. Reduit l'armure de l'ennemie" << std::endl;
    std::cout << "1 - Execution: Puissance:5. Inflige 50% des PV manquant de la cible" << std::endl;
    std::cout << "2 - Double attaque: Puissance:5. Attaque 2 fois" << std::endl;
    std::cout << "3 - Retour choix" << std::endl;
    std::cin >> sort;
    if(sort == "3"){
        player->interactionEnCombat(cible);
    }
    else if(sort == "0" || sort == "1" || sort == "2" ) {
        action(sort, cible);
    }
    else{
        std::cout << "Cette attaque n'existe pas" << std::endl;
    }

}