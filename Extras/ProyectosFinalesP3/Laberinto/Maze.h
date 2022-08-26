#pragma once
#include "Tile.h"
#include "Room.h"
#include "Path.h"
#include "Node.h"
#include "Wall.h"
#include "Direction.h"
#include "Door.h"
#include "Utils.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <set>
#include <unordered_set>

class Path;

class Maze {
public:
    Maze(int width, int height);
    void initialize();
    void generate();
    void regenerate();
    std::map<Direction, Room*> getNeighborRooms(Room* room);
    Room* getRoomAt(int x, int y);
    Tile* getTileAt(Coordinate coords);
    void draw(sf::RenderWindow* window);
    void handleKeyPressed(sf::Keyboard::Key key);

    Path* getPath();
    std::vector<Room*>& getRooms();
    std::vector<std::vector<Tile*>>& getTiles();
    int getWidth();
    int getHeight();

private:
    int width;
    int height;
    std::vector<std::vector<Tile*>> tiles;
    std::vector<Room*> rooms;
    std::set<Room*> visitedRooms;
    std::unordered_set<Tile*> walls;
    bool initialized = false;
    Path* path;
    std::vector<Node*> solution;

    bool highlightRooms = false;
    bool highlightPillars = false;
    bool highlightWalls = false;
    bool highlightDoors = false;
    bool showSolution = true;
};