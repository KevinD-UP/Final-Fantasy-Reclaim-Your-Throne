//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY_RECLAIM_YOUR_THRONE_PERSONNAGE_H
#define FINAL_FANTASY_RECLAIM_YOUR_THRONE_PERSONNAGE_H

#include <vector>
#include <iostream>
#include "../Objet/Objet.h"
#include "../Piece/Piece.h"

enum Statut { Etourdit, Empoisonner, Bruler, Somnolent };

class Piece;

class Personnage {

    private:
        const std::string nom;
        int indice_de_sante_max;
        int indice_de_sante_actuel = indice_de_sante_max;
        int attaque;
        int defense;
        Piece* pieceCourante;
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
        void pushStatut(std::pair<Statut, int> *);
        void pushSac(Objet*);

        int setSante(int santeArg);
        int setAttaque(int attaqueArg);
        int setDefense(int defenseArg);
        Piece* setPiece(Piece*);
        Piece* getPieceCour();
        virtual void action(std::string, Personnage *) = 0;

        bool estMort();

        std::pair<Statut, int> getStatut();
        std::vector<Objet*> getSac();

        friend class Amazone;
        friend class Moine;
        friend class Guerrier;
        friend class Sorcier;


};


#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_PERSONNAGE_H
