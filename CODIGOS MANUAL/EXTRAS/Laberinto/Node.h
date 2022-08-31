#pragma once
#include "Coordinate.h"
#include <vector>

class Node {
public:
    Node(Coordinate coords) {
        this->coords = coords;
    }

    void addAdjacent(Node* child) {
        if (adjacentList.size() == 4) return;
        adjacentList.push_back(child);
    }

    std::vector<Node*>& getAdjacentNodes() {
        return adjacentList;
    }

    void setParent(Node* parent) {
        this->parent = parent;
    }

    Node* getParent() {
        return parent;
    }

    void setVisited(bool visited) {
        this->visited = visited;
    }

    bool isVisited() {
        return visited;
    }

    Coordinate getCoords() {
        return coords;
    }

    bool equals(Node* target) {
        return coords.equals(target->getCoords());
    }
    
private:
    Coordinate coords;
    Node* parent = nullptr;
    bool visited = false;
    std::vector<Node*> adjacentList;
};

