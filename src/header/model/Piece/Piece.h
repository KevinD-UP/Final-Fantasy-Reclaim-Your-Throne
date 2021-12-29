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
    std::vector<Piece*> vecPiecesAdjacentes;

public:
    Piece(std::vector<Objet*>,std::vector<Piece*>);
    void pushPerso(Personnage *);
    void removePerso();
    void pushObjet(Objet*);
    void setPiecesAdjacentes(std::vector<Piece*>);
    std::vector<Personnage*> getVecPerso() const;
    std::vector<Objet*> getVecObjet() const;
    std::vector<Piece*> getVecPieceAdjacentes() const;
    bool combatPossible() const;

};

#include "../Personnage/Personnage.h"
#endif //FINAL_FANTASY___RECLAIM_YOUR_THRONE_PIECE_H
