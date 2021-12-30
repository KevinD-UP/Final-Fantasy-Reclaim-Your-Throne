//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Piece/Map.h"


Map::Map() {
    std::vector <Piece *> A = {new Piece(),new Piece(),new Piece(),new Piece()};
    std::vector <Piece *> B = {new Piece(),new Piece(),new Piece(),new Piece()};
    std::vector <Piece *> C = {new Piece(),new Piece(),new Piece(),new Piece()};
    std::vector <Piece *> D = {new Piece(),new Piece(),new Piece(),new Piece()};

    getMap() = {A,B,C,D};
    size_t i = 0;
    size_t j = 0;
    while(i < 4){
        while(j < 4){
            if((i - 1) < 0){
                getMap().at(i).at(j)->getVecPiece().push_back(getMap().at())
            }
            else if((i+1) < 4){

            }
            else if((j - 1) < 0){

            }
            else if((j+1) < 4){

            }
        }
    }

}

std::vector<std::vector<Piece*>> Map::getMap() const {
    return map;
}