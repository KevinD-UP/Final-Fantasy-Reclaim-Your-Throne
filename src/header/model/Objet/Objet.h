//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY___RECLAIM_YOUR_THRONE_OBJET_H
#define FINAL_FANTASY___RECLAIM_YOUR_THRONE_OBJET_H

#include <iostream>



class Personnage;



enum ObjetType {
    OT_Equipement,
    OT_Consommable
};

class Objet {

private:
    const std::string nom;
    const ObjetType objetType;
    std::string description;
    Objet(std::string, ObjetType, std::string);

public:
    virtual ~Objet();
    std::string getNom() const;
    ObjetType getObjetType() const;
    std::string getDescription() const;
    virtual void appliquerEffet(Personnage *) = 0;
    virtual void enleverEffet(Personnage *) = 0;
    friend class Consommable;
    friend class Equipement;
};


#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_OBJET_H
