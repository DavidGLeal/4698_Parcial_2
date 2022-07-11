
/*
	*Universidad de las Fuerzas Armadas "ESPE"
        *Enunciado del problema:
	*Realizar un pograma de manejo de árboles binarios con todas sus funciones.
        *Autores:
	*Curso de Estructura de Datos NRC: 4698
	*Fecha de creacion: 
        * 04-07-2022
	*Fecha de modificacion:
        * 08-07-2022
        *GitHub del grupo:	
        *https://github.com/DavidGLeal/4698_Parcial_2
*/

#pragma once
#include "Nodo.cpp"

class Arbol
{
private:
    Nodo *arbol = NULL;
    void imprimirNivelActual(Nodo *, int); //Metodo para que funcione el recorrido por nivel
public:
    void setArbol(Nodo *);
    Nodo *getArbol();
    Nodo *crearNodo(int);
    void insertarNodo(Nodo *&, int);
    void mostrar(Nodo *, int);
    void buscar(Nodo *, int);
    void buscarporNivel(Nodo *, int);
    void preOrden(Nodo *);
    void inOrden(Nodo *);
    void recorridoNivel(Nodo *);
    void postOrden(Nodo *);
    int peso(Nodo *);
    int altura(Nodo *);
    bool simetria(Nodo *, Nodo *);
    bool simetrias(Nodo *);
    Nodo *eliminarNodo(Nodo *, int);
};
