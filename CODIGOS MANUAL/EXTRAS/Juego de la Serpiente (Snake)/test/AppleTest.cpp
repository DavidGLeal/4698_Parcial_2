#include "..\source\Apple.hpp"
#include <iostream>

void constructors() {
    Apple appleA{ Position{10, 5} };
    appleA.render();
}

void spawning() {
    Apple appleA{};
    Apple appleB{};

    appleA.spawn({2, 10});
    appleA.spawn({5, 20});
}

int main() {
    system("cls");
    constructors();
    spawning();

    return 0;
}