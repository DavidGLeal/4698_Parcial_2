#include <iostream>
using namespace std;
 
class imprimirDato {
   public:
  	void imprimir(int i) {
    	cout << "Imprime el valor int: " << i << endl;
  	}
  	void imprimir(double  f) {
    	cout << "Imprime el valor float: " << f << endl;
  	}
  	void imprimir(char* c) {
    	cout << "Imprime el caracter: " << c << endl;
  	}
};
 
int main(void) {
   imprimirDato pd;
 
   // Hacemos la llamada para que se imprima el valor int
   pd.imprimir(5);
  
   // Hacemos la llamada para que se imprima el valor float
   pd.imprimir(500.263);
  
   // Hacemos la llamada para que se imprima el caracter
   pd.imprimir("Hola amigos NRC 4698");
 
   return 0;
}
