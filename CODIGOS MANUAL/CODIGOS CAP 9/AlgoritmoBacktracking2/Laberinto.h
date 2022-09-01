/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
INGENIERÍA DE SOFTWARE             
	AUTORES:
        Dylan Hernández
        Andrés Almeida
	Juan Reyes
        Brandon Masacela
        GRUPO: 3
   FECHA DE CREACION:        Domingo, 07 de agosto de 2022 05:42 p.m. 	
   FECHA DE MODIFICACION:    Domingo, 07 de agosto de 2022 11:30 p.m.
 * --------------------------
 * Planteamiento: Resolver un laberinto utilizando Backtracking
 * --------------------------
 * Este programa implementa una solución al Problema de resolver un laberinto
 * utilizando el metodo de Backtracking
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

class Laberinto
{
public:
    int **m;     
    int f, c;    
    int fp, cp;   
    int fs, cs;  
    int ifp, icp; 
    int movs;              
    int espacios;           
    bool pasoApaso = false; 
    int pasosReales;                 
    char ruta[20]; 
    Laberinto();
    void leerArchivo();
    void MuestraLaberinto();
    void dimensionaMatriz();
    bool backtracking(int, int);
    void corre();
};
