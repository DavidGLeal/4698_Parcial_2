public:
	Nodo *inicio;
	Nodo *ultimo;
	int tamanio;
private:
	void Lista();
	boolean esVacia();
	int getTamanio();
	void agregarAlFinal(int valor);
	void agregarAlInicio(int valor) :
		int getValor(int posicion);
	boolean buscar(int referencia);
	int getPosicion(int referencia);
	void removerPorReferencia(int referencia);
	void removerPorPosicion(int posicion);
	void eliminar();
	void listar();
