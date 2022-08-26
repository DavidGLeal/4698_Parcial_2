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
#include <vector>
#include "IngresarDatos.cpp"
#include "MenuGrafico.cpp"

using namespace std;

class Usuario
{
public:
    string nombre;
    string cedula;
    string direccion;
    string usuario;
    string clave;
    Usuario();
    Usuario(string _nombre, string _cedula, string _direccion, string _usuario, string _clave);
    ~Usuario();
    Usuario crearUsuario(int x, int y);
    bool buscarUsuario(vector<Usuario> &usuarios, string _cedula);
    int recuperarUsuario(vector<Usuario> &usuarios, string _usuario);
};

Usuario::Usuario()
{
}

Usuario::~Usuario()
{
}

Usuario::Usuario(string _nombre, string _cedula, string _direccion, string _usuario, string _clave)
{
    nombre = _nombre;
    cedula = _cedula;
    direccion = _direccion;
    usuario = _usuario;
    clave = _clave;

}

Usuario Usuario::crearUsuario(int _x, int _y)
{
    IngresarDatos *ing = new IngresarDatos();
    ing->setCoordenadas(_x,_y);
    Usuario* usuario = new Usuario(ing->ingresarDatosStringPermisivo("su nombre"),
        ing->ingresarCedula("su cedula"),
        ing->ingresarDatosStringPermisivo("su direccion"),
        ing->ingresarDatosStringPermisivo("su nombre de usuario"),
        ing->ingresarDatosOculto("su clave"));
    return *usuario;
}

bool Usuario::buscarUsuario(vector<Usuario> &usuarios, string _cedula)
{
    for (int i = 0; i < usuarios.size(); i++)
    {
        if (usuarios[i].cedula == _cedula)
        {
            return true;
        }
    }
    return false;
}

int Usuario::recuperarUsuario(vector<Usuario> &usuarios, string _usuario)
{
    for (int i = 0; i < usuarios.size(); i++)
    {
        if (usuarios[i].usuario == _usuario)
        {
            return i;
        }
    }
    return 0;
}
