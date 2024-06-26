//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Personnage/Personnage.h"


Personnage::Personnage(std::string nom_arg,
                       const int &niveau,
                       const int &sante_arg,
                       const int &attaque_arg,
                       const int &defense_arg,
                       const PersonnageType &personnageType_arg,
                       std::vector<Objet*> &sac_arg,
                       const Map* carte_arg):
                       nom(std::move(nom_arg)),
                       level(niveau),
                       indice_de_sante_max(sante_arg),
                       attaque_max(attaque_arg),
                       defense_max(defense_arg),
                       typePersonnage(personnageType_arg),
                       sac(sac_arg),
                       carte(std::move(carte_arg))

{
    equipeAll();
}

Personnage::~Personnage() {
    //std::cout << nom << " est mort et ne reviendra plus." << std::endl;
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

int Personnage::getLevel() const {
    return level;
}

int Personnage::getExp() const {
    return exp;
}

const Map *Personnage::getMap() const {
    return carte;
}

int Personnage::setSante(int santeArg) {
    indice_de_sante_actuel = santeArg;
    if(indice_de_sante_actuel > indice_de_sante_max){
        indice_de_sante_actuel = indice_de_sante_max;
    }
    if(indice_de_sante_actuel <= 0){
        indice_de_sante_actuel = 0;
    }
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
    sac.push_back(x);
    getPieceCour()->removeObjet(x);
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
    setSante(getSante() + getSanteMax()/10);
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

void Personnage::victoire(Personnage * vaincu){
    this->reset();
    vaincu->drop();
    exp += vaincu->getLevel() * 25;
    while((exp/100)>0){
        levelUp();
        exp -= 100;
    }
}

void Personnage::levelUp() {
    level += 1;
    std::cout << this->getNom() << " est maintenant de niveau " << this->level << std::endl;
    setMaxSante(getSanteMax() + 25);
    setMaxAttaque(getAttaqueMax() + 10);
    setMaxDefense(getDefenseMax() + 10);

    setAttaque(getAttaqueMax());
    setDefense(getDefenseMax());
    setSante(getSanteMax());
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
        if(statut[i].first == Proteger){
            std::cout << "Proteger ";
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
            setSante(getSante() - (getSanteMax()/16));
            statut[i].second -=1;
          //  std::cout << "Bruler ";
        }
        if(statut[i].first == Empoisonner){
            setSante(getSante() - (getSanteMax()/12));
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

    //std::cout << std::endl;
    return etourdit;
}

void Personnage::actionObjet(const Joueur * player, Personnage *cible) {
    size_t i = 0;
    std::cout << "Objet disponible:" << std::endl;
    std::string choix = "";
    while(i < sac.size()){
        std::cout << "| " << i << " - "<< sac[i]->getNom()
                  << " " << sac[i]->getDescription() << std::endl;
        i++;
    }
    if (i == 0){
        std::cout << "Aucun Objet disponible" << std::endl;
        player->interactionEnCombat(cible);
        return;
    }
    std::cout << "| 4 - Retour choix " << std::endl;
    std::cin >> choix;
    i = 0;
    while(i < sac.size()){
        if(std::to_string(i) == choix ){
            if(sac[i]->getObjetType() == OT_Consommable) {
                if(!sac[i]->checkTp()) {
                    if (sac[i]->checkCible()) {
                        std::cout << "L'objet " << sac[i]->getNom() << " a été utilise sur " << getNom() <<std::endl;
                        sac[i]->appliquerEffet(this);
                    } else {
                        std::cout << "L'objet " << sac[i]->getNom() << " a été utilise sur " << cible->getNom() <<std::endl;
                        sac[i]->appliquerEffet(cible);
                    }
                    //Objet* consomme = sac[i];
                    sac.erase(sac.begin() + i);
                    //delete consomme;
                    //consomme = nullptr;
                    return;
                }else{
                    std::cout << "Erreur la teleportation ne peut être utilisé en combat" << std::endl;
                    player->interactionEnCombat(cible);
                    return;
                }
            }
            else{
                std::cout << "Erreur cette objet n'est pas un consommable" << std::endl;
                player->interactionEnCombat(cible);
                return;
            }
        }
        i++;
    }
    if(choix == "4"){
        player->interactionEnCombat(cible);
        return;
    }
    if(i == sac.size()){
        std::cout << "Erreur cette commande n'existe pas " << std::endl;
        player->interactionEnCombat(cible);
        return;
    }

}

void Personnage::actionObjetHC(const Joueur * player) {
    size_t i = 0;
    std::cout << "Objet disponible: " << std::endl;
    std::string choix = "";
    while(i < sac.size()){
        std::cout << "| " << i << " - "<< sac[i]->getNom()
                  << " " << sac[i]->getDescription() << std::endl;
        i++;
    }
    std::cout << "| 4 - Retour choix " << std::endl;
    if (i == 0){
        std::cout << "Aucun Objet disponible" << std::endl;
        //player->interactionHorsCombat();
        return;
    }
    std::cin >> choix;
    i = 0;
    while(i < sac.size()){
        if(std::to_string(i) == choix ){
            if(sac[i]->getObjetType() == OT_Consommable) {
                if (sac[i]->checkCible()) {
                    std::cout << "L'objet " << sac[i]->getNom() << " a été utilise sur " << getNom() <<std::endl;
                    sac[i]->appliquerEffet(this);
                } else {
                    std::cout << "Erreur pas de cible" << std::endl;
                    //player->interactionHorsCombat();
                    return;
                }
                //Objet* consomme = sac[i];
                sac.erase(sac.begin() + i);
                //delete consomme;
                //consomme = nullptr;
                return;
            }
            else{
                std::cout << "Erreur cette objet n'est pas un consommable" << std::endl;
                //player->interactionHorsCombat();
                return;
            }
        }
        i++;
    }
    if(choix == "4"){
        //player->interactionHorsCombat();
        return;
    }
    if(i == sac.size()){
        std::cout << "Erreur cette commande n'existe pas" << std::endl;
        //player->interactionHorsCombat();
        return;
    }

}

void Personnage::autoloot() {
    if(!getPieceCour()->getVecObjet().empty()){
        if(getSac().size() < 4){
            size_t i = 0;
            while(i < getPieceCour()->getVecObjet().size()){
                if(getPieceCour()->getVecObjet()[i]->getObjetType() == OT_Equipement){
                    pushSac(getPieceCour()->getVecObjet()[i]);
                    equipeAll();
                }
                i++;
            }
        }
        else if(getSac().size() == 4){
            size_t i = 0;
            while(i < getPieceCour()->getVecObjet().size()){
                if(getPieceCour()->getVecObjet()[i]->getObjetType() == OT_Equipement){
                    if(getPieceCour()->getVecObjet()[i]->getRarete() > 0){
                        size_t j = 0;
                        while(j < getSac().size()){
                            if(getPieceCour()->getVecObjet()[i]->getRarete() > getSac()[j]->getRarete()){
                                pushSac(getPieceCour()->getVecObjet()[i]);
                                getPieceCour()->pushObjet(sac[j]);
                                sac[j]->enleverEffet(this);
                                sac.erase(sac.begin() + j);
                                equipeAll();
                                autoloot();
                                return;
                            }
                            j++;
                        }
                    }
                }
                i++;
            }
        }
    }
}

void Personnage::drop() {

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
        std::cout << i << " - "<< sac[i]->getNom()
                  << " " << sac[i]->getDescription() << std::endl;
        i++;
    }
    std::cin >> choix;
    i = 0;
    while(i < sac.size()) {
        if (std::to_string(i) == choix) {
            getPieceCour()->pushObjet(sac[i]);
            sac[i]->enleverEffet(this);
            sac.erase(sac.begin() + i);
            return;
        }
        i++;
    }
    std::cout << "Erreur Objet non trouvé" << std::endl;
    desequipe();
}


Piece* Personnage::deplacement(int arrive) {
    this->pieceCourante->removePerso(this);
    this->pieceCourante->getVecPieceAdjacentes()[arrive]->pushPerso(this);
    return this->setPiece(pieceCourante->getVecPieceAdjacentes()[arrive]);
}

Piece* Personnage::deplacementIA(){
    try {
        autoloot();
        std::random_device seeder;
        std::mt19937 engine(seeder());
        std::uniform_int_distribution<int> dist(0, 3);
        int deplacementAleatoire = dist(engine);
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

void Personnage::actionIa(Personnage * cible, const Joueur * player) {
    std::random_device seeder;
    std::mt19937 engine(seeder());
    std::uniform_int_distribution<int> dist(0, 2);
    int choix = dist(engine);

    std::string choix2 = std::to_string(choix);
    this->action(choix2,cible,player);
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