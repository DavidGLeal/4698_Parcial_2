#pragma once
#include "Maze.h"
#include "Tile.h"
#include "Wall.h"
#include "Node.h"
#include <vector>

class Maze;
class Path {
public:
    Path(Maze* maze);
    std::vector<Node*> find(Room* startRoom, Room* endRoom);
    std::vector<Node*> backtrack(Node* target);
    void setEdges();

private:
    Maze* maze;
    std::vector<Node*> edges;
};