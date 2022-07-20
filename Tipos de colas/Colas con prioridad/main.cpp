
#include <iostream>
#include <stdlib.h>
#include"ColaPrioridad.cpp"
using namespace std;

int main()
{
	//Creamos nuestro objeto ColaPrioridad
    ColaPrioridad cola;
    //Insertamos elementos con diferente prioridad
    cola.insertar(2,3);
    cola.insertar(8,4);
    cola.insertar(7,1);
    cola.insertar(5,5);
    //Mostramos los elementos en cola
    cola.mostrar();
    //Eliminamos un elemento
    cout<<endl;
    cout<<"Dato eliminado: "<<cola.eliminar();
    cout<<endl;
    //Mostramos los elementos en cola
    cola.mostrar();
    return 0;
}