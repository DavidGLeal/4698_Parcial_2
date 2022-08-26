#include "MazeGame.h"
#include <math.h>
#include "Windows.h"

MazeGame::MazeGame() {
    int width = 18 * 41;
    int height = 18 * 31;

    maze = new Maze(width / 18, height / 18);
    player = nullptr;
    window = new sf::RenderWindow(sf::VideoMode(width, height), "Estructuras::Laberinto");
}

void MazeGame::initialize() {
    maze->generate();
    player = new Player(sf::Vector2f(18, 18), maze->getRooms().at(0)->getCoords());
    
    while (window->isOpen() && !finished)
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window->close();
            }

            if (event.type == sf::Event::KeyPressed) {
                maze->handleKeyPressed(event.key.code);
                Coordinate nextPosition = player->getPosition();

                if (event.key.code == sf::Keyboard::Up) {
                    nextPosition.transform(0, -1);
                }

                if (event.key.code == sf::Keyboard::Down) {
                    nextPosition.transform(0, 1);
                }

                if (event.key.code == sf::Keyboard::Left) {
                    nextPosition.transform(-1, 0);
                }

                if (event.key.code == sf::Keyboard::Right) {
                    nextPosition.transform(1, 0);
                }

                if (event.key.code == sf::Keyboard::G) {
                    auto start = maze->getRooms().at(0);
                    nextPosition.setX(start->getCoords().getX());
                    nextPosition.setY(start->getCoords().getY());
                }

                if (nextPosition.getX() < 0) {
                    nextPosition.setX(0);
                }

                if (nextPosition.getX() >= maze->getWidth()) {
                    nextPosition.setX(maze->getWidth() - 1);
                }

                if (nextPosition.getY() < 0) {
                    nextPosition.setY(0);
                }

                if (nextPosition.getY() >= maze->getHeight()) {
                    nextPosition.setY(maze->getHeight() - 1);
                }

                auto tile = maze->getTileAt(nextPosition);

                if (!Utils::instanceof<Wall>(tile)) {
                    player->setPosition(nextPosition);
                }
            }
        }

        window->clear(sf::Color::Green);
        maze->draw(window);
        player->draw(window);
        window->display();

        auto end = maze->getRooms().at(maze->getRooms().size() - 1);

        if (player->getPosition().equals(end->getCoords())) {
            MessageBoxA(NULL, "Has llegado a la meta", "Juego Finalizado!", MB_OK);
            window->close();
            finished = true;
        }
    }
}
