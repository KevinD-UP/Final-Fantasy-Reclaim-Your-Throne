//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY___RECLAIM_YOUR_THRONE_CONSOMMABLE_H
#define FINAL_FANTASY___RECLAIM_YOUR_THRONE_CONSOMMABLE_H

#include "Objet.h"

enum ConsommableType {
    CT_POTIONSOIN,
    CT_POTIONBRULURE,
    CT_POTIONPOISON,
    CT_POTIONSOMNOLENCE
};

class Consommable : public Objet{

private:
    ConsommableType typeConsommable;

public:
    ConsommableType getTypeConsommable() const;
    void appliquerEffet() override;
};


#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_CONSOMMABLE_H
