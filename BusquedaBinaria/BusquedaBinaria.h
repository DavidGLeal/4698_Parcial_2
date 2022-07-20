/*Universidad de las Fuerzas Armadas ESPE
  Enunciado: Dado el siguiente problema utilizando proceso racional resolver el siguiente problema 
  Autores: 
  Adriana Diaz
  Johanna Pila
  Fecha de creación: 17/07/2022
  Fecha de modificación: 17/07/2022
  Github: https://github.com/AdrianaDiazB/Grupo3-EstructuraDeDatos-4698/tree/main/Evidencia%20Grupo%2014/PARCIAL%20I/Deber%201
*/
#pragma once
#include <iostream>
#define MAX 50

class BusquedaBinaria{
public:
    //lee el array de numeros
    void leerArray(int n,int x[]);
    //Lista el array ingresado
    void Listado(int n,int x[]);
    //Metodo de ordenacion
    void Burbuja(int n,int x[]);
    //Metodo de busqueda de binaria
    int bBinaria(int n,int x[],int t);
};