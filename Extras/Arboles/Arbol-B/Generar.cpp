
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <complex>
#include <cmath>
#include "pdf.cpp"
#include "metrics.cpp"
#include "Generar.h"

using std::complex;
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::ostringstream;

Generar::Generar()
{
}

Generar::~Generar()
{
}

void Generar::generarPDF(string nombre)
{
    
    PDF p;
    p.setFont(PDF::HELVETICA_BOLD,30);
	p.showTextXY("ARBOL B",230,746);  
    p.setFont(PDF::HELVETICA, 12);
    p.showTextXY("NUMEROS INGRESADOS:",50,546);
    string linea, texto;
    int x=50;
    ifstream original("prueba.txt");
    while (getline(original, linea))
    {
        p.showTextXY(linea,x,516);
        x+=50;
    }
    original.close();
	string errMsg;

    if (!p.writeToFile(nombre, errMsg))
    {
        cout << errMsg << endl;
    }
    else
    {
        cout << "(File Successfully Written)" << endl;
    }

    cout << endl;
}