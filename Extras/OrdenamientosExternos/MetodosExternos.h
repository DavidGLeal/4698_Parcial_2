#pragma once
#include <iostream>
#include "ImprimirExterno.cpp"
using namespace std;
   
class MetodoExterno: public ImprimirExterno{

    private:
        string nombreArchivo{"ordenada.txt"}; //Por default

        //!METODOS DE AMBAS FUNCIONES

        void abrir(fstream *f, string nom, int tip);
        void cerrar(fstream *f);
        void limpiar();

        //!ORDENACION NATURAL. METODOS INTERNOS


        void generarAleatorios(int min, int max);
        void insertar(int d, string nom);
        void particionInicial();
        void particionFusion();
        void intercalacionDeArchivo(string nom1, string nom2, string nom3, string nom4);

        //!ORDENACION DIRECTA. METODOS INTERNOS

        void particiona(int l);
        void fusiona(int l);
        int N;


    public:
        MetodoExterno(string);
        ~MetodoExterno();
        
        //!ORDENACION DIRECTA
        void ordenarPorDirecta();

        //!ORDENACION NATURAL.
        void ordenarPorNatural();

};