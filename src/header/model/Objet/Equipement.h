//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY___RECLAIM_YOUR_THRONE_EQUIPEMENT_H
#define FINAL_FANTASY___RECLAIM_YOUR_THRONE_EQUIPEMENT_H

#include "Objet.h"
#include "../Personnage/Personnage.h"


class Equipement : public Objet {

private:
    PersonnageType bonusClass;
    //EquipementType typeEquipement;
    bool estEquipe;
    int buffAttaque;
    int buffDefense;
    int buffSante;
    int rarete;
    //int buffAutre;

public:
    Equipement(std::string, ObjetType, std::string, PersonnageType, bool, int, int, int, int);
    //EquipementType getTypeEquipement() const;
    int getRarete() override;
    void appliquerEffet(Personnage *) override;
    void enleverEffet(Personnage *) override;
    __attribute__((unused)) bool checkCible() override;
    bool checkTp() override;
};

#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_EQUIPEMENT_H
