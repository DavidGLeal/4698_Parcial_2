#pragma once
#ifndef CPIEZA_HIJAS_H
#define CPIEZA_HIJAS_H

#include "Header.h"
#include "CPieza.h"

class CPeon: public CPieza {
public:
    CPeon();
    CPeon(int y, int x, char c);
    ~CPeon() override = default;
};


class CTorre: public CPieza {
public:
    CTorre();
    CTorre(int y, int x, char c);
    ~CTorre() override = default;
};



class CCaballo: public CPieza {
public:
    CCaballo();
    CCaballo(int y, int x, char c);
    ~CCaballo() override = default;
};



class CAlfil: public CPieza {
public:
    CAlfil();
    CAlfil(int y, int x, char c);
    ~CAlfil() override = default;
};



class CReina: public CPieza {
public:
    CReina();
    CReina(int y, int x, char c);
    ~CReina() override = default;
};



class CRey: public CPieza {
public:
    CRey();
    CRey(int y, int x, char c);
    ~CRey();
};

#endif