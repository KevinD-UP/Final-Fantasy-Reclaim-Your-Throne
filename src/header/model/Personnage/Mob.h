//
// Created by kevin on 11/01/2022.
//

#ifndef FINAL_FANTASY_RECLAIM_YOUR_THRONE_MOB_H
#define FINAL_FANTASY_RECLAIM_YOUR_THRONE_MOB_H

#include "../Personnage/Personnage.h"
#include "../Action/Action.h"
#include <iostream>

class Mob : public Personnage {

private:

    Mob(const std::string& nom, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet*> sac);

public:
    const std::string nom;
    int indice_de_sante_max;
    int indice_de_sante_actuel = indice_de_sante_max;
    int attaque_max;
    int attaque = attaque_max;
    int defense_max;
    int defense = defense_max;
    virtual ~Mob();
    void action(std::string nom, Personnage * ennemie) override;
    void actionJoueur(const Joueur *,Personnage *) override;
    void print() override;
    friend std::ostream& operator<<(std::ostream& out, Mob *mobArg);
    friend class MobFactory;
};


#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_MOB_H
