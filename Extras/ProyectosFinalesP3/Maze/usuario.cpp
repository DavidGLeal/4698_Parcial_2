#include "usuario.h"

Usuario::Usuario(std::string nombre, std::string password)
{
    _nombre = nombre;
    _password = password;
}

std::string Usuario::getNombre()
{
    return _nombre;
}

std::string Usuario::getPassword()
{
    return _password;
}

void Usuario::setNombre(std::string nombre)
{
    _nombre = nombre;
}

void Usuario::setPassword(std::string password)
{
    _password = password;
}

std::string Usuario::toCSV()
{
    return _nombre + "," + _password;
}
