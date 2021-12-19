//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Personnage.h"
#include "../../../header/model/Action/Action.h"

Personnage::Personnage(std::string nom_arg,
                       const int &sante_arg,
                       const int &attaque_arg,
                       const int &defense_arg,
                       std::vector<Objet*> sac_arg) : nom(std::move(nom_arg)), indice_de_sante_max(sante_arg), attaque(attaque_arg), defense(defense_arg), sac(std::move(sac_arg))
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

std::pair<Statut, int> Personnage::getStatut() {
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
    return indice_de_sante_actuel == 0;
}

Piece* Personnage::getPieceCour() {
    return pieceCourante;
}

Piece* Personnage::setPiece(Piece * nouvellePiece) {
    pieceCourante = nouvellePiece;
    return pieceCourante;
}

void Personnage::action(std::string, Personnage *) {}
/*void Personnage::pushStatut(std::pair<Personnage::Statut, int> x) {
    statut.push_back(x);
}*/

std::ostream& operator<<(std::ostream& out, Personnage *PersonageArg){
    PersonageArg->print();
    out << "TESTING";
    return  out;
}