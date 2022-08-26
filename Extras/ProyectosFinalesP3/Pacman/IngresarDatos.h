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
class IngresarDatos
{
private:
    int x;
    int y;
public:
    IngresarDatos();
    void setCoordenadas(int _x, int _y);
    int getX(){return x;};
    int getY(){return y;};
    ~IngresarDatos();
    std::string ingresarCedula(string prompt);
    bool validarCedula(const char* identificacion);
    int ingresarDatos(const char* prompt);
    int ingresarDatosLim(const char* prompt, int _limite);
    string ingresarDatosNumSt(const char* prompt, int _limite);
    float ingresarDatosF(const char* prompt, int _limite);
    string ingresarDatosS(const char* prompt);
    string ingresarDatosStringPermisivo(const char* prompt);
    string ingresarDatosOculto(const char* prompt);
};
