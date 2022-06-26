#pragma once
#include <iostream>
#include "5ImprimirExterno.cpp"
using namespace std;
   
class MetodoExterno: public ImprimirExterno{

    private:
        string nombreArchivo{"ordenada.txt"}; //Por default
        int N{0};

        //!METODOS DE AMBAS FUNCIONES

        void abrir(fstream *f, string nom, int tip);
        void cerrar(fstream *f);

        //!ORDENACION NATURAL. METODOS INTERNOS


        void generarAleatorios(int min, int max);
        void particionInicial();
        void particionFusion();
        void limpiar();
        void intercalacionDeArchivo(string nom1, string nom2, string nom3, string nom4);

        //!ORDENACION DIRECTA. METODOS INTERNOS

        void particiona(int l);
        void fusiona(int l);


    public:
    
        MetodoExterno(string);
        ~MetodoExterno();
        MetodoExterno();
        
        //!ORDENACION DIRECTA
        void ordenarPorDirecta();
        void insertar(int d, string nom);

        //!ORDENACION NATURAL.
        void ordenarPorNatural();
        bool hayDatos();
        void limpiarArchivo();
        void insertar2(int d, string nom);
        void setN(int n);

};