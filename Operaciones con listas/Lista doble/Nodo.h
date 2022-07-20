/*UFA-ESPE
* Deber 6
* Autores: Iza Christopher- Rea Denise
* Fecha de creación 01/06/2022
* Fecha de modificación 02/06/2022
* Grupo 20
* github del grupo @dnrea@espe.edu.ec @cdiza5@espe.edu.ec
*/
#pragma once
class Nodo{
	private:
		int valor;
		Nodo *siguiente;
		Nodo *previo;
	public:
		Nodo();
		Nodo(int, Nodo*,Nodo*);
    	~Nodo();
    	int getValor();
    	void setValor(int);
    	Nodo* getSiguiente();
    	void setSiguiente(Nodo*);
		Nodo* getPrevio();
    	void setPrevio(Nodo*);
	friend class Lista;
};