//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY___RECLAIM_YOUR_THRONE_AMAZONE_H
#define FINAL_FANTASY___RECLAIM_YOUR_THRONE_AMAZONE_H

#include "Personnage.h"
#include "../Objet/Objet.h"

class IAmazone {

};

class Amazone : public IAmazone, public Personnage{


    private:
        Amazone(std::string nom, int sante, int attaque, int defense, std::vector<Objet*> sac);

    public:
        void print() override;
        friend class AmazoneFactory;

};


#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_AMAZONE_H
