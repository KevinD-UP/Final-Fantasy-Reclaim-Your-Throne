//
// Created by anthony on 12/12/2021.
//

#ifndef LOA_ACTION_H
#define LOA_ACTION_H
#include "../Personnage/Personnage.h"
#include "../Personnage/Gobelin.h"

class Partie;

class Action{
    private:
        const Joueur* player;
        Type type;
        Personnage * lanceur;
        Personnage * receveur;
        std::string nom;
        int dommage;
    public:
        Action(Personnage*, Personnage*, std::string, int, Type, const Joueur *);
        void utilisation();
};
#include "../../Partie.h"
#endif //LOA_ACTION_H
