#include <iostream>
using namespace std;

void func(int *);     // prototipo: argumento definido como puntero-a-int

int main() {        // =============
	int x = NULL;
	int * ptr = &x;
	func(ptr);         // se pasa puntero-a-int como argumento
	cout << "El valor es ahora: " << x << endl;
	system("pause>null");
	return 0;
}

void func(int * p) { // el argumento se define como puntero-a-int
	*p += 10;           // el argumento es tratado como puntero
}
