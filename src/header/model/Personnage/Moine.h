//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY___RECLAIM_YOUR_THRONE_MOINE_H
#define FINAL_FANTASY___RECLAIM_YOUR_THRONE_MOINE_H

#include "Personnage.h"
#include "../Objet/Objet.h"
#include "../Joueur/Joueur.h"

class IMoine{

};

class Moine : public IMoine, public Personnage {

    private:
        Moine(const std::string& nom, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet*> sac);

    public:
        void action(std::string nom, Personnage * ennemie) override;
        void actionJoueur(const Joueur *,Personnage *) override;
        void actionIa(Personnage *) override;
        void print() override;
        friend class MoineFactory;
};


#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_MOINE_H
