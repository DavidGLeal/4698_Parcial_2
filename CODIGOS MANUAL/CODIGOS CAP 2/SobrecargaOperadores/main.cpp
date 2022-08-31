#include <iostream>
using namespace std;
 
class Contador {
	private:
	int valor;
 
   public:
 
	// Constructor e inicialización del valor en 5
	Contador() : valor(5) {}
 
	void operator ++ () {
    	++valor;
	}
 
	void imprimir() {
    	cout << "Contador: " << valor << endl;
	}
};
 
int main() {
	Contador Contador1;
 
	// Hacemos un llamado a la función operador
	++Contador1;
 
	Contador1.imprimir();
	return 0;
}

