#include <conio.h> 
#include <iostream> 
#include <stdlib.h> 
using namespace std; 
struct nodo {
	int info;
	struct nodo *sig;
};
void crear(struct nodo **);
void insertar(struct nodo **, int);
void eliminar(struct nodo **, int);
void recorrer(struct nodo **);
int buscar(struct nodo **, int); //true or false 
int main() {
	struct nodo *ent;
	int dato;
	crear(&ent);
	cout << "Ingrese valores enteros, cero para terminar: ";
	cin >> dato;
	while (dato != 0){
		insertar(&ent, dato);
		cout << "Ingrese valores enteros, cero para terminar: ";
		cin >> dato;}
	recorrer(&ent);
	cout << "Ingrese dato a eliminar: ";
	cin >> dato;
	eliminar(&ent, dato);
	recorrer(&ent);
	cout << "Ingrese dato a buscar: ";
	cin >> dato;
	if (buscar(&ent, dato) == 1)
		cout << "numero " << dato << " encontrado";
	getch();
	getch();
	return 0;
}
/******** funciones de listas simplemente enlazadas *********/
void crear(struct nodo **ent){
	*ent = NULL;}
void insertar(struct nodo **ent, int dato){
	struct nodo *aux, *p, *ant;
	aux = new nodo;
	if (!aux) { cout << "error:memoria insuficiente" << endl; exit(1); }
	aux->info = dato;
	ant = NULL;
	p = *ent; //p es el ptro aux que recorre la lista para insertar ORDENADO 
	while ((p != NULL) && (p->info < dato))
	{
		ant = p;
		p = p->sig;
	}
	if (ant == NULL)
	{
		aux->sig = *ent;
		*ent = aux;
	}
	else
	{
		ant->sig = aux;
		aux->sig = p;}
}
void eliminar(struct nodo **ent, int dato){
	struct nodo *p, *ant;
	p = *ent;
	ant = NULL;
	while ((p != NULL) && (p->info < dato))
		//si pregunto p->info != dato recorro toda la lista sin sentido {
		ant = p;
		p = p->sig;}
	if (p->info != dato) cout << "dato no existe " << endl;
	else{
		if (ant == NULL) //1er nodo 
			*ent = (*ent)->sig;
		else
			ant->sig = p->sig;

		delete p;}
}
void recorrer(struct nodo **ent)
{
	struct nodo *p;
	p = *ent;
	while (p != NULL)
	{
		cout << p->info << endl;
		p = p->sig;
	}
}
int buscar(struct nodo **ent, int dato)
{
	struct nodo *p;
	p = *ent;
	while ((p != NULL) && (p->info < dato)) p = p->sig;
	if (p->info == dato)
		return 1;
	else
		return 0;
}
