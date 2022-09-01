#include "..\source\Snake.hpp"
#include <windows.h>

void constructors() {
    Snake snake{ Position{5, 10} };
    snake.render();
}

void movement() {
    Snake snake{ Position{4, 2} };
    snake.render();

    for (int i{}; i < 20; ++i) {
        snake.move(Movement::right);
        Sleep(500);
    }
}

void eating() {
    Snake snake{ Position{5, 2} };
    snake.render();

    for (int i{}; i < 40; ++i) {
        snake.move(Movement::down);
        if (i % 5 == 0)
            snake.eat();

        Sleep(500);
    }
}

int main() {
    system("cls");
    // constructors();
    // movement();
    eating();

    return 0;
}