#include <iostream>
#include "0Vector.cpp"
#include "6ImprimirInterno.cpp"
#include "2OrdenamientoInterno.cpp"
using namespace std;
   

int main(){

    Vector v;
    v.push_back(12);
    v.push_back(4);
    v.push_back(7);
    v.push_back(47);
    v.push_back(2);
    v.push_back(3);
    v.push_back(-98);
    v.push_back(-28378);
    v.push_back(74);
    v.push_back(123);


    OrdenamientoInterno *a = new OrdenamientoInterno(v);

    a->imprimirInterno();
    a->ordenarRadix();
    a->imprimirInterno();

    return 0;
}
