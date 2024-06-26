//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY_RECLAIM_YOUR_THRONE_PERSONNAGE_H
#define FINAL_FANTASY_RECLAIM_YOUR_THRONE_PERSONNAGE_H



#include <vector>
#include <iostream>
#include <random>
#include "../Objet/Objet.h"

class Equipement;
class Joueur;
class Piece;
class Map;
enum PersonnageType{
    PT_Guerrier,
    PT_Amazone,
    PT_Moine,
    PT_Sorcier,
    PT_Gobelin,
    PT_Loup,
    PT_Dragon
};

enum Statut { Etourdit, Empoisonner, Bruler, Somnolent, Affaiblie, Berserk, Proteger, Ecorcher };
enum Type { Offensive, Defensive, Utilitaire};
class Personnage {

    private:
        const std::string nom;
        int level;
        int exp = 0;
        int indice_de_sante_max;
        int indice_de_sante_actuel = indice_de_sante_max;
        int attaque_max;
        int attaque = attaque_max;
        int defense_max;
        int defense = defense_max;
        PersonnageType typePersonnage;
        Piece* pieceCourante{};
        std::vector<std::pair<Statut, int>> statut;
        std::vector<Objet*> sac;
        const Map* carte;
        Personnage(std::string nom_arg,
                   const int &niveau,
                   const int &sante_arg,
                   const int &attaque_arg,
                   const int &defense_arg,
                   const PersonnageType &personnageType_arg,
                   std::vector<Objet*> &sac_arg,
                   const Map* carte);

    public:
        virtual void print() = 0;
        virtual ~Personnage();

        //Getter
        std::string getNom() const;
        int getSante() const;
        int getSanteMax() const;
        int getAttaqueMax() const;
        int getAttaque() const;
        int getDefenseMax() const;
        int getDefense() const;
        int getLevel() const;
        int getExp() const;
        PersonnageType getPersonnageType() const;
        Piece* getPieceCour();
        std::vector<std::pair<Statut, int>> getStatut();
        std::vector<Objet*> getSac();
        const Map * getMap() const;

        //Opération sur les sac
        Statut pushStatut(Statut,int);
        void pushSac(Objet*);


        //Setter
        int setSante(int santeArg);
        int setMaxSante(int santeArg);
        int setAttaque(int attaqueArg);
        int setMaxAttaque(int attaqueArg);
        int setDefense(int defenseArg);
        int setMaxDefense(int defenseArg);
        Piece* setPiece(Piece*);

        //Statut changement
        void victoire(Personnage *);
        void levelUp();
        void buff(Statut,int);
        void debuff(Statut,int,Personnage*);
        void checkStatut();
        bool updateStatut();
        bool effetPresent(Statut);
        void resetEffet(Statut);
        void enleverEffet(Statut);
        void reset();

        //Equipement check
        void equipeAll();
        void desequipe();
        virtual void drop() = 0;
        void autoloot();

        //Déplacement
        Piece* deplacement(int);
        Piece* deplacementIA();

        void actionIa(Personnage *, const Joueur *);
        virtual void actionJoueur(const Joueur *, Personnage *) = 0;
        void actionObjet(const Joueur *, Personnage *);
        void actionObjetHC(const Joueur *);
        virtual void action(std::string, Personnage *, const Joueur *) = 0;
        friend std::ostream& operator<<(std::ostream& out, Personnage *personnageArg);

        bool estMort();

        friend class Amazone;
        friend class Moine;
        friend class Guerrier;
        friend class Sorcier;
        friend class Gobelin;
        friend class Loup;
        friend class Dragon;
};

#include "../Joueur/Joueur.h"
#include "../Piece/Piece.h"
#include "../Objet/Equipement.h"
#include "../Piece/Map.h"
#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_PERSONNAGE_H
