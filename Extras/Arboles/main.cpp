/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Programa que permita hacer uso de la estructura de datos arbol AVL
 * Autor: Grupo 1 y 20
 * Fecha de creacion: 2022-07-12
 * Fecha de ultima modificación: 2022-07-13
 * Github: https://github.com/ChristopherIza/Arboles_AVL.git
 */

// #include "MenuPrincipal.hpp"
#include "Login.hpp"
#include "Marquee.hpp"
#include "GlobalVariables.hpp"
#include "PrintBitMap.hpp"
#include <thread>
using namespace std;

void printImage() {
    const std::string BITMAP_FILE_NAME{"imagen.bmp"};
    PrintBitmap::printImage(BITMAP_FILE_NAME);
}

void menu(){
    Login menu;
    menu.start();
}
void marquee(){
    Marquee marquee;
    marquee.displayMarquee();
}

int main() {
    printImage();

    //MenuPrincipal::start();
    //Login::start();
    thread first(menu);
	thread second(marquee);
	first.join();
	second.join();

    /* if (GlobalVariables::printImageAvailable)
        printImage(); */

    return 0;
}