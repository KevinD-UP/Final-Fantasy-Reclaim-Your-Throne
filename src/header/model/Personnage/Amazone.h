//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY___RECLAIM_YOUR_THRONE_AMAZONE_H
#define FINAL_FANTASY___RECLAIM_YOUR_THRONE_AMAZONE_H

#include "Personnage.h"
#include "../Objet/Objet.h"
#include "../Joueur/Joueur.h"

class IAmazone {

};

class Amazone : public IAmazone, public Personnage{


    private:
        Amazone(const std::string& nom, int niveau, int sante, int attaque, int defense, PersonnageType typePersonnage, std::vector<Objet*> sac);

    public:
        void action(std::string nom, Personnage * ennemie, const Joueur *) override;
        void actionJoueur(const Joueur *,Personnage *) override;
        void print() override;
        void drop() override;
        virtual ~Amazone();
        friend class AmazoneFactory;
};


#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_AMAZONE_H
