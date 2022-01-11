//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY___RECLAIM_YOUR_THRONE_GUERRIER_H
#define FINAL_FANTASY___RECLAIM_YOUR_THRONE_GUERRIER_H

#include "Personnage.h"
#include "../Objet/Objet.h"
#include "../Joueur/Joueur.h"
#include "../Action/Action.h"
#include <iostream>

class IGuerrier {
};

class Guerrier : public IGuerrier, public Personnage{


    private:
        Guerrier(const std::string& nom, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet*> sac);

    public:
        void action(std::string nom, Personnage * ennemie) override;
        void actionJoueur(const Joueur *,Personnage *) override;
        void print() override;
        friend class GuerrierFactory;
        friend std::ostream& operator<<(std::ostream& out, Guerrier *guerrierArg);
};


#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_GUERRIER_H
