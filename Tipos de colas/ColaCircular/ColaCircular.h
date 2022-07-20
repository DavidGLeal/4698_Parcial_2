
class ColaCircular{
	//Atributos de la clase
	private:
		int *colaC;	//Cualquier tipo de dato
		int inicio;
		int ultimo;
		int tamanio;
	//Metodos de la clase
	public:
		ColaCircular();
		void insertar(int);
		void eliminar();
		void imprimir();
};