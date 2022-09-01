#include <iostream>
 
using namespace std;
 
// Estructura de Datos que representa un nodo en el árbol
class Nodo
{
public:
    int dato;        // Almacena el valor
    Nodo *padre;     // Puntero al Padre
    Nodo *izquierdo; // Puntero al Hijo Izquierdo
    Nodo *derecho;   // Puntero al Hijo Derecho
    int color;       // 1 -> Rojo, 0 -> Negro
    friend class ArbolRN;
};

typedef Nodo *NodoPtr;
