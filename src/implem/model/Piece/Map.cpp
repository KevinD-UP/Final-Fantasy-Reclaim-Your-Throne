//
// Created by kevin on 11/12/2021.
//

#include "../../../header/model/Piece/Map.h"


Map::Map() {}

std::vector<std::vector<Piece*>> Map::getMap() const {
    return map;
}