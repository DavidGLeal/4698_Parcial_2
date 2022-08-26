#pragma once
#ifndef CTABLA_H
#define CTABLA_H

#include "Header.h"
#include "CPieza.h"
#include "CPieza_Hijas.h"

using namespace std;

const unsigned int X = 8;
const unsigned int Y = 8;

class CTabla {
private:
    unsigned int tamX;
    unsigned int tamY;
    unsigned int numPiezas;
    CPieza** listaPiezas;
public:
    CTabla();
    ~CTabla();
    void imprimirTabla();
};

#endif
