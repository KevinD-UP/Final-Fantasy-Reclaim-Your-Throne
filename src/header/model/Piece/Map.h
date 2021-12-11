//
// Created by kevin on 11/12/2021.
//

#ifndef FINAL_FANTASY_RECLAIM_YOUR_THRONE_MAP_H
#define FINAL_FANTASY_RECLAIM_YOUR_THRONE_MAP_H

#include "Piece.h"

class Map {

private:
    const std::vector<std::vector<Piece*>> map;

public:
    Map();
    std::vector<std::vector<Piece*>> getMap() const;
    static std::vector<std::vector<Piece*>>* initMap();
};

#endif //FINAL_FANTASY_RECLAIM_YOUR_THRONE_MAP_H
