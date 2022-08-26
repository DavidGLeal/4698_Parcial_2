#pragma once
#include "Tile.h"
#include "Direction.h"
#include <map>
#include <optional>

class Room : public Tile {
public:
    Room() = default;
    Room(Coordinate coords);
    void createWall(Direction direction);
    void createDoor(Direction direction);
    Tile* getAdjacentAt(Direction direction);
    void setAdjacentAt(Direction direction, Tile* tile);
    bool hasAdjacentAt(Direction direction);
    std::map<Direction, Tile*> getAdjacentTiles();
    void setAdjacentAtCoord(Coordinate coord, Tile* tile);
    Tile* getAdjacentAtCoords(Coordinate coord);
    Coordinate getAdjacentCoord(Direction direction);
    
private:
    std::map<Direction, Tile*> adjacentTiles;
};

