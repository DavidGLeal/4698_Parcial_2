#pragma once
#include "CPieza_Hijas.h"


// ---- Peon ----------------------------------

CPeon::CPeon():CPieza() {icono[0] = 'P';}

CPeon::CPeon(int y, int x, char c): CPieza(y, x, c) {icono[0]='P';}



// ---- Torre ---------------------------------

CTorre::CTorre():CPieza() {icono[0] = 'T';}

CTorre::CTorre(int y, int x, char c): CPieza(y, x, c) {icono[0]='T';}



// ---- Caballo -----------------------------------

CCaballo::CCaballo():CPieza() {icono[0] = 'C';}

CCaballo::CCaballo(int y, int x, char c): CPieza(y, x, c) {icono[0]='C';}




// ---- Alfil ---------------------------------

CAlfil::CAlfil():CPieza() {icono[0] = 'A';}

CAlfil::CAlfil(int y, int x, char c): CPieza(y, x, c) {icono[0]='A';}




// ---- Reina ---------------------------------

CReina::CReina():CPieza() {icono[0] = 'Q';}

CReina::CReina(int y, int x, char c): CPieza(y, x, c) {icono[0]='Q';}



// ---- Rey -----------------------------------

CRey::CRey():CPieza() {icono[0] = 'K';}

CRey::CRey(int y, int x, char c): CPieza(y, x, c) {icono[0]='K';}

CRey::~CRey() {
}

