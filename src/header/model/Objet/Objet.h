//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY___RECLAIM_YOUR_THRONE_OBJET_H
#define FINAL_FANTASY___RECLAIM_YOUR_THRONE_OBJET_H

#include <iostream>

enum ObjetType {
    OT_Equipement,
    OT_Consommable
};

class Objet {

private:
    const std::string nom;
    const ObjetType objetType;
    Objet();

public:
    std::string getNom() const;
    ObjetType getObjetType() const;
    virtual void appliquerEffet() = 0;

    friend class Consommable;
    friend class Equipement;
};


#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_OBJET_H
