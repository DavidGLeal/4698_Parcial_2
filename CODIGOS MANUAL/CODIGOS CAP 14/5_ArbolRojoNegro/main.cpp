#include <iostream>
#include "ArbolRN.h"
 
using namespace std;

int main()
{
    ArbolRN arbol;
    arbol.insert(8);
    arbol.insert(18);
    arbol.insert(5);
    arbol.insert(15);
    arbol.insert(17);
    arbol.insert(25);
    arbol.insert(40);
    arbol.insert(80);
    arbol.borrarNodo(25);
    arbol.imprimirCorregido();
    return 0;
}
