#include"Nodo.cpp"

class Bicola
{
public:
	//Metodos de la clase bicola
 	 Bicola();
	 void ponerFinal(int elemento);
	 void ponerFrente(int elemento);
	 int quitarFrente();
	 int quitarFinal();
	 void mostrarBicola();
 
 private:
 	//Apuntadores frente y final
 	Nodo* frente;
 	Nodo* final;
};