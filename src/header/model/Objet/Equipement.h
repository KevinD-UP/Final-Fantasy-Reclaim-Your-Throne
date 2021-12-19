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
    bool estEquipe;

public:
    EquipementType getTypeEquipement() const;
    void appliquerEffet() override;
    virtual void equiper() = 0;


};


#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_EQUIPEMENT_H
