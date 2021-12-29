//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Piece/Piece.h"

Piece::Piece(std::vector<Objet*> vecO, std::vector<Piece*> vecPie) : vecObjet(std::move(vecO)), vecPiecesAdjacentes(std::move(vecPie)){}

void Piece::pushPerso(Personnage* p) {
    vecPerso.push_back(p);
}

void Piece::removePerso() {
    vecPerso.erase(vecPerso.begin());
}

void Piece::pushObjet(Objet *o) {
    vecObjet.push_back(o);
}

void Piece::setPiecesAdjacentes(std::vector<Piece*> vec) {
    vecPiecesAdjacentes = std::move(vec);
}

std::vector<Personnage*> Piece::getVecPerso() const{
    return vecPerso;
}

std::vector<Objet*> Piece::getVecObjet() const{
    return vecObjet;
}

std::vector<Piece*> Piece::getVecPieceAdjacentes() const {
    return vecPiecesAdjacentes;
}

bool Piece::combatPossible() const {
    return vecPerso.size() > 1;
}