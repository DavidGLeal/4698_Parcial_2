/*UFA-ESPE
* Deber 5
* Autores: Iza Christopher- Rea Denise
* Fecha de creación 25/05/2022
* Fecha de modificación 30/05/2022
* Grupo 20
* github del grupo @dnrea@espe.edu.ec @cdiza5@espe.edu.ec
*/
#pragma once
class Nodo{
	private:
		int valor;
		Nodo *siguiente;
	public:
		Nodo(int, Nodo*);
    	~Nodo();
    	int getValor();
    	void setValor(int);
    	Nodo* getSiguiente();
    	void setSiguiente(Nodo*);
	friend class Lista;
};