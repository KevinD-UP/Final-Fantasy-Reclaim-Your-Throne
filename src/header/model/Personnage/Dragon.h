//
// Created by anthony on 13/01/2022.
//

#ifndef FINAL_FANTASY_RECLAIM_YOUR_THRONE_DRAGON_H
#define FINAL_FANTASY_RECLAIM_YOUR_THRONE_DRAGON_H

#include "../Personnage/Personnage.h"
#include "../Action/Action.h"
#include <iostream>

class Dragon : public Personnage {

private:

    Dragon(const std::string& nom, int niveau, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet*> sac,const Map* carte);

public:
    void action(std::string nom, Personnage * ennemie, const Joueur *) override;
    void actionJoueur(const Joueur *,Personnage *) override;
    void print() override;
    void drop() override;
    virtual ~Dragon();
    friend std::ostream& operator<<(std::ostream& out, Dragon *mobArg);
    friend class DragonFactory;
};

#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_DRAGON_H
