//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY___RECLAIM_YOUR_THRONE_EQUIPEMENT_H
#define FINAL_FANTASY___RECLAIM_YOUR_THRONE_EQUIPEMENT_H

#include "Objet.h"

enum EquipementType {

};

class Equipement : public Objet {

private:
    EquipementType typeEquipement;

public:
    EquipementType getTypeEquipement() const;
    void appliquerEffet() override;


};


#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_EQUIPEMENT_H
