#pragma once
#include "Tile.h"
#include "Coordinate.h"

class Wall : public Tile {
public:
    Wall(Coordinate coords) : Tile(coords) {}
};

