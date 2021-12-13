//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Piece/Piece.h"

#include <utility>

Piece::Piece(std::vector<Objet*> vecO, std::vector<Piece*> vecPie) : vecObjet(std::move(vecO)), vecPiece(std::move(vecPie)){}

void Piece::pushPerso(Personnage* p) {
    vecPerso.push_back(p);
}

void Piece::pushObjet(Objet* o) {
    vecObjet.push_back(o);
}

void Piece::setPiece(std::vector<Piece*> vec) {
    vecPiece = std::move(vec);
}

std::vector<Personnage*> Piece::getVecPerso() const{
    return vecPerso;
}

std::vector<Objet*> Piece::getVecObjet() const{
    return vecObjet;
}

std::vector<Piece*> Piece::getVecPiece() const {
    return vecPiece;
}