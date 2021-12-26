//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY___RECLAIM_YOUR_THRONE_EQUIPEMENT_H
#define FINAL_FANTASY___RECLAIM_YOUR_THRONE_EQUIPEMENT_H

#include "Objet.h"
#include "../Personnage/Personnage.h"

/*enum EquipementType {
    ET_EPEE,
    ET_LANCE,
    ET_BATON,
    ET_BAGUETTE
    ET_ARME,
    ET_PROTECTION
};*/

class Equipement : public Objet {

private:
    PersonnageType bonusClass;
    //EquipementType typeEquipement;
    bool estEquipe;
    int buffAttaque;
    int buffDefense;
    int buffSante;
    //int buffAutre;

public:
    Equipement(std::string, ObjetType, std::string, PersonnageType, bool, int, int, int);
    //EquipementType getTypeEquipement() const;
    void appliquerEffet(Personnage *) override;
    void enleverEffet(Personnage *) override;
};

#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_EQUIPEMENT_H
