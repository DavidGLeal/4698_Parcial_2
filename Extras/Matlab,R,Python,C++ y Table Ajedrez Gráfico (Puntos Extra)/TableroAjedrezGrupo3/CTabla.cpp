/*
	Universidad de las Fuerzas Armadas "ESPE"
	Deber tablero de ajedrez.
	Arias Sebastián, Escobar David, Portilla Diego, Valdiviezo Darwin, Yánez Michelle
	Fecha de creación: 05/08/2022
	Fecha de modificación: 07/08/2022
	Grupo 8
	https://github.com/EscobarDavid/Grupo3P
*/
#pragma once
#include "CTabla.h"

CTabla::CTabla() : tamX{X},tamY{Y}, numPiezas{32} {
    listaPiezas = new CPieza*[numPiezas];

    // Insertar las torres en la lista
    listaPiezas[0] = new CTorre(0,0,'B');
    listaPiezas[1] = new CTorre(0,7,'B');
    listaPiezas[2] = new CTorre(7,0,'N');
    listaPiezas[3] = new CTorre(7,7,'N');

    // Insertar los caballos en la lista
    listaPiezas[4] = new CCaballo(0,1,'B');
    listaPiezas[5] = new CCaballo(0,6,'B');
    listaPiezas[6] = new CCaballo(7,1,'N');
    listaPiezas[7] = new CCaballo(7,6,'N');

    // Insertar los alfiles en la lista
    listaPiezas[8] = new CAlfil(0,2,'B');
    listaPiezas[9] = new CAlfil(0,5,'B');
    listaPiezas[10] = new CAlfil(7,2,'N');
    listaPiezas[11] = new CAlfil(7,5,'N');

    // Insertar las reinas en la lista
    listaPiezas[12] = new CReina(0,3,'B');
    listaPiezas[13] = new CReina(7,3,'N');

    // Insertar los reyes en la lista
    listaPiezas[14] = new CRey(0,4,'B');
    listaPiezas[15] = new CRey(7,4,'N');

    // Insertar los peones en la lista
    for(int i=0; i<tamX; i++) {
        listaPiezas[16+2*i] = new CPeon(1,i,'B');
        listaPiezas[17+2*i] = new CPeon(6,i,'N');
    }
}

CTabla::~CTabla() {
    for(int i=0; i<numPiezas; i++) {
        delete listaPiezas[i];
        listaPiezas[i] = nullptr;
    }
    delete[] listaPiezas;
}

void CTabla::imprimirTabla() {
    string tabla[tamY][tamX];
    for(int i=0; i<tamY; i++) {for(int j=0; j<tamX; j++) {tabla[i][j] = "";}}

    for(int i=0; i<numPiezas; i++) {
        tabla[listaPiezas[i]->getPosY()][listaPiezas[i]->getPosX()] = listaPiezas[i]->getIcono();
    }

    for(int i=int(tamY)-1; i>=0; i--){
        cout << endl << string(2,' ');
        for(int j=0; j<tamX; j++){
            cout << setfill('-') << setw(5) << left << '.';
        }
        cout << '.' << endl;

        cout << setfill(' ') << setw(2) << left << i+1;
        for(int j=0; j<tamX; j++){
            cout << setfill(' ') << setw(2) << left << '|';
            cout << setfill(' ') << setw(3) << left << tabla[i][j];
        }
        cout << '|';
    }

    cout << endl << string(2,' ');
    for(int i=0; i<tamX; i++){
        cout << setfill('-') << setw(5) << left << '.';
    }
    cout << '.';
    //  - Linea de letras
    cout <<  endl;
    cout << string(2,' ');
    for(int i=0; i<tamX; i++){
        cout << setfill(' ') << setw(5) << left << char('A'+i);
    }
    cout << ' ' << endl;
}


