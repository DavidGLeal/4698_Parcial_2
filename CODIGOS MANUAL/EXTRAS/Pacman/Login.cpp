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
#include "Login.h"

Login::Login()
{
}
Login::Login(std::string newUsuario, std::string newClave)
{
    usuario = newUsuario;
    clave = newClave;
}
std::string Login::getUsuario(){
    return usuario;
}
std::string Login::getClave(){
    return clave;
}
void Login::setUsuario(std::string newUsuario){
    usuario = newUsuario;
}
void Login::setClave(std::string newClave){
    clave = newClave;
}
Login::~Login()
{
}
bool Login::validarLoginAdmin(Login* login){
    if ((login->getUsuario() == useradmin1 && login->getClave() == claveadmin1) || (login->getUsuario() == useradmin2 && login->getClave() == claveadmin2))
    {
        return true;
    }
    return false;
}
bool Login::validarLoginNormal(vector<Usuario>& usuarios, int pos){
    //if ((clientes->buscar(getUsuario())).getNombre() == getUsuario() && (clientes->buscar(getUsuario())).getCedula() == getClave())
    Usuario _usuario = usuarios.at(pos);
    if((_usuario.usuario == this->getUsuario()) && (_usuario.clave == this->getClave()))
    {
        return true;
    }
    else
    {
        return false;
    }
}
