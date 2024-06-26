//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Piece/Map.h"


Map::Map() {
    std::vector <Piece *> A = {new Piece(),new Piece(),new Piece(),new Piece()};
    std::vector <Piece *> B = {new Piece(),new Piece(),new Piece(),new Piece()};
    std::vector <Piece *> C = {new Piece(),new Piece(),new Piece(),new Piece()};
    std::vector <Piece *> D = {new Piece(),new Piece(),new Piece(),new Piece()};

    map = {A,B,C,D};
    int i = 0;
    while(i < 4){
        int j = 0;
        while(j < 4){
            if((i - 1) < 0){
                map[i][j]->pushPiece(nullptr);
            }else{
              map[i][j]->pushPiece(map[i-1][j]);
            }
            if((j - 1) < 0){
                map[i][j]->pushPiece(nullptr);
            }else{
                map[i][j]->pushPiece(map[i][j-1]);
            }
            if((i+1) >= 4){
                map[i][j]->pushPiece(nullptr);
            }else{
                map[i][j]->pushPiece(map[i+1][j]);
            }
            if((j+1) >= 4){
                map[i][j]->pushPiece(nullptr);
            }else{
                map[i][j]->pushPiece(map[i][j+1]);
            }
            //map[i][j]->print();
            j++;
        }
        i++;
    }

}

void Map::showMap(const Joueur * joueur) const {
    for(int i =0; i< 4; i++){
        for(int j=0; j< 4;j++){
            if(map[i][j] == joueur->getPerso()->getPieceCour()){
                std::cout<<"|O|";
            }
            else{
                std::cout<<"|X|";
            }
        }
        std::cout<<std::endl;
    }
}

std::vector<std::vector<Piece*>> Map::getMap() const {
    return map;
}