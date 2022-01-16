//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Moine.h"
#include "../../../header/model/Action/Action.h"

Moine::Moine(const std::string& nom, int niveau, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet *> sac, const Map* carte) :
    Personnage(nom, niveau,  sante, attaque, defense, typePersonnage, sac, carte)
{}

void Moine::print() {
    std::cout << nom <<std::endl;
    std::cout << "Moine de Niveau: " << getLevel()
              << " | Exp: " << getExp()
              << " | HP: " << getSante() << "/" << getSanteMax()
              << " | Attaque: " << getAttaque()
              << " | Defense: " << getDefense() <<std::endl;
    checkStatut();
}



void Moine::action(std::string nom, Personnage * ennemie, const Joueur * player)  {
    int dommage;
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
        dommage = ((getSanteMax()-getSante())*1/3);
        buff(Proteger,1);
        nomSort = "Soin";
    }
    else if(nom == "2"){
        type = Offensive;
        dommage =  getSante() * 1/3;
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
    std::cout << "| 0 - Frappe: Puissance:15. 25% de chance d'étourdir votre ennemie |" << std::endl;
    std::cout << "| 1 - Soin: Puissance:x. Soigne le personnage de 33% des PV manquant et augmente votre defense pour 1 tour |" << std::endl;
    std::cout << "| 2 - Chatiment: Puissance:x. Inflige 33% des PV courant |" << std::endl;
    std::cout << "| 3 - Retour choix |" << std::endl;
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

void Moine::drop() {
    size_t i = 0;
    while(getSac().size() > i){
        getPieceCour()->pushObjet(sac[i]);
        sac[i]->enleverEffet(this);
        sac.erase(sac.begin() + i);
    }
}

Moine::~Moine() {
    std::cout << nom << " est mort et ne reviendra plus." << std::endl;
}