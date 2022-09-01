#include "Maze.h"
#include <iostream>
#include <type_traits>

Maze::Maze(int width, int height) : path(new Path(this)) {
    this->width = width;
    this->height = height;
    this->tiles = std::vector<std::vector<Tile*>>(
        height,
        std::vector<Tile*>(width, nullptr)
    );
}

void Maze::initialize() {
    int horizontalRooms = (int)std::ceil(width / 2);
    int verticalRooms = (int)std::ceil(height / 2);

    if (initialized) {
        return;
    }

    for (int y = 0; y < verticalRooms; y++) {
        for (int x = 0; x < horizontalRooms; x++) {
            Coordinate coords((2 * x) + 1, (2 * y) + 1);

            if (coords.getX() >= width || coords.getY() >= height) continue;

            Room* room = new Room(coords);

            if (coords.getX() == (width - 1) || coords.getY() == (height - 1)) {
                tiles[coords.getY()][coords.getX()] = new Wall(coords);
                continue;
            }

            rooms.push_back(room);
        }
    }

    for (Room* room : rooms) {
        int x = room->getCoords().getX();
        int y = room->getCoords().getY();

        // set the room neighbours
        std::map<Direction, Room*> neighbours = getNeighborRooms(room);

        for (Direction direction : Direction::values()) {
            if (!room->hasAdjacentAt(direction) && y > 0) {
                if (neighbours.find(direction) != neighbours.end()
                    && neighbours.at(direction)->hasAdjacentAt(direction.opposite())) {
                    room->setAdjacentAt(direction,
                        neighbours.at(direction)->getAdjacentAt(direction.opposite()));
                }
                else {
                    room->createWall(direction);
                }
            }
        }
    }

    for (Room* room : rooms) {
        int x = room->getCoords().getX();
        int y = room->getCoords().getY();

        tiles[y][x] = room;

        for (Direction direction : Direction::values()) {
            if (room->hasAdjacentAt(direction)) {
                x = room->getAdjacentAt(direction)->getCoords().getX();
                y = room->getAdjacentAt(direction)->getCoords().getY();
                tiles[y][x] = room->getAdjacentAt(direction);
            }
        }
    }

    // set the pillars
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if ((x + 1) % 2 == 0 || (y + 1) % 2 == 0) {
                continue;
            }

            tiles[y][x] = new Wall(Coordinate(x, y));
        }
    }

    initialized = true;
}

void Maze::generate() {
    Room* room = nullptr;
    Tile* wall = nullptr;

    initialize();

    if (visitedRooms.size() == rooms.size()) {
        std::cout << "Maze is already generated" << std::endl;
    }

    do {
        room = rooms.at(Utils::random_between(0, rooms.size() - 1));
    } while (visitedRooms.find(room) != visitedRooms.end());

    visitedRooms.insert(room);

    auto tiles_ = room->getAdjacentTiles();

    for (auto item : tiles_) {
        walls.insert(item.second);
    }

    while (!walls.empty()) {
        int randomIndex = Utils::random_between(0, walls.size() - 1);
        std::unordered_set<Tile*>::iterator found = walls.begin();

        auto it = walls.begin();

        for (int i = 0; i < randomIndex; i++) {
            it++;
        }

        Tile* randomWall = *it;

        std::vector<Tile*> possibleAdjacentTiles = {
            getTileAt(Coordinate::transform(randomWall->getCoords(), 1, 0)),
            getTileAt(Coordinate::transform(randomWall->getCoords(), -1, 0)),
            getTileAt(Coordinate::transform(randomWall->getCoords(), 0, 1)),
            getTileAt(Coordinate::transform(randomWall->getCoords(), 0, -1))
        };

        std::vector<Tile*> adjacentTiles;

        for (auto tile : possibleAdjacentTiles) {
            if (tile != nullptr) {
                adjacentTiles.push_back(tile);
            }
        }

        std::vector<Tile*> adjacentRooms;
        Room* unvisitedRoom = nullptr;

        for (auto tile : adjacentTiles) {
            if (Utils::instanceof<Room>(tile)) {
                adjacentRooms.push_back(static_cast<Room*>(tile));
            }
        }

        for (auto tile : adjacentRooms) {
            if (visitedRooms.find(static_cast<Room*>(tile)) == visitedRooms.end()) {
                unvisitedRoom = static_cast<Room*>(tile);
                break;
            }
        }

        if (adjacentRooms.size() == 2 && unvisitedRoom != nullptr) {
            Door* door = new Door(randomWall->getCoords());

            tiles.at(randomWall->getCoords().getY()).at(randomWall->getCoords().getX()) = door;
            unvisitedRoom->setAdjacentAtCoord(randomWall->getCoords(), door);
            visitedRooms.insert(unvisitedRoom);

            auto roomTiles = unvisitedRoom->getAdjacentTiles();
            
            for (auto entry : roomTiles) {
                auto t = entry.second;

                if (Utils::instanceof<Wall>(t)) {
                    walls.insert(t);
                }
            }
        }

        walls.erase(randomWall);
    }
}

void Maze::regenerate() {
    initialized = false;
    showSolution = true;
    tiles = std::vector<std::vector<Tile*>>(
        height,
        std::vector<Tile*>(width, nullptr)
    );
    solution.clear();
    rooms.clear();
    walls.clear();
    visitedRooms.clear();
    generate();
}

std::map<Direction, Room*> Maze::getNeighborRooms(Room* room) {
    int x = room->getCoords().getX();
    int y = room->getCoords().getY();
    std::map<Direction, Room*> neighbors;

    if (getRoomAt(x, y - 2) != nullptr) {
        neighbors[Direction::NORTH] = getRoomAt(x, y - 2);
    }

    if (getRoomAt(x, y + 2) != nullptr) {
        neighbors[Direction::SOUTH] = getRoomAt(x, y + 2);
    }

    if (getRoomAt(x - 2, y) != nullptr) {
        neighbors[Direction::WEST] = getRoomAt(x - 2, y);
    }

    if (getRoomAt(x + 2, y) != nullptr) {
        neighbors[Direction::EAST] = getRoomAt(x + 2, y);
    }

    return neighbors;
}

Room* Maze::getRoomAt(int x, int y) {
    for (Room* room : rooms) {
        if (room->getCoords().getX() == x && room->getCoords().getY() == y) {
            return room;
        }
    }

    return nullptr;
}

Tile* Maze::getTileAt(Coordinate coords)
{
    if (coords.getX() < 0 || coords.getX() >= width) {
        return nullptr;
    }

    if (coords.getY() < 0 || coords.getY() >= height) {
        return nullptr;
    }

    return tiles[coords.getY()][coords.getX()];
}

void Maze::draw(sf::RenderWindow* window) {
    Room* start = !rooms.empty() ? rooms.at(0) : nullptr;
    Room* end = !rooms.empty() ? rooms.at(rooms.size() - 1) : nullptr;

    if (!initialized) {
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Tile* tile = tiles[y][x];
            bool wasNull = false;

            if (tile == nullptr) {
                wasNull = true;
                tile = new Wall(Coordinate(x, y));
            }

            Coordinate coords = tile->getCoords();
            sf::RectangleShape rect(sf::Vector2f(18, 18));
            
            if (wasNull) {
                rect.setFillColor(sf::Color::Red);
            } else if (Utils::instanceof<Wall>(tile)) {
                rect.setFillColor(sf::Color::Black);
            } else if (Utils::instanceof<Door>(tile)) {
                rect.setFillColor(highlightDoors ? sf::Color(0x45aaf2ff) : sf::Color::White);
            } else if (Utils::instanceof<Room>(tile)) {
                rect.setFillColor(highlightRooms ? sf::Color(0xF97F51ff) : sf::Color::White);
            } else {
                rect.setFillColor(sf::Color::White);
            }

            if (highlightWalls && Utils::instanceof<Wall>(tile)) {
                rect.setFillColor(sf::Color(64, 64, 122));
            }

            if (((x + 1) % 2 != 0 && (y + 1) % 2 != 0) && highlightPillars && Utils::instanceof<Wall>(tile)) {
                rect.setFillColor(sf::Color(0x576574ff));
            }

            rect.setPosition(sf::Vector2f((coords.getX() * 18), (coords.getY() * 18)));
            window->draw(rect);
        }
    }

    if (showSolution) {
        for (auto node : solution) {
            sf::RectangleShape rect;
            rect.setFillColor(sf::Color(0x1dd1a1ff));
            rect.setPosition(sf::Vector2f((node->getCoords().getX() * 18 + 4.5F), (node->getCoords().getY() * 18 + 4.5F)));
            rect.setSize(sf::Vector2f(9.f, 9.f));
            window->draw(rect);
        }
    }

    if (start != nullptr && end != nullptr) {
        sf::RectangleShape rect;
        rect.setFillColor(sf::Color(0x487eb0ff));
        rect.setPosition(sf::Vector2f(start->getCoords().getX() * 18, start->getCoords().getY() * 18));
        rect.setSize(sf::Vector2f(18.f, 18.f));
        window->draw(rect);

        sf::RectangleShape rect2;
        rect2.setFillColor(sf::Color(0x16a085ff));
        rect2.setPosition(sf::Vector2f(end->getCoords().getX() * 18, end->getCoords().getY() * 18));
        rect2.setSize(sf::Vector2f(18.f, 18.f));
        window->draw(rect2);
    }
}

void Maze::handleKeyPressed(sf::Keyboard::Key key)
{
    if (key == sf::Keyboard::R) {
        highlightRooms = !highlightRooms;
    }
    
    if (key == sf::Keyboard::W) {
        highlightWalls = !highlightWalls;
    }
    
    if (key == sf::Keyboard::P) {
        highlightPillars = !highlightPillars;
    }

    if (key == sf::Keyboard::D) {
        highlightDoors = !highlightDoors;
    }

    if (key == sf::Keyboard::G) {
        regenerate();
    }

    if (key == sf::Keyboard::Return) {
        if (!solution.empty()) {
            showSolution = !showSolution;
        } else {
            solution = path->find(rooms.at(0), rooms.at(rooms.size() - 1));
        }
    }
}

Path* Maze::getPath()
{
    return path;
}

std::vector<Room*>& Maze::getRooms()
{
    return rooms;
}

std::vector<std::vector<Tile*>>& Maze::getTiles()
{
    return tiles;
}

int Maze::getWidth()
{
    return width;
}

int Maze::getHeight()
{
    return height;
}
