//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY___RECLAIM_YOUR_THRONE_GUERRIER_H
#define FINAL_FANTASY___RECLAIM_YOUR_THRONE_GUERRIER_H

#include "Personnage.h"
#include "../Objet/Objet.h"
#include <iostream>
using namespace std;

class IGuerrier {
};

class Guerrier : public IGuerrier, public Personnage{


    private:
        Guerrier(std::string nom, int sante, int attaque, int defense, std::vector<Objet*> sac);

    public:
        void action(std::string nom, Personnage * ennemie) override;
        void print() override;
        friend class GuerrierFactory;
        friend std::ostream& operator<<(std::ostream& out, Guerrier *guerrierArg);
};


#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_GUERRIER_H
