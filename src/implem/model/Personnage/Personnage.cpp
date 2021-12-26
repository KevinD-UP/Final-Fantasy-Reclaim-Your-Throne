//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Personnage.h"
#include "../../../header/model/Action/Action.h"

Personnage::Personnage(const std::string &nom_arg,
                       const int &sante_arg,
                       const int &attaque_arg,
                       const int &defense_arg,
                       const PersonnageType &personnageType_arg,
                       std::vector<Objet*> &sac_arg) :
                       nom(nom_arg),
                       indice_de_sante_max(sante_arg),
                       attaque_max(attaque_arg),
                       defense_max(defense_arg),
                       typePersonnage(personnageType_arg),
                       sac(sac_arg)
{}

std::string Personnage::getNom() const {
    return nom;
}

int Personnage::getAttaque() const {
    return attaque;
}

int Personnage::getDefense() const {
    return defense;
}

int Personnage::getSante() const {
    return indice_de_sante_actuel;
}

int Personnage::getSanteMax() const {
    return indice_de_sante_max;
};
int Personnage::getAttaqueMax() const {
    return attaque_max;
};
int Personnage::getDefenseMax() const {
    return defense_max;
};

PersonnageType Personnage::getPersonnageType() const {
    return typePersonnage;
}

std::vector<std::pair<Statut, int>> Personnage::getStatut() {
    return statut;
}

std::vector<Objet *> Personnage::getSac() {
    return sac;
}

int Personnage::setSante(int santeArg) {
    indice_de_sante_actuel = santeArg;
    return indice_de_sante_actuel;
}

int Personnage::setAttaque(int attaqueArg) {
    attaque = attaqueArg;
    return attaque;
}

int Personnage::setDefense(int defenseArg) {
    defense = defenseArg;
    return defense;
}

void Personnage::pushSac(Objet * x) {
    sac.push_back(x);
}

bool Personnage::estMort() {
    return indice_de_sante_actuel <= 0;
}

Piece* Personnage::getPieceCour() {
    return pieceCourante;
}

Piece* Personnage::setPiece(Piece * nouvellePiece) {
    pieceCourante = nouvellePiece;
    return pieceCourante;
}

Statut Personnage::pushStatut(Statut newStatut, int temp) {
    statut.push_back(std::make_pair(newStatut,temp));
    return newStatut;
}

bool Personnage::effetPresent(Statut effet){
    size_t i = 0;
    while(i < statut.size()){
        if(statut[i].first == effet){
            return true;
        }
        i++;
    }
    return false;
}

void Personnage::resetEffet(Statut effet) {
    size_t i = 0;
    while(i < statut.size()){
        if(statut[i].first == effet){
            statut[i].second = 2;
        }
        i++;
    }
}

void Personnage::enleverEffet(Statut effet){
    size_t i = 0;
    while(i < statut.size()){
        if(statut[i].first == effet){
            if(statut[i].first == Affaiblie || statut[i].first == Berserk){
                setAttaque(attaque_max);
            }
            if(statut[i].first == Proteger || statut[i].first == Ecorcher){
                setDefense(defense_max);
            }
            statut.erase(statut.begin() + i);
        }
        i++;
    }
}

void Personnage::checkStatut() {
    size_t i = 0;
    while(i < statut.size()){
        if(statut[i].first == Bruler){
            std::cout << "Bruler ";
        }
        if(statut[i].first == Empoisonner){
            std::cout << "Empoisonner ";
        }
        if(statut[i].first == Etourdit){
            std::cout << "Etourdit ";
        }
        if(statut[i].first == Affaiblie){
            std::cout << "Affaiblie ";
        }
        if(statut[i].first == Berserk){
            std::cout << "Berserk ";
        }
        if(statut[i].first == Ecorcher){
            std::cout << "Ecorcher ";
        }
        i++;
    }
    std::cout << std::endl;
}

bool Personnage::updateStatut(){
    size_t i = 0;
    bool etourdit = false;
    while(i < statut.size()){
        if(statut[i].first == Bruler){
            setSante(getSante() - (getSanteMax()/10));
            statut[i].second -=1;
            std::cout << "Bruler ";
        }
        if(statut[i].first == Empoisonner){
            setSante(getSante() - (getSanteMax()/10));
            statut[i].second -=1;
            std::cout << "Empoisonner ";
        }
        if(statut[i].first == Etourdit){
            statut[i].second -=1;
            std::cout << "Etourdit ";
            etourdit = true;
        }
        if(statut[i].first == Affaiblie){
            statut[i].second -=1;
            std::cout << "Affaiblie ";
            setAttaque(attaque_max*4/5);
        }
        if(statut[i].first == Berserk){
            statut[i].second -=1;
            std::cout << "Berserk ";
            setAttaque(attaque_max + ((getSanteMax() - getSante()) /2));
        }
        if(statut[i].first == Proteger){
            statut[i].second -=1;
            std::cout << "Proteger ";
            setDefense(getDefenseMax()*7/4);
        }
        if(statut[i].first == Ecorcher){
            statut[i].second -=1;
            std::cout << "Ecorcher ";
            setDefense(getDefenseMax()*1/2);
        }
        if(statut[i].second == 0){
            if(statut[i].first == Affaiblie || statut[i].first == Berserk){
                setAttaque(attaque_max);
            }
            if(statut[i].first == Proteger || statut[i].first == Ecorcher){
                setDefense(defense_max);
            }
            statut.erase(statut.begin() + i);
        }
        i++;
    }

    std::cout << std::endl;
    return etourdit;
}
/*void Personnage::pushStatut(std::pair<Personnage::Statut, int> x) {
    statut.push_back(x);
}*/

void Personnage::actionObjet(const Joueur * player,Personnage *cible) {
    int i = 0;
    std::string choix = "";
    for (auto & objet: sac) {
        std::cout << i << ":";
        objet->getNom();
        std::cout << " ";
        objet->getDescription();
        std::cout << std::endl;
        i++;
    }
    std::cin >> choix;
    i = 0;
    for (auto & objet: sac) {
        if(std::to_string(i) == choix ){
            if(objet->getObjetType() == OT_Consommable) {
                objet->appliquerEffet(cible);
            }
            else{
                std::cout << "Erreur cette objet n'est pas un consummable" << std::endl;
               // player->interagir(cible);
            }
        }
        i++;
    }

}

std::ostream& operator<<(std::ostream& out, Personnage *PersonageArg){
    PersonageArg->print();
    out << "";
    return  out;
}