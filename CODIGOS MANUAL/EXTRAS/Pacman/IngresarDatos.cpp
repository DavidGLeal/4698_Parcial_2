/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
INGENIERÍA DE SOFTWARE             
	AUTORES:
        Dylan Hernández
        Andrés Almeida
	Juan Reyes
        Brandon Masacela
        GRUPO: 3
   FECHA DE CREACION:        Lunes, 22 de agosto de 2022 07:25 p.m. 	
   FECHA DE MODIFICACION:     Miercoles, 24 de agosto de 2022 01:52 a.m.
 * --------------------------
 * Planteamiento: Elaborar simulación del juego Pac-Man, aplicando algoritmos
 * --------------------------
 */
#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "IngresarDatos.h"
#include "MenuGrafico.cpp"
using namespace std;

IngresarDatos::IngresarDatos(){
    x = 0;
    y = 0;
}
IngresarDatos::~IngresarDatos(){
    delete this;
}
void IngresarDatos::setCoordenadas(int _x, int _y)
{
    x = _x;
    y = _y;
}
int IngresarDatos::ingresarDatos(const char* prompt){
    string guia = "Ingrese el control " + (string)prompt + ": ";
    Escribir(x, y, guia.c_str());
    char *opcion = new char, input;
    int i = 0, contador = 0;
    bool primerIngreso = false;
    while ((input = getch()) != 13 && contador < 5)
    {
        if (input >= '0' && input <= '9')
        {
            printf("%c", input);
            opcion[i++] = input;
            contador++;
            primerIngreso = true;
        }
        else if (input == 8 && primerIngreso == true)
        {
            if (i > 0) {
                printf("%s", "\b \b");
                opcion[i--] = input;
                contador--;
            }
        }
        
    }
    opcion[i] = '\0';
    printf("\n");
    return atoi(opcion);
}
int IngresarDatos::ingresarDatosLim(const char* prompt, int _limite){
    cout << "Para evitar el desbordamiento de memoria, el maximo de ingreso es de " << _limite << " cifras."<<endl;
    cout << "Ingrese el control " << prompt << ": ";
    char *opcion = new char, input;
    int i = 0, contador = 0;
    bool primerIngreso = false;
    while ((input = _getch()) != 13 && contador < _limite)
    {
        if (input >= '0' && input <= '9')
        {
            printf("%c", input);
            opcion[i++] = input;
            contador++;
            primerIngreso = true;
        }
        else if (input == 8 && primerIngreso == true)
        {
            if (i > 0) {
                printf("%s", "\b \b");
                opcion[i--] = input;
                contador--;
            }
        }
    }
    opcion[i] = '\0';
    printf("\n");
    return atoi(opcion);
}
string IngresarDatos::ingresarCedula(string prompt)
{
    string cedula;
    bool validado = false;
    while(!validado)
    {
        string guia = "Ingrese un numero de cedula valido para el Estado Ecuatoriano";
        Escribir(x, y++, guia.c_str());
        guia = "Ingrese " + (string)prompt + ": ";
        Escribir(x, y++, guia.c_str());
        cin >> cedula;
        validado = validarCedula(cedula.c_str());
    }
    return cedula;
}
bool IngresarDatos::validarCedula(const char* identificacion)
{
    string guia;
    int limite = 0;
    int cedula[10];
    int provincia = 0;

    for (int i = 0; identificacion[i] != '\0'; i++)
    {
        cedula[i] = identificacion[i] - '0'; // Recorrido del Offset ASCII para empezar en 0.
        if (cedula[i] < 0 || cedula[i] > 9)
        {
            guia = "Usted ha ingresado un caracter alfabetico. Por favor, intente nuevamente.";
            Escribir(x, y++, guia.c_str());
            return 0;
        }
        if (i == 0)
            provincia += cedula[i] * 10;
        else if (i == 1)
            provincia += cedula[i];
        limite = i + 1;
    }

    if (limite != 10)
    {
        guia = "Error! La cedula debe tener 10 digitos.";
        Escribir(x, y++, guia.c_str());
        return 0;
    }

    if (provincia < 1 || provincia > 24)
    {
        if (provincia != 30) // El código 30 corresponde a una cédula de extranjería.
        {
            guia = "Error! Su Provincia no es valida.";
            Escribir(x, y++, guia.c_str());
            return 0;
        }
    }

    // Proceso de Verificación del Módulo 10
    // Cálculo del Dígito Verificador
    int i = 0, j = 0, control = 0;
    while (i < limite - 1)
    {
        j = cedula[i];
        if ((i + 1) % 2 != 0)
        {
            j *= 2;
            if (j > 9)
            {
                j -= 9;
            }
        }
        control += j;
        i++;
    }

    if (control % 10 != 0)
        control = 10 - (control % 10);
    else
        control = 0;

    if (cedula[9] != control)
    {
        guia = "Error! El Digito Verificador no es valido.";
        Escribir(x, y++, guia.c_str());
        return 0;
    }
    guia = "Felicidades! Cedula Correcta!";
    Escribir(x, y++, guia.c_str());
    return 1;
}
string IngresarDatos::ingresarDatosNumSt(const char* prompt, int _limite){
    cout << "Ingrese un numero de cedula valido para el Estado Ecuatoriano (10 digitos)"<<endl;
    cout << "Ingrese " << prompt << ": ";
    char *opcion = new char, input;
    int i = 0, contador = 0;
    bool primerIngreso = false, primero = false, segundo = false;
    while ((input = _getch()))
    {
        if (input >= '0' && input <= '9' && contador < _limite)
        {
            if (contador == 0 && (input >= 48 && input <= 50))
            {
                printf("%c", input);
                opcion[i++] = input;
                contador++;
                primerIngreso = true;
            }
            else if(contador == 1 && (opcion[0] == 50) && (input >= 48 && input <= 52))
            {
                printf("%c", input);
                opcion[i++] = input;
                contador++;
                primerIngreso = true;
                
            }
            else if(contador == 1 && (opcion[0] != 50) && (input >= 48 && input <= 57))
            {
                printf("%c", input);
                opcion[i++] = input;
                contador++;
                primerIngreso = true;
                
            }
            else if ((contador > 1) && (input >= 48 && input <= 57))
            {
                printf("%c", input);
                opcion[i++] = input;
                contador++;
                primerIngreso = true;
            }
        }
        else if (input == 8 && primerIngreso == true)
        {
            if (i > 0) {
                printf("%s", "\b \b");
                opcion[i--] = input;
                contador--;
            }
        }
        else if (input == 13)
        {
            if (contador == _limite)
            {
                break;
            }
        }
    }
    opcion[i] = '\0';
    printf("\n");
    return opcion;
}
float IngresarDatos::ingresarDatosF(const char* prompt, int _limite){
    cout << "Para evitar el desbordamiento de memoria, el máximo de ingreso es de " << _limite << " cifras."<<endl;
    cout << "Ingrese el control " << prompt << ": ";
    char *opcion = new char, input;
    int i = 0, contador = 0;
    bool primerIngreso = false;
    bool usado = false;
    while ((input = _getch()) != 13 && contador < _limite)
    {
        if (input >= '0' && input <= '9')
        {
            printf("%c", input);
            opcion[i++] = input;
            contador++;
            primerIngreso = true;
        }
        else if (input == '.' && usado == false)
        {
            usado = true;
            printf("%c", input);
            opcion[i++] = input;
        }
        else if (input == 8 && primerIngreso == true)
        {
            if (i > 0) {
                printf("%s", "\b \b");
                if (opcion[i] == '.')
                {
                    usado = false;
                }
                opcion[i--] = input;
                contador--;
            }
        }
        
    }
    opcion[i] = '\0';
    printf("\n");
    return atof(opcion);
}
string IngresarDatos::ingresarDatosS(const char* prompt){
    string guia = "Ingrese " + (string)prompt + ": ";
    Escribir(x, y++, guia.c_str());
    char *opcion = new char, input;
    int i = 0;
    bool primerIngreso = false;
    while ((input = _getch()) != 13)
    {
        if (input >= 97 && input <= 122)
        {
            printf("%c", input);
            opcion[i++] = input;
            primerIngreso = true;
        }
        else if (input == 8 && primerIngreso == true)
        {
            if (i > 0) {
                printf("%s", "\b \b");
                opcion[i--] = input;
            }
        }
        
    }
    opcion[i] = '\0';
    printf("\n");
    return opcion;
}
string IngresarDatos::ingresarDatosStringPermisivo(const char* prompt){
    string guia = "Ingrese " + (string)prompt + ": ";
    Escribir(x, y++, guia.c_str());
    char *opcion = new char, input;
    int i = 0;
    bool primerIngreso = false;
    while ((input = _getch()) != 13)
    {
        if (input >= 65 && input <= 168 || input == 32 || input == 46 || input >= 48 && input <= 57)
        {
            printf("%c", input);
            opcion[i++] = input;
            primerIngreso = true;
        }
        else if (input == 8 && primerIngreso == true)
        {
            if (i > 0) {
                printf("%s", "\b \b");
                opcion[i--] = input;
            }
        }
        
    }
    opcion[i] = '\0';
    printf("\n");
    return opcion;
}
string IngresarDatos::ingresarDatosOculto(const char* prompt)
{
    string guia = "Su clave no puede tener caracteres especiales.";
    Escribir(x, y++, guia.c_str());
    guia = "Ingrese " + (string)prompt + ": ";
    Escribir(x, y++, guia.c_str());
    char *opcion = new char, input;
    int i = 0;
    bool primerIngreso = false;
    while ((input = _getch()) != 13)
    {
        if (input >= 65 && input <= 168 || input == 32 || input == 46 || input >= 48 && input <= 57)
        {
            printf("%c", '*');
            opcion[i++] = input;
            primerIngreso = true;
        }
        else if (input == 8 && primerIngreso == true)
        {
            if (i > 0) {
                printf("%s", "\b \b");
                opcion[i--] = input;
            }
        }
        
    }
    opcion[i] = '\0';
    printf("\n");
    return opcion;
}
