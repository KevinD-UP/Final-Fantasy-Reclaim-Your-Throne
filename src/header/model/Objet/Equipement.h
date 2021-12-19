//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY___RECLAIM_YOUR_THRONE_EQUIPEMENT_H
#define FINAL_FANTASY___RECLAIM_YOUR_THRONE_EQUIPEMENT_H

#include "Objet.h"
#include "../Personnage/Personnage.h"

enum EquipementType {
    /*ET_EPEE,
    ET_LANCE,
    ET_BATON,
    ET_BAGUETTE*/
    ET_ARME,
    ET_PROTECTION
};

class Equipement : public Objet {

private:
    PersonnageType bonusClass;
    EquipementType typeEquipement;
    bool estEquipe;
    int buffDeClasse;
    int buffAutre;

public:
    Equipement(std::string, ObjetType, std::string, PersonnageType, EquipementType, bool, int, int);
    EquipementType getTypeEquipement() const;
    void appliquerEffet(Personnage *) override;
};

#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_EQUIPEMENT_H
