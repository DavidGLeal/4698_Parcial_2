
class ColaSimple{
	//Atributos de la clase
	private:
		int *cola;	//Cualquier tipo de dato
		int primero;
		int ultimo;
		int tamanio;
	//Metodos de la clase
	public:
		ColaSimple();
		void insertar(int);
		void eliminar();
		void imprimir();
};