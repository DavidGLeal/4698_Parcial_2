#include <iostream>
#include "vector.h"
#include "vector.cpp"
#include "OrdenamientoInterno.h"
#include "OrdenamientoInterno.cpp"

using namespace std;

int main() {
    Vector v;
    OrdenamientoInterno oi;
    v.push_back(1);
    v.push_back(9);
    v.push_back(3);
    v.push_back(7);


    oi.ordenarQuicksort(v, 0, v.size() - 1);

    return 0;
}
   
