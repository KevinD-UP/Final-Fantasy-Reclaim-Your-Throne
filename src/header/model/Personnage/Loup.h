//
// Created by anthony on 12/01/2022.
//

#ifndef FINAL_FANTASY_RECLAIM_YOUR_THRONE_LOUP_H
#define FINAL_FANTASY_RECLAIM_YOUR_THRONE_LOUP_H

#include "../Personnage/Personnage.h"
#include "../Action/Action.h"
#include <iostream>

class Loup : public Personnage {

private:

    Loup(const std::string& nom, int niveau, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet*> sac, const Map* carte);

public:
    void action(std::string nom, Personnage * ennemie, const Joueur *) override;
    void actionJoueur(const Joueur *,Personnage *) override;
    void print() override;
    void drop() override;
    virtual ~Loup();
    friend std::ostream& operator<<(std::ostream& out, Loup *mobArg);
    friend class LoupFactory;
};


#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_LOUP_H
