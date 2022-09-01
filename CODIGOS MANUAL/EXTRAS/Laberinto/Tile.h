#pragma once
#include "Coordinate.h"

class Tile {
public:
    Tile() = default;
    Tile(Coordinate coords) : coords(coords) {}
    virtual ~Tile() {}

    Coordinate getCoords() const {
        return coords;
    }

protected:
    Coordinate coords;
};
