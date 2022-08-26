#pragma once
#include <string>
#include "modelo.h"

class Usuario : public Modelo
{
private:
    std::string _nombre;
    std::string _password;

public:
    Usuario() = default;
    Usuario(std::string nombre, std::string password);
    
    std::string getNombre();
    std::string getPassword();
    
    void setNombre(std::string nombre);
    void setPassword(std::string password);

    virtual std::string toCSV();
};
