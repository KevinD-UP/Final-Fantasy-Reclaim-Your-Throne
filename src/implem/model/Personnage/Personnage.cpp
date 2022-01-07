//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Personnage.h"

int Personnage::random = 0;

Personnage::Personnage(std::string nom_arg,
                       const int &sante_arg,
                       const int &attaque_arg,
                       const int &defense_arg,
                       const PersonnageType &personnageType_arg,
                       std::vector<Objet*> &sac_arg) :
                       nom(std::move(nom_arg)),
                       indice_de_sante_max(sante_arg),
                       attaque_max(attaque_arg),
                       defense_max(defense_arg),
                       typePersonnage(personnageType_arg),
                       sac(sac_arg)
{
    equipeAll();
}

Personnage::~Personnage() {
    std::cout << nom << " est mort et ne reviendra plus." << std::endl;
}

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
}

int Personnage::getAttaqueMax() const {
    return attaque_max;
}

int Personnage::getDefenseMax() const {
    return defense_max;
}

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

int Personnage::setMaxSante(int santeArg) {
    indice_de_sante_max = santeArg;
    return indice_de_sante_max;
}

int Personnage::setMaxAttaque(int attaqueArg) {
    attaque_max = attaqueArg;
    return attaque_max;
}

int Personnage::setMaxDefense(int defenseArg) {
    defense_max = defenseArg;
    return defense_max;
}

void Personnage::pushSac(Objet * x) {
    std::cout << x->getNom();
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

void Personnage::reset(){
    setSante(getSante() + getSanteMax()/6);
    setAttaque(getAttaqueMax());
    setDefense(getDefenseMax());
    statut.clear();
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
          //  std::cout << "Bruler ";
        }
        if(statut[i].first == Empoisonner){
            setSante(getSante() - (getSanteMax()/10));
            statut[i].second -=1;
           // std::cout << "Empoisonner ";
        }
        if(statut[i].first == Etourdit){
            statut[i].second -=1;
           // std::cout << "Etourdit ";
            etourdit = true;
        }
        if(statut[i].first == Affaiblie){
            statut[i].second -=1;
          //  std::cout << "Affaiblie ";
            setAttaque(attaque_max*4/5);
        }
        if(statut[i].first == Berserk){
            statut[i].second -=1;
          //  std::cout << "Berserk ";
            setAttaque(attaque_max + ((getSanteMax() - getSante()) /2));
        }
        if(statut[i].first == Proteger){
            statut[i].second -=1;
          //  std::cout << "Proteger ";
            setDefense(getDefenseMax()*7/4);
        }
        if(statut[i].first == Ecorcher){
            statut[i].second -=1;
           // std::cout << "Ecorcher ";
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

void Personnage::actionObjet(const Joueur * player, Personnage *cible) {
    size_t i = 0;
    std::cout << "Objet disponible:" << std::endl;
    std::string choix = "";
    while(i < sac.size()){
        std::cout << i << ":"<< sac[i]->getNom()
        << " " << sac[i]->getDescription() << std::endl;
        i++;
    }
    if (i == 0){
        std::cout << "Aucun Objet disponible" << std::endl;
        player->interactionEnCombat(cible);
        return;
    }
    std::cin >> choix;
    i = 0;
    while(i < sac.size()){
        if(std::to_string(i) == choix ){
            if(sac[i]->getObjetType() == OT_Consommable) {
                std::cout << "Choisir cible: 1:Joueur 2:Ennemie" << std::endl;
                std::cin >> choix;
                if(choix == "1"){
                    sac[i]->appliquerEffet(this);
                }
                else if(choix == "2"){
                    sac[i]->appliquerEffet(cible);
                }
                else{
                    std::cout << "Erreur ce choix n'est pas possible" << std::endl;
                    player->interactionEnCombat(cible);
                    return;
                }
                Objet* consomme = sac[i];
                sac.erase(sac.begin() + i);
                delete consomme;
                consomme = nullptr;
            }
            else{
                std::cout << "Erreur cette objet n'est pas un consommable" << std::endl;
                player->interactionEnCombat(cible);
                return;
            }
        }
        i++;
    }

}

void Personnage::equipeAll() {
    for (auto & objet: sac) {
        if(objet->getObjetType() == OT_Equipement){
            objet->appliquerEffet(this);
        }
    }
}

void Personnage::desequipe(){
    size_t i = 0;
    std::string choix;
    while(i < sac.size()){
        std::cout << i << ":"<< sac[i]->getNom()
                  << " " << sac[i]->getDescription() << std::endl;
        i++;
    }
    std::cin >> choix;
    i = 0;
    while(i < sac.size()) {
        if (std::to_string(i) == choix) {
            getPieceCour()->pushObjet(sac.at(i));
            sac[i]->enleverEffet(this);
            sac.erase(sac.begin() + i);
        }
        i++;
    }
}

Piece* Personnage::deplacement(int arrive) {
    this->pieceCourante->removePerso(this);
    this->pieceCourante->getVecPieceAdjacentes()[arrive]->pushPerso(this);
    return this->setPiece(pieceCourante->getVecPieceAdjacentes()[arrive]);
}

Piece* Personnage::deplacementIA(){
    try {
        std::random_device seeder;
        std::mt19937 engine(seeder());
        std::uniform_int_distribution<int> dist(0, 3);
        int deplacementAleatoire = dist(engine);
        //random ++;
        //srand((int) time(0) + random);
        //int deplacementAleatoire = rand() % 3;
        if(pieceCourante->getVecPieceAdjacentes()[deplacementAleatoire] != nullptr) {
            return this->deplacement(deplacementAleatoire);
        }
        else{
            return this->deplacementIA();
        }
    } catch(const std::exception& e) {
        return this->deplacementIA();
    }
}

void Personnage::buff(Statut effet, int tour) {
    if(effetPresent(Ecorcher) && effet == Proteger){
        enleverEffet(Ecorcher);
    }
    else if(effetPresent(Proteger) && effet == Proteger) {
        resetEffet(Proteger);
    }
    else if(effetPresent(Affaiblie) && effet == Berserk){
        enleverEffet(Affaiblie);
    }
    else if(effetPresent(Berserk) && effet == Berserk) {
        resetEffet(Berserk);
    }
    else{
        pushStatut(effet, tour);
    }
}

void Personnage::debuff(Statut effet, int tour, Personnage * ennemie) {
    if(ennemie->effetPresent(Proteger) && effet == Ecorcher){
        ennemie->enleverEffet(Proteger);
    }
    else if(ennemie->effetPresent(Ecorcher) && effet == Ecorcher) {
        ennemie->resetEffet(Ecorcher);
    }
    else if(ennemie->effetPresent(Berserk) && effet == Affaiblie){
        ennemie->enleverEffet(Berserk);
    }
    else if(ennemie->effetPresent(Affaiblie) && effet == Affaiblie) {
        ennemie->resetEffet(Affaiblie);
    }
    else{
        ennemie->pushStatut(effet, tour);
    }
}

std::ostream& operator<<(std::ostream& out, Personnage *PersonageArg){
    PersonageArg->print();
    out << "";
    return  out;
}