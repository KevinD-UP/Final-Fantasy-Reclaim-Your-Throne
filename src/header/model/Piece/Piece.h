//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY___RECLAIM_YOUR_THRONE_PIECE_H
#define FINAL_FANTASY___RECLAIM_YOUR_THRONE_PIECE_H


#include "../Objet/Objet.h"
#include <vector>
class Personnage;

class Piece {

private:
    std::vector<Personnage*> vecPerso;
    std::vector<Objet*> vecObjet;
    std::vector<Piece*> vecPiece;

public:
    Piece();
    void pushPerso(Personnage *);
    void pushObjet(Objet*);
    void fill(int);
    void setPiece(std::vector<Piece*>);
    std::vector<Personnage*> getVecPerso() const;
    std::vector<Objet*> getVecObjet() const;
    std::vector<Piece*> getVecPiece() const;
    bool combatPossible() const;
    void print();
    static std::vector<Objet *> allEquipement;
    static int random;

};

#include "../Personnage/Personnage.h"
#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_PIECE_H
