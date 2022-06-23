#include <iostream>
#include "ImprimirExterno.h"
using namespace std;
#pragma once
   
class MetodosExternos: public ImprimirExterno{

    private:
        string nombreArchivo{"ordenada.txt"}; //Por default

        //!ORDENACION NATURAL. METODOS INTERNOS


        void generarAleatorios(int min, int max);
    
        void abrir(fstream *f, string nom, int tip);
        void insertar(int d, string nom);
        void cerrar(fstream *f);
        void limpiar();

        void particionInicial();
        void particionFusion();
        void intercalacionDeArchivo(string nom1, string nom2, string nom3, string nom4);

        //!ORDENACION DIRECTA. METODOS INTERNOS

    public:
        MetodosExternos(string);
        ~MetodosExternos();
        
        void ordenarPorDirecta();

        //!ORDENACION NATURAL.
        void ordenarPorNatural();
    
};