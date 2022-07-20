#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "ListaCircularDoble.h"
using namespace std;
int main() {
    CircularList clist("Hola");

    clist.insertarNodopoCabeza("Hi");
    clist.insertNodoFinal("Konichiwa");

    clist.printNodes();
    cout << " ----------------------------------- " << endl;

    clist.insertarNodopoCabeza("Salut");
    clist.printNodes();

    return EXIT_SUCCESS;
}