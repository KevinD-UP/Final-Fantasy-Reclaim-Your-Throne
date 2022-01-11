//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY___RECLAIM_YOUR_THRONE_SORCIER_H
#define FINAL_FANTASY___RECLAIM_YOUR_THRONE_SORCIER_H

#include "Personnage.h"
#include "../Objet/Objet.h"
#include "../Joueur/Joueur.h"
class ISorcier {

};

class Sorcier : public ISorcier, public Personnage {


    private:
        Sorcier(std::string nom, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet*> sac);

    public:
        void action(std::string nom, Personnage * ennemie, const Joueur *) override;
        void actionJoueur(const Joueur *,Personnage *) override;
        void print() override;
        virtual ~Sorcier();
        friend class SorcierFactory;
};


#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_SORCIER_H
