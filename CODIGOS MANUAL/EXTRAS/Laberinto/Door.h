#pragma once
#include "Coordinate.h"
#include "Tile.h"

class Door : public Tile {
public:
    Door(Coordinate coords) : Tile(coords) {}
};

