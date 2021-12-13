//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY_RECLAIM_YOUR_THRONE_PERSONNAGE_H
#define FINAL_FANTASY_RECLAIM_YOUR_THRONE_PERSONNAGE_H

#include <vector>
#include <iostream>
#include "../Objet/Objet.h"

class Personnage {


public:
    virtual void print() = 0;
    enum Statut { Etourdit, Empoisonner, Bruler, Somnolent };
    std::string getNom() const;
    int getSante() const;
    int getAttaque() const;
    int getDefense() const;
    //std::vector<std::pair<Statut, int>> getStatut() const;
    std::vector<Objet*> getSac();
    void setSante(int);
    void setAttaque(int);
    void setDefense(int);
    void pushStatut(std::pair<Personnage::Statut, int> *);
    void pushSac(Objet*);
    virtual void action(std::string,Personnage*);
    friend class Amazone;
    friend class Moine;
    friend class Guerrier;
    friend class Sorcier;

    private:
        const std::string nom;
        int indice_de_sante;
        int attaque;
        int defense;
        std::vector<std::pair<Statut, int>> statut;
        std::vector<Objet*> sac;
        Personnage(std::string nom_arg,
                   const int &sante_arg,
                   const int &attaque_arg,
                   const int &defense_arg,
                   std::vector<Objet*> sac_arg);



};


#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_PERSONNAGE_H
