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
#include "Usuario.h"
#define useradmin1 "dylanhdz"
#define claveadmin1 "aspiracion"
#define useradmin2 "andresamd"
#define claveadmin2 "ventanacuatro"

class Login
{
private:
    std::string usuario;
    std::string clave;
public:
    Login();
    Login(std::string newUsuario, std::string newClave);
    std::string getUsuario();
    std::string getClave();
    void setUsuario(std::string newUsuario);
    void setClave(std::string newClave);
    ~Login();
    bool validarLoginAdmin(Login* login);
    bool validarLoginNormal(vector<Usuario>& usuarios, int pos);
};
