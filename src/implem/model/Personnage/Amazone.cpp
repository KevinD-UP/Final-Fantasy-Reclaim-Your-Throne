//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Amazone.h"
#include "../../../header/model/Action/Action.h"
#include<string>
Amazone::Amazone(std::string nom, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet*> sac) :
    Personnage(nom, sante, attaque, defense, typePersonnage, sac)
{}

void Amazone::print() {
    std::cout << "Je suis " << nom <<std::endl;
    std::cout << "J'ai " << getSante() << "HP "
      << getAttaque() << ":Attaque "
      << getDefense() << ":Defense" <<std::endl;
    checkStatut();

}

void Amazone::actionIa(Personnage * cible){
    int v1 = rand() % 2;
    std::string v2 = std::to_string(v1);
    action(v2,cible);
}


void Amazone::action(std::string nom, Personnage * ennemie)  {
    //std::cout<< "La sorciere utilise " << nom << std::endl;
    int dommage = 0;
    std::string nomSort = "";
    Type type;
    if(nom == "0"){
        type = Offensive;
        ennemie->pushStatut(Ecorcher,2);
        dommage = attaque + 10 - ennemie->getDefense();
        if(ennemie->effetPresent(Proteger)){
            ennemie->enleverEffet(Proteger);
        }
        else if(ennemie->effetPresent(Ecorcher)) {
            ennemie->resetEffet(Ecorcher);
        }
        else{
            ennemie->pushStatut(Ecorcher, 2);
        }
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
    //std::pair<Statut,int> effet = std::pair<Bruler,2>;
    Action *x = new Action(this, ennemie, nomSort, dommage, type);
    x->utilisation();
}

void Amazone::actionJoueur(Joueur * player,Personnage * cible) {
    std::string sort;
    std::cout << "0 - Attaque longue: Puissance 10 " << std::endl;
    std::cout << "1 - Execution: Puissance 5. Inflige 50% des PV manquant de la cible" << std::endl;
    std::cout << "2 - Double attaque: Puissance 5. Attaque 2 fois" << std::endl;
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