//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Guerrier.h"
#include "../../../header/model/Action/Action.h"
#include<string>
Guerrier::Guerrier(std::string nom, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet *> sac) :
    Personnage(nom, sante, attaque, defense, typePersonnage, sac)
{}

void Guerrier::print() {
    std::cout << nom <<std::endl;
    std::cout << getSante() << "HP "
      << getAttaque() << ":Attaque "
      << getDefense() << ":Defense" <<std::endl;
    checkStatut();
}

void Guerrier::actionIa(Personnage * cible){
    int v1 = rand() % 2;
    std::string v2 = std::to_string(v1);
    action(v2,cible);
}


void Guerrier::action(std::string nom, Personnage * ennemie)  {
    //std::cout<< "La sorciere utilise " << nom << std::endl;
    int dommage = 0;
    std::string nomSort = "";
    Type type;
    if(nom == "0"){
        type = Offensive;
        dommage = attaque + 20 - ennemie->getDefense();
        //inflige statut
        nomSort = "Lacérage";
    }
    else if(nom == "1"){
        type = Offensive;
        buff(Berserk,2);
        dommage = attaque + 5  - ennemie->getDefense();
        nomSort = "Berserk";
    }
    else if(nom == "2"){
        type = Offensive;
        dommage = attaque + 5 + (getDefense() * 5/4) - ennemie->getDefense();
        nomSort = "Armure pointu";
    }
    else if(nom == "4"){
        type = Offensive;
        dommage = 0;
        nomSort = "Passer";
    }
    else{
        std::cout<< "ECHEC cette action n'existe pas " << nom <<std::endl;
        return;
    }
    //std::pair<Statut,int> effet = std::pair<Bruler,2>;
    Action *x = new Action(this, ennemie, nomSort, dommage, type);
    x->utilisation();
}

void Guerrier::actionJoueur(const Joueur * player, Personnage * cible) {
    std::string sort;
    std::cout << "0 - Lacérage: Puissance:20. " << std::endl;
    std::cout << "1 - Berserk: Puissance:5. Le personnage devient Berserk: augmente l'attaque selon la vie perdu" << std::endl;
    std::cout << "2 - Armure pointu: Puissance:5. Inflige 125% de l'armure du personnage" << std::endl;
    std::cout << "3 - Retour choix" << std::endl;
    std::cin >> sort;
    if(sort == "3"){
        player->interactionEnCombat(cible);
    }
    else if(sort == "0" || sort == "1" || sort == "2" || sort == "4") {
        action(sort, cible);
    }
    else{
        std::cout << "Cette attaque n'existe pas" << std::endl;
    }

}