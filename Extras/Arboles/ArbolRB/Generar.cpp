#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <complex>
#include <cmath>
#include "pdf.cpp"
#include "metrics.cpp"
#pragma once 
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
    p.setFont(PDF::HELVETICA, 12);
    p.showTextXY("UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE",150,750);
    p.showTextXY("ESTRUCTURA DE DATOS",200,700);
    p.showTextXY("Integrantes:",50,650);
    p.showTextXY("Diego Portilla - Darwin Valdiviezo - Danny Quingaluisa - Alejandro Gallegos",150,650);
    p.showTextXY("--DATOS DEL SISTEMA --",200,580);
    string linea, texto;
    int y=50;
    ifstream original("Datos.txt");
    while (getline(original, linea))
    {
        p.showTextXY(linea, y, 550);
        y+=20;
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