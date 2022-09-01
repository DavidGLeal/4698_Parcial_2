#include <iostream>
#include "BusquedaBinaria.cpp"
 
using namespace std;
 
int main() {
	BusquedaBinaria busqueda;
	int n, x[MAX], t, pos;
	cout << "Nro de elementos: "; cin >> n;
	busqueda.leerArray(n, x);
	busqueda.Burbuja(n, x);
	busqueda.listado(n, x);
	cout << "Elemeto a buscar: "; cin >> t;
	pos = busqueda.bBinaria(n, x, t);
	if (pos == -1) cout << "No se encuentra " << endl;
	else cout << "los encontre en la posicion: " << pos + 1 << endl;
	return 0;
}
