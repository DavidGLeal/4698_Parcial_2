#include"Nodo.cpp"
class ColaPrioridad{
	public: 	
		//Metodos
		ColaPrioridad();
		void insertar(int,int);
		int eliminar();
		void ordenarPrioridad();
		void encolar(int,int);
		void mostrar();
	private:
		//Atributos
		Nodo* primero;
		Nodo* ultimo;
};