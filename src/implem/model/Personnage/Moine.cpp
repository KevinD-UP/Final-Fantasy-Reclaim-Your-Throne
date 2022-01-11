//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Moine.h"
#include "../../../header/model/Action/Action.h"
#include<string>
Moine::Moine(const std::string& nom, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet *> sac) :
    Personnage(nom, sante, attaque, defense, typePersonnage ,sac)
{}

void Moine::print() {
    std::cout << nom <<std::endl;
    std::cout << "Moine de Niveau:" << getLevel()
              << " " << getExp() << "Exp: "
              << getSante() << "/" << getSanteMax() << "HP "
              << getAttaque() << ":Attaque "
              << getDefense() << ":Defense" <<std::endl;
    checkStatut();
}



void Moine::action(std::string nom, Personnage * ennemie, const Joueur * player)  {
    //std::cout<< "La sorciere utilise " << nom << std::endl;
    int dommage = 0;
    std::string nomSort;
    Type type;
    if(nom == "0"){
        type = Offensive;
        dommage = attaque + 15 - ennemie->getDefense();
        srand((int) time(0));
        int v1 = rand() % 4;
        std::string v2 = std::to_string(v1);
        if(v2 == "0"){
            ennemie->pushStatut(Etourdit,1);
        }
        //inflige statut
        nomSort = "Frappe";
    }
    else if(nom == "1"){
        type = Defensive;
        dommage = 10 + ((getSanteMax()-getSante())*1/4);
        buff(Proteger,1);
        nomSort = "Soin";
    }
    else if(nom == "2"){
        type = Offensive;
        dommage =  getSante() * 1/4;
        nomSort = "Chatiment";
    }
    else{
        std::cout<< "ECHEC cette action n'existe pas " << nom <<std::endl;
        return;
    }
    //std::pair<Statut,int> effet = std::pair<Bruler,2>;
    auto *x = new Action(this, ennemie, nomSort, dommage, type, player);
    x->utilisation();
}

void Moine::actionJoueur(const Joueur * player, Personnage * cible) {
    std::string sort;
    std::cout << "0 - Frappe: Puissance:15. 25% de chance d'étourdir votre ennemie" << std::endl;
    std::cout << "1 - Soin: Puissance:5. Soigne le personnage de 25% des PV manquant et augmente votre defense pour 1 tour" << std::endl;
    std::cout << "2 - Chatiment: Puissance:x. Inflige 25% des PV courant" << std::endl;
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

Moine::~Moine()
noexcept {
std::cout << nom << " est mort et ne reviendra plus." << std::endl;
}