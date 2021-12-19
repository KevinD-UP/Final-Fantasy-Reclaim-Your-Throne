//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY_RECLAIM_YOUR_THRONE_PERSONNAGE_H
#define FINAL_FANTASY_RECLAIM_YOUR_THRONE_PERSONNAGE_H

#include <vector>
#include <iostream>
#include "../Objet/Objet.h"
#include "../Piece/Piece.h"

enum PersonnageType{
    PT_Guerrier,
    PT_Amazone,
    PT_Moine,
    PT_Sorcier,
};

enum Statut { Etourdit, Empoisonner, Bruler, Somnolent };
enum Type { Offensive, Defensive, Utilitaire};

class Personnage {

    private:
        const std::string nom;
        int indice_de_sante_max;
        int indice_de_sante_actuel = indice_de_sante_max;
        int attaque;
        int defense;
        PersonnageType typePersonnage;
        Piece* pieceCourante;
        std::pair<Statut, int> statut;
        std::vector<Objet*> sac;
        Personnage(const std::string &nom_arg,
                   const int &sante_arg,
                   const int &attaque_arg,
                   const int &defense_arg,
                   const PersonnageType &personnageType_arg,
                   std::vector<Objet*> &sac_arg);

    public:
        virtual void print() = 0;

        //Getter
        std::string getNom() const;
        int getSante() const;
        int getSanteMax() const;
        int getAttaque() const;
        int getDefense() const;
        PersonnageType getPersonnageType() const;
        Piece* getPieceCour();
        std::pair<Statut, int> getStatut();
        std::vector<Objet*> getSac();

        //Opé sur les sac
        void pushStatut(std::pair<Statut, int> *);
        void pushSac(Objet*);

        //Setter
        int setSante(int santeArg);
        int setAttaque(int attaqueArg);
        int setDefense(int defenseArg);
        Piece* setPiece(Piece*);

        virtual void action(std::string, Personnage *) = 0;
        friend std::ostream& operator<<(std::ostream& out, Personnage *personnageArg);

        bool estMort();

        friend class Amazone;
        friend class Moine;
        friend class Guerrier;
        friend class Sorcier;


};


#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_PERSONNAGE_H
