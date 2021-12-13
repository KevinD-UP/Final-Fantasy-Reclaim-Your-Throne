//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY_RECLAIM_YOUR_THRONE_PERSONNAGE_H
#define FINAL_FANTASY_RECLAIM_YOUR_THRONE_PERSONNAGE_H

#include <vector>
#include <iostream>
#include "../Objet/Objet.h"

class Personnage {

    enum Statut { Etourdit, Empoisonner, Bruler, Somnolent };

    private:
        const std::string nom;
        int indice_de_sante;
        int attaque;
        int defense;
        std::pair<Statut, int> statut;
        std::vector<Objet*> sac;
        Personnage(std::string nom_arg,
                   const int &sante_arg,
                   const int &attaque_arg,
                   const int &defense_arg,
                   std::vector<Objet*> sac_arg);

    public:
        virtual void print() = 0;
        std::string getNom() const;
        int getSante() const;
        int getAttaque() const;
        int getDefense() const;
        int setSante(int santeArg);
        int setAttaque(int attaqueArg);
        int setDefense(int defenseArg);
        std::pair<Personnage::Statut, int> getStatut();
        std::vector<Objet*> getSac();
        friend class Amazone;
        friend class Moine;
        friend class Guerrier;
        friend class Sorcier;

};


#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_PERSONNAGE_H
