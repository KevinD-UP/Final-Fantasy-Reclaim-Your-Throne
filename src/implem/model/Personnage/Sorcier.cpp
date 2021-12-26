//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Sorcier.h"
#include "../../../header/model/Action/Action.h"
#include<string>
Sorcier::Sorcier(std::string nom, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet *> sac) :
    Personnage(nom, sante, attaque, defense, typePersonnage, sac)
{}

void Sorcier::print() {
    std::cout << "Je suis " << nom <<std::endl;
    std::cout << "J'ai " << getSante() << "HP "
    << getAttaque() << ":Attaque "
    << getDefense() << ":Defense" <<std::endl;
    checkStatut();

}

void Sorcier::actionIa(Personnage * cible){
    int v1 = rand() % 2;
    std::string v2 = std::to_string(v1);
    action(v2,cible);
}


void Sorcier::action(std::string nom, Personnage * ennemie)  {
    //std::cout<< "La sorciere utilise " << nom << std::endl;
    int dommage = 0;
    std::string nomSort = "";
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
        dommage = attaque + 5;
        nomSort = "Eclair";
    }
    else if(nom == "2"){
        type = Offensive;
        dommage = attaque + 10 - ennemie->getDefense();
        setSante(getSante() + dommage/2);
        if(ennemie->effetPresent(Berserk)){
            ennemie->enleverEffet(Berserk);
        }
        else if(ennemie->effetPresent(Affaiblie)) {
            ennemie->resetEffet(Affaiblie);
        }
        else{
            ennemie->pushStatut(Affaiblie, 2);
        }
        nomSort = "Drain";
    }
    else{
        std::cout<< "ECHEC cette action n'existe pas " << nom <<std::endl;
        return;
    }
    std::cout<< "TEST " << nom <<std::endl;
    //std::pair<Statut,int> effet = std::pair<Bruler,2>;
    Action *x = new Action(this, ennemie, nomSort, dommage, type);
    x->utilisation();
}

void Sorcier::actionJoueur(const Joueur * player,Personnage * cible) {
    std::string sort;
    std::cout << "0 - Boule de feu: Puissance 15 " << std::endl;
    std::cout << "1 - Eclair: Puissance 5. Ignore l'armure ennemie" << std::endl;
    std::cout << "2 - Drain: Puissance 5. Regenere 25% des dommages infligés et applique Affaibli" << std::endl;
    std::cout << "3 - Retour choix" << std::endl;
    std::cin >> sort;
    if(sort == "3"){
        player->interagir(cible);
    }
    else if(sort == "0" || sort == "1" || sort == "2" ) {
        action(sort, cible);
    }
    else{
        std::cout << "Cette attaque n'existe pas" << std::endl;
    }

}