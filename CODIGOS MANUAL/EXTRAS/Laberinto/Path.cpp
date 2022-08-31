#include "Path.h"
#include <deque>
#include <queue>
#include <iostream>

Path::Path(Maze* maze) {
    this->maze = maze;
}

std::vector<Node*> Path::find(Room* startRoom, Room* endRoom) {
    std::deque<Node*> stack;
    std::vector<Node*> found;
    setEdges();

    Node* start = nullptr;
    Node* end = nullptr;

    for (Node* node : edges) {
        if (node->getCoords() == startRoom->getCoords()) {
            start = node;
        }

        if (node->getCoords() == endRoom->getCoords()) {
            end = node;
        }

        if (start != nullptr && end != nullptr) {
            break;
        }
    }

    if (start == nullptr || end == nullptr) {
        return std::vector<Node*>();
    }

    std::cout << "start: " << start->getCoords().toString() << std::endl;
    std::cout << "end: " << end->getCoords().toString() << std::endl;

    start->setParent(nullptr);
    stack.push_front(start);

    while (!stack.empty()) {
        Node* node = stack.front();
        stack.pop_front();

        if (node->equals(end)) {
            return backtrack(node);
        }

        node->setVisited(true);

        for (Node* adjacent : node->getAdjacentNodes()) {
            if (!adjacent->isVisited()) {
                adjacent->setParent(node);
                adjacent->setVisited(true);
                stack.push_front(adjacent);
            }
        }
    }

    for (auto el : stack) {
        found.push_back(el);
    }

    return found;
}

std::vector<Node*> Path::backtrack(Node* target) {
    std::vector<Node*> path;
    Node* parent = target;

    do {
        path.push_back(parent);
        parent = parent->getParent();
    } while (parent != nullptr);

    return path;
}

void Path::setEdges() {
    std::vector<Room*> rooms = maze->getRooms();
    edges.clear();

    for (int y = 0; y < maze->getHeight(); y++) {
        for (int x = 0; x < maze->getWidth(); x++) {
            edges.push_back(new Node(Coordinate(x, y)));
        }
    }

    for (Node* node : edges) {
        int x = node->getCoords().getX();
        int y = node->getCoords().getY();
        Tile* tile = maze->getTiles()[y][x];

        std::vector<Coordinate> moves = {
            Coordinate::transform(tile->getCoords(), 0, 1),
            Coordinate::transform(tile->getCoords(), 0, -1),
            Coordinate::transform(tile->getCoords(), 1, 0),
            Coordinate::transform(tile->getCoords(), -1, 0)
        };

        for (auto coordinate : moves) {
            Node* adjacent = nullptr;

            for (Node* edge : edges) {
                if (edge->getCoords().equals(coordinate)) {
                    adjacent = edge;
                    break;
                }
            }

            if (adjacent == nullptr || Utils::instanceof<Wall>(tile)) {
                continue;
            }

            adjacent->setParent(node);
            node->addAdjacent(adjacent);
        }
    }
}