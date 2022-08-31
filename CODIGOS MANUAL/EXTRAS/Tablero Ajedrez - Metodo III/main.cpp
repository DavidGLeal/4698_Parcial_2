#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Tablero de ajedrez");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    std::vector<std::vector<sf::RectangleShape*>> cuadros(
        8,
        std::vector<sf::RectangleShape*>(8)
    );

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cuadros.at(i).at(j) = new sf::RectangleShape;
        }
    }

    int row = 0;

    for (std::vector<sf::RectangleShape*> fila : cuadros) {
        int col = 0;

        for (sf::RectangleShape*& cuadro : fila) {
            if (row % 2 == 0) {
                if (col % 2 == 0) {
                    cuadro->setFillColor(sf::Color::White);
                }
                else {
                    cuadro->setFillColor(sf::Color::Black);
                }
            } else {
                if (col % 2 == 0) {
                    cuadro->setFillColor(sf::Color::Black);
                }
                else {
                    cuadro->setFillColor(sf::Color::White);
                }
            }

            cuadro->setSize(sf::Vector2f(100.f, 100.f));
            cuadro->setPosition(col * 100, row * 100);
            col++;
        }

        row++;
    }


    while (window.isOpen())
    {
        sf::RectangleShape cuadro;
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (std::vector<sf::RectangleShape*> fila : cuadros) {
            for (sf::RectangleShape* cuadro : fila) {
                window.draw(*cuadro);
            }
        }

        window.display();
    }

    return 0;
}