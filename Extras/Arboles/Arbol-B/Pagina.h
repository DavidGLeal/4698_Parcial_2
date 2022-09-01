
using namespace std;
#include <iostream>
#include <cctype>
#pragma once
enum EsMenor{SI,NO};
enum Donde{VACIO,PRINCIPIO,ENMEDIO,FINAL};

class Casilla2;

class Pagina;

// representa la casilla que va en cada una de las listas de cada pagina
class Casilla{
	public:
	int valor; // el numero que se guarda en cada casilla
	Pagina *hizq,*hder; // sus hijos los cuales son paginas
	Pagina *actual; // es la pagina en la que se encuentra
	Casilla *siguiente,*anterior; // el siguiente y el anterior de la casilla en
	// la lista de la pagina
	Casilla2 *direccionLista; // es la direccion a la lista, la cual esta 
	//ordenada en el arbol b
};

class Pagina{
	
	int nivel;// el nivel en el que se encuentra la pagina
	int n; // maximo de casillas que caben en una pagina
	// punteros a las casilla importantes de cada lista
	Casilla *principio,*final,*anterior,*mitad,*lugarEncontrado; 
 	Pagina *padre; // padre de la casilla, apunta a la pagina padre
 	Casilla *padreCasilla; // padre casilla de la pagina
	int cuantos; // el numero de casillas en la pagina
	Donde donde; // la localizacion de la casilla a la que se busca
	EsMenor esMenor; // se usa para saber si el valor agregado es menor o mayor 
	//que la mitad
	int menores,mayoresOiguales; // 'menores' son la cantidad de casillas antes 
	//de la mitad y 'mayoresOiguales' son la cantidad de casilla que son mayores
	// que la mitad y la mitad misma  
	
public:
	
	Pagina(int orden); // constructor de la pagina
	~Pagina(); // destructor de la pagina 
	void terminar(); // copia del destructor
	bool buscar(int a); // se usa para buscar en la lists
	Pagina* buscar2(int a); // se usa para buscar en el arbol
	bool agregar(int a); // se usa para agregar un numero a la lista
	void agregar(Casilla *p); // se usa para agregar una casilla a la lista
	void pintar(); // pinta la lista
	void acomodarHijos(); // acomoda los hijos de cada casilla de la pagina
	void desligar(Casilla *casilla); // desliga una casilla de la pagina
	int obtenerCuantos(); // regresa el numero de casillas de la lista
	Casilla* obtenerLugarEncontrado(); // regresa el lugar encontrado
	Casilla* obtenerMitad(); // regresa la mitad
	Pagina* obtenerPadre(); // regresa la pagina padre
	void ponerPadre(Pagina *padre); // asigna el padre a la pagina		 
	Casilla* obtenerPrincipio(); // regresa el principio
	Casilla* obtenerFinal(); // regresa el final
	Casilla* obtenerPadreCasilla(); // regresa la casilla padre de una pagina
	void ponerPadreCasilla(Casilla *p); // pone la casilla padre de la pagina
	Casilla* obtenerCasillaEnPosicion(Pagina *pag, int pos);
	
	void setNivelPag(int);
	int getNivelPag();
};

