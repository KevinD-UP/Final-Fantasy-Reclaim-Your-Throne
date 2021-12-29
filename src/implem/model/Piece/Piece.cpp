//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Piece/Piece.h"
#include "../../../header/model/Objet/ConsommableFactory.h"
#include "../../../header/model/Objet/Equipement.h"
#include <unistd.h>

ConsommableType T_PotionSoin = CT_POTIONSOIN;
ConsommableType T_PotionBrulure = CT_POTIONBRULURE;
ConsommableType T_PotionPoison = CT_POTIONPOISON;
ConsommableType T_PotionSomnol = CT_POTIONSOMNOLENCE;

ConsommableType T_PotionBerserk = CT_POTIONBERSERK;
ConsommableType T_PotionAffaiblie = CT_POTIONAFFAIBLIE;
ConsommableType T_PotionProteger = CT_POTIONPROTEGER;
ConsommableType T_PotionEcorcher = CT_POTIONECORCHER;

Consommable* Potion_Soin = ConsommableFactory::initConsommable(T_PotionSoin);
Consommable* Potion_Brulure = ConsommableFactory::initConsommable(T_PotionBrulure);
Consommable* Potion_Poison = ConsommableFactory::initConsommable(T_PotionPoison);
Consommable* Potion_Somnol = ConsommableFactory::initConsommable(T_PotionSomnol);

Consommable* Potion_Berserk = ConsommableFactory::initConsommable(T_PotionBerserk);
Consommable* Potion_Affaiblie = ConsommableFactory::initConsommable(T_PotionAffaiblie);
Consommable* Potion_Proteger = ConsommableFactory::initConsommable(T_PotionProteger);
Consommable* Potion_Ecorcher = ConsommableFactory::initConsommable(T_PotionEcorcher);

auto* Epee = new Equipement("Epee", OT_Equipement, "Attaque:10 Defense:5", PT_Guerrier, false, 10, 5, 0);
auto* Armure = new Equipement("Armure", OT_Equipement, "Defense:10 Sante:20", PT_Guerrier, false, 0, 10, 20);

auto* Toge = new Equipement("Toge",OT_Equipement,"Defense:10 Sante 30",PT_Moine,false,0,10,30);
auto* Masse = new Equipement("Masse",OT_Equipement,"Attaque:5 Defense:5 Sante:15",PT_Moine,false,5,5,15);

auto* Lance = new Equipement("Lance",OT_Equipement,"Attaque:10 Defense:5 Sante:5",PT_Amazone,false,10,5,5);
auto* Arc = new Equipement("Arc",OT_Equipement,"Attaque:10 Sante:15",PT_Amazone,false,10,0,10);

auto* Baguette = new Equipement("Baguette",OT_Equipement,"Attaque:15 Sante:5",PT_Sorcier,false,15,0,5);
auto* Robe = new Equipement("Robe",OT_Equipement,"Attaque:5 Defense:10 Sante:15",PT_Sorcier,false,5,10,15);

std::vector<Objet *> Piece::allEquipement = {Epee,Armure,Toge,Masse,Lance,Arc,Baguette,Robe,Potion_Soin,Potion_Brulure,Potion_Poison,Potion_Somnol,
                                      Potion_Berserk,Potion_Affaiblie,Potion_Proteger,Potion_Ecorcher};

int Piece::random = 0;
Piece::Piece(){
    random ++;
    srand((int) time(0) + random);
    int v1 = rand() % 3;
    fill(v1);
}

void Piece::fill(int i) {
    random ++;
    srand((int) time(0) + random);
    while (i > 0){
        int v1 = rand() % 16;
        pushObjet(allEquipement.at(v1));
        i--;
    }
}

void Piece::print(){
    size_t i = 0;
    while(i < vecObjet.size()){
        std::cout << i << ":"<< vecObjet[i]->getNom()
                  << " " << vecObjet[i]->getDescription() << std::endl;
        i++;
    }
}

void Piece::pushPerso(Personnage* p) {
    vecPerso.push_back(p);
}

void Piece::pushObjet(Objet *o) {
    vecObjet.push_back(o);
}

void Piece::setPiece(std::vector<Piece*> vec) {
    vecPiece = std::move(vec);
}

std::vector<Personnage*> Piece::getVecPerso() const{
    return vecPerso;
}

std::vector<Objet*> Piece::getVecObjet() const{
    return vecObjet;
}

std::vector<Piece*> Piece::getVecPiece() const {
    return vecPiece;
}

bool Piece::combatPossible() const {
    return vecPerso.size() > 1;
}

