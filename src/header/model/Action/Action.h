//
// Created by anthony on 12/12/2021.
//

#ifndef LOA_ACTION_H
#define LOA_ACTION_H
#include "../Personnage/Personnage.h"

class Action{
    private:
        Type type;
        Personnage * lanceur;
        Personnage * receveur;
        std::string nom;
        int dommage;
        //std::pair<Personnage::Statut,int> effet;
    public:
        Action(Personnage*,Personnage*, std::string, int, Type);
        void utilisation();
};
#endif //LOA_ACTION_H
