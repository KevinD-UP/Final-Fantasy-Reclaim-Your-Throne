//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY___RECLAIM_YOUR_THRONE_MOINE_H
#define FINAL_FANTASY___RECLAIM_YOUR_THRONE_MOINE_H

#include "Personnage.h"
#include "../Objet/Objet.h"

class IMoine{

};

class Moine : public IMoine, public Personnage {

    private:
        Moine(std::string nom, int sante, int attaque, int defense, std::vector<Objet*> sac);

    public:
        void action(std::string nom, Personnage * ennemie) override;
        void print() override;
        friend class MoineFactory;
};


#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_MOINE_H
