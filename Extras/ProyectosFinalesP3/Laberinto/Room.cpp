#include "Room.h"
#include "Door.h"
#include "Wall.h"

Room::Room(Coordinate coords) : Tile(coords) {}

void Room::createWall(Direction direction) {
    setAdjacentAt(direction, new Wall(getAdjacentCoord(direction)));
}

void Room::createDoor(Direction direction) {
    setAdjacentAt(direction, new Door(getAdjacentCoord(direction)));
}

Tile* Room::getAdjacentAt(Direction direction) {
    return adjacentTiles.at(direction);
}

void Room::setAdjacentAt(Direction direction, Tile* tile) {
    if (!hasAdjacentAt(direction)) {
        adjacentTiles[direction] = tile;
    }

    adjacentTiles.at(direction) = tile;
}

bool Room::hasAdjacentAt(Direction direction) {
    return adjacentTiles.find(direction) != adjacentTiles.end();
}

std::map<Direction, Tile*> Room::getAdjacentTiles() {
    return adjacentTiles;
}

void Room::setAdjacentAtCoord(Coordinate coord, Tile* tile) {
    for (auto item : adjacentTiles) {
        auto direction = item.first;
        auto currentTile = item.second;

        if (tile->getCoords() == currentTile->getCoords()) {
            setAdjacentAt(direction, tile);
        }
    }
}

Tile* Room::getAdjacentAtCoords(Coordinate coord) {
    for (auto item : adjacentTiles) {
        auto direction = item.first;
        auto adjacent = item.second;

        if (adjacent->getCoords().getX() == coords.getX()
            && adjacent->getCoords().getY() == coords.getY()) {
            return adjacent;
        }
    }

    return nullptr;
}

Coordinate Room::getAdjacentCoord(Direction direction) {
    Coordinate current = getCoords();
    Coordinate target = current;

    switch (direction.value()) {
        case direction.NORTH:
            target = Coordinate(current.getX(), current.getY() - 1);
            break;
        case direction.SOUTH:
            target = Coordinate(current.getX(), current.getY() + 1);
            break;
        case direction.WEST:
            target = Coordinate(current.getX() - 1, current.getY());
            break;
        case direction.EAST:
            target = Coordinate(current.getX() + 1, current.getY());
            break;
        default: break;
    }

    return target;
}