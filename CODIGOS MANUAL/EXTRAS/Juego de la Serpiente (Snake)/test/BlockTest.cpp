#include "..\source\Block.hpp"
#include <iostream>

void constructor() {
    Block blockA{};
    Block blockB{ Position{5, 20} };
    Block blockC{ {10, 5} };

    blockA.render();
    blockB.render();
    blockC.render();
}

int main() {
    system("cls");
    constructor();

    return 0;
}