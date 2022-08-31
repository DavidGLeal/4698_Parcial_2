#include <iostream>
#include <string.h>
#include <string>
#include<conio.h>
using namespace std;
// Clase NodoProducto
class NodoProducto {
public:
	int    Codigo;
	int    Precio;
	string Descripcion;
	// Prototipos
	NodoProducto();
	NodoProducto(int cod, int pres, string des);};
// Constructor
NodoProducto::NodoProducto() {
	Codigo = 0;
	Precio = 0;
	Descripcion = "";
}
// Constructor
NodoProducto::NodoProducto(int cod, int pres, string des) {
	Codigo = cod;
	Precio = pres;
	Descripcion = des;
}

class NodoBmas {
public:
	NodoProducto claves[5];
	NodoBmas     *ramas[5];
	NodoBmas     *shojas;
	int cuentas;
	// Prototipos
	NodoBmas();
};
// Costructor
NodoBmas::NodoBmas() {
	cuentas = 0;
}

class ArbolBmas {
public:
	NodoBmas *raiz, *Xr, *P, *N, *vsam;
	int k, cuentas, MAX, MIN, nivel;
	NodoProducto mediana;
	bool esta, ea;
	double contT, contTot;
	int eli;
	int arreglo[50];
	//bandera es del archivo maestro, y bandera2
	int bandera, bandera2;
	//Prototipos
	ArbolBmas() {
		cuentas = k = 0;
		esta = ea = false;
		MAX = 4;
		MIN = 2;
		nivel = 0;
		vsam = raiz = P = N = Xr = NULL;
		contT = contTot = bandera = bandera2 = eli = 0;}
	void refrescar();
	void insertar(NodoProducto);
	void empujar(NodoProducto, NodoBmas *);
	void meterHoja();
	bool arbolVacio(NodoBmas *);
	void dividir();
	void doblar(NodoBmas *);
	//imprime el arbol en orden por la referencia de la raiz
	void print_rec();
	void print_rec_aux(NodoBmas *nodo);//auxiliar
	bool buscarNodo(NodoProducto clave, NodoBmas *nodo);
	bool buscar(NodoProducto clave, NodoBmas *nodo);
	//busca si una clace existe o no en el arbol
	bool buscar(NodoProducto clave);
	//da la altura
	int  Altura();
	//imprime en anchura
	void Anchura();
	void Anchura_aux(NodoBmas *, int, int);
	//imprime por niveles auxiliar de anchura aux
	void ImprimeNivel(NodoBmas *, int);
	//imprime por la referencia de orden
	void Imprimir();
	//carga el archivo de productos
	void Cargar();
	/***********  Recorridos **************************/
	void postOrdenRecursivo(NodoBmas *r);
	void postOrdenIterativo(NodoBmas *r);
	void preOrdenRecursivo(NodoBmas *r);
	void preOrdenIterativo(NodoBmas *r);
	void postOrdenRecursivoAux(NodoBmas *r);
	void postOrdenIterativoAux(NodoBmas *r);
	void preOrdenRecursivoAux(NodoBmas *r);
	void preOrdenIterativoAux(NodoBmas *r);
	//bool buscarNodo (int clave, NodoBmas *pagina);
	bool Buscar(int clave);
	//elimina al archivo
	void Eliminar(int);
	//ve si c esta en el archivo
	int Esta(int c);
	NodoProducto* Encontrar(int c);
	bool EstaArreglo(int num);
	void ImprimirArreglo();};

void ArbolBmas::refrescar() {
	nivel = Altura();
	NodoBmas *aux = raiz;
	while (!arbolVacio(aux->ramas[0]))
		aux = aux->ramas[0];
	vsam = aux;}
// Metodo de Insertar
void ArbolBmas::insertar(NodoProducto clave) {
	ea = false;
	empujar(clave, raiz);
	if (ea) {
		NodoBmas *nuevo = new NodoBmas();
		nuevo->cuentas = 1;
		nuevo->claves[1] = mediana;
		nuevo->ramas[0] = raiz;
		nuevo->ramas[1] = Xr;
		raiz = nuevo;}
	refrescar();}
// Metodo Empujar
void ArbolBmas::empujar(NodoProducto clave, NodoBmas *nodo) {
	if (nodo == NULL) {
		ea = true;
		mediana = clave;
		Xr = NULL;}
	else {
		esta = buscarNodo(clave, nodo);
		if (esta)
			cout << "\nCodigo Repetido: " << clave.Codigo << endl;
		else {
			empujar(clave, nodo->ramas[k]);
			buscarNodo(clave, nodo);
			if (ea) {
				if (nodo->cuentas < MAX) {
					//cout << "Voy a insertar hoja!" <<endl;
					ea = false;
					P = nodo;
					// Usa las variables globales
					meterHoja();}
				else {
					//cout << "Voy a dividir arbol !" << endl;
					ea = true;
					P = nodo;
					// Usa las variables globales.
					dividir();}}}}}
// Metodo Meter Hoja que usa las variables globales: Mediana, P, K, Xr
void ArbolBmas::meterHoja() {
	for (int i = P->cuentas; i >= k + 1; i--) {
		P->claves[i + 1] = P->claves[i];
		P->ramas[i + 1] = P->ramas[i];
	}
	P->claves[k + 1] = mediana;
	P->ramas[k + 1] = Xr;
	P->cuentas++;
}
// Metodo Dividir Nodo que usa las variables asignadas por Meter Hoja Mediana, P, K, Xr.
void ArbolBmas::dividir() {
	NodoBmas *mde = new NodoBmas();
	int pos;

	if (k <= MIN)
		pos = MIN;
	else
		pos = MIN + 1;

	for (int i = pos + 1; i <= MAX; i++) {
		mde->claves[i - pos] = P->claves[i];
		mde->ramas[i - pos] = P->ramas[i];
	}

	mde->cuentas = MAX - pos;
	P->cuentas = pos;

	if (k <= MIN)
		meterHoja();
	else {
		k = k - pos;
		NodoBmas *aux = P;
		P = mde;
		meterHoja();
		P = aux;
	}
	mediana = P->claves[P->cuentas];

	if (arbolVacio(P->ramas[0]))
		doblar(mde);

	mde->ramas[0] = P->ramas[P->cuentas];
	mde->shojas = P->shojas;
	P->shojas = mde;

	P->cuentas--;
	Xr = mde;
}
// Metodo que duplica un Nodo
void ArbolBmas::doblar(NodoBmas *mde) {
	for (int i = mde->cuentas; i >= 1; i--) {
		mde->claves[i + 1] = mde->claves[i];
		mde->ramas[i + 1] = mde->ramas[i];
	}
	mde->claves[1] = mediana;
	mde->cuentas++;
}
// Metodo Arbol Vacio
bool ArbolBmas::arbolVacio(NodoBmas *nodo) {
	return ((nodo == NULL) || (nodo->cuentas == 0));
}

// Metodo buscar que retorna si el nodo existe o no
bool ArbolBmas::buscar(NodoProducto clave) {
	return buscarNodo(clave, raiz);
}
// Metodo buscar que retorna si el nodo existe o no
bool ArbolBmas::buscar(NodoProducto clave, NodoBmas *nodo) {
	if (nodo->cuentas == 0)
		esta = false;
	else {
		buscarNodo(clave, nodo);
		if (esta)
			N = nodo;
		else
			esta = buscar(clave, nodo->ramas[k]);
	}
	return esta;
}
// Metodo buscar nodo
bool ArbolBmas::buscarNodo(NodoProducto clave, NodoBmas *nodo) {
	if (nodo == NULL)
		return false;
	else {
		if (clave.Codigo < nodo->claves[1].Codigo) {
			k = 0;
			return esta = false;
		}
		else {
			k = nodo->cuentas;
			while ((k > 1) && (clave.Codigo <nodo->claves[k].Codigo))
				k--;

			esta = (clave.Codigo == nodo->claves[k].Codigo);
		}
		return esta;
	}
}
// Realiza un Imprimir Recursivo
void ArbolBmas::print_rec() {
	if (!arbolVacio(raiz)) {
		print_rec_aux(raiz);
		cout << endl;
	}
	else
		cout << "\nEl Arbol B+ esta Vacio!" << endl;
}
// Metodo auxiliar de print_rec
void ArbolBmas::print_rec_aux(NodoBmas *nodo) {
	
if (!arbolVacio(nodo)) {
		print_rec_aux(nodo->ramas[0]);
		for (int i = 1; i <= nodo->cuentas; i++) {
			cout << nodo->claves[i].Codigo << " ";
			print_rec_aux(nodo->ramas[i]);
		}
	}
}
// Metodo que retorna la Altura del arbol B+
int ArbolBmas::Altura() {
	int res = 0;
	NodoBmas *aux = raiz;
	if (arbolVacio(aux)) {
		cout << "\nEl Arbol B+ esta Vacio!" << endl;
		return 0;
	}
	else {
		while (!arbolVacio(aux)) {
			res++;
			aux = aux->ramas[0];
		}
		return res;
	}
}
// Realiza el recorrido en Anchura
void ArbolBmas::Anchura() {
	int largo = Altura();
	int con = 1;
	NodoBmas *pg = raiz;
	cout << "Impresion del arbol B+ en anchura:" << endl;
	Anchura_aux(pg, largo, con);
	cout << endl;
}
// Metodo auxiliar de Anchura
void ArbolBmas::Anchura_aux(NodoBmas *nodo, int largo, int con) {
	if (arbolVacio(nodo)) {
	}
	else {
		if (largo >= con) {
			ImprimeNivel(nodo, con);
			con++;
			Anchura_aux(nodo, largo, con);
		}
	}
}

void ArbolBmas::ImprimeNivel(NodoBmas *nodo, int con) {
	if (arbolVacio(nodo)) {
	}
	else {
		if (con == 1) {
			for (int i = 1; i <= nodo->cuentas; i++) {
				cout << nodo->claves[i].Codigo << " ";
			}
		}
		else {
			con--;
			for (int r = 0; r <= nodo->cuentas; r++)
				ImprimeNivel(nodo->ramas[r], con);
		}
	}
}

// Metodo Imprimir Arbol B+
void ArbolBmas::Imprimir() {
	NodoBmas *aux = vsam;
	if (arbolVacio(aux))
		cout << "\nEl Arbol B+ esta Vacio!" << endl;
	else {
		cout << "Impresion del arbol B+:" << endl;
		while (!arbolVacio(aux)) {
			for (int i = 1; i <= aux->cuentas; i++)
				cout << aux->claves[i].Codigo << " ";
			aux = aux->shojas;
		}
	}
	cout << endl;
}
/****************************/
bool ArbolBmas::Buscar(int c) {
	int i;

	NodoBmas *nodo = vsam;
	while (nodo != NULL) {
		i = 0;

		for (; i <= (nodo->cuentas); i++) {
			if (nodo->claves[i].Codigo == c) {
				return  true;
			}
		}
		nodo = (*nodo).shojas;
	}
	return false;
}
//ve si el el codigo c existe
int ArbolBmas::Esta(int c) {
	int i;
	NodoBmas *nodo = vsam;
	while (nodo != NULL) {
		i = 0;
		for (; i <= ((nodo->cuentas) - 1); i++) {
			if (nodo->claves[i].Codigo == c)
				return  true;
		}
		nodo = (*nodo).shojas;
	}
	return false;
}
//encuentra y retorna el nodo buscado
NodoProducto* ArbolBmas::Encontrar(int c) {
	int i;
	NodoBmas *nodo = vsam;
	NodoProducto *siesta;
	while (nodo != NULL) {
		i = 0;

		for (; i <= (nodo->cuentas); i++) {
			if (nodo->claves[i].Codigo == c) {
				siesta = new NodoProducto(nodo->claves[i].Codigo,
					nodo->claves[i].Precio, nodo->claves[i].Descripcion);/////ojo
				return  siesta;
			}
		}
		nodo = (*nodo).shojas;
	}
	return NULL;
}

void ArbolBmas::preOrdenRecursivo(NodoBmas *raiz) {
	preOrdenRecursivoAux(raiz);
}
/* Realiza un recorrido del arbol de forma iterativa */
void ArbolBmas::preOrdenRecursivoAux(NodoBmas *raiz) {
	NodoBmas *pg = raiz;
	if (raiz != NULL) {
		cout << pg->claves[1].Codigo << " ";
		// llamada recursiva por la primera hoja
		this->preOrdenRecursivoAux(pg->ramas[0]);
		if (pg->ramas[0] != NULL) {
			// llamada recursiva por la primera hoja
			this->preOrdenRecursivoAux(pg->ramas[1]);
		}
		for (int i = 2; i <= pg->cuentas; i++) {

			cout << pg->claves[i].Codigo << " ";
			this->preOrdenRecursivoAux(pg->ramas[i]);
		}
	}
}

//fstream file7("PostOrRecBmas.txt", ios::out); //archivo salida de recorrido

void ArbolBmas::postOrdenRecursivo(NodoBmas *raiz) {
	postOrdenRecursivoAux(raiz);
}
/* Realiza un recorrido del arbol de forma recursiva */
void ArbolBmas::postOrdenRecursivoAux(NodoBmas *raiz) {

	NodoBmas *pg = raiz;

	if (raiz != NULL) {

		// llamada recursiva por la primera hoja
		this->postOrdenRecursivoAux(pg->ramas[0]);

		if (pg->ramas[0] != NULL) {
			// llamada recursiva por la primera hoja
			this->postOrdenRecursivoAux(pg->ramas[1]);
		}

		cout << pg->claves[1].Codigo << " ";

		for (int i = 2; i <= pg->cuentas; i++) {
			this->postOrdenRecursivoAux(pg->ramas[i]);
			cout << pg->claves[i].Codigo << " ";
		}
	}
}
/**************************************************************/
void ArbolBmas::preOrdenIterativo(NodoBmas *raiz) {
	preOrdenIterativoAux(raiz);
}
/* Realiza un recorrido del arbol de forma iterativo */
void ArbolBmas::preOrdenIterativoAux(NodoBmas *raiz) {
	NodoBmas *pg = raiz;
	if (raiz != NULL) {
		cout << pg->claves[1].Codigo << " ";
		// llamada recursiva por la primera hoja
		this->preOrdenIterativoAux(pg->ramas[0]);
		if (pg->ramas[0] != NULL) {
			// llamada recursiva por la primera hoja
			this->preOrdenIterativoAux(pg->ramas[1]);}
		for (int i = 2; i <= pg->cuentas; i++) {
			cout << pg->claves[i].Codigo << " ";
			this->preOrdenIterativoAux(pg->ramas[i]); }}}
//fstream file9("PostOrIteBmas.txt", ios::out); //archivo salida de recorrido
void ArbolBmas::postOrdenIterativo(NodoBmas *raiz) {
	postOrdenIterativoAux(raiz);
}
/* Realiza un recorrido del arbol de forma iterativo */
void ArbolBmas::postOrdenIterativoAux(NodoBmas *raiz) {
	NodoBmas *pg = raiz;

	if (raiz != NULL) {

		// llamada recursiva por la primera hoja
		this->postOrdenIterativoAux(pg->ramas[0]);

		if (pg->ramas[0] != NULL) {
			// llamada recursiva por la primera hoja
			this->postOrdenIterativoAux(pg->ramas[1]);
		}

		cout << pg->claves[1].Codigo << " ";

		for (int i = 2; i <= pg->cuentas; i++) {
			this->postOrdenIterativoAux(pg->ramas[i]);
			cout << pg->claves[i].Codigo << " ";
		}
	}
}

int main() {
	ArbolBmas H;
	NodoProducto temp;
	int i = 0;
	while (i<60) {
		temp.Codigo = i;
		temp.Descripcion = "opcion" + i;
		temp.Precio = i * 2;
		H.insertar(temp);
		i++;}
	cout << endl;
	H.Anchura();
	cout << endl;
	H.Imprimir();
	cout << endl;
	cout << "La altura del arbol b+ es: " << H.Altura() << endl;
	cout << endl;
	_getch();}
//Fin clase arbol B+
