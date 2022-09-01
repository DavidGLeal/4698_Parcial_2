
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Complemento.cpp"
/* Estructura de cuentas de usuario */
class Usuario {
	private:
        char nombre[80];
	    char password[80];
    public:

    /* Funciones de menú */
    void menuInicial();
    void menuListarUsuarios();
    void menuRegistrarUsuario();
    void menuIniciarSesion();
    void menuSistema();
	void registrarUno();
    /* Funciones que manipulan el archivo de usuarios */
    char insertarUsuario(Usuario usuario);
    char existeUsuario(char nombreUsuario[], Usuario *usuario);
    Usuario *obtenerUsuarios(int *);
    char logear(char nombreUsuario[], char password[]);
    int leerLinea(char *cad, int n);
    void leerClave(char *password);

        char getNombre();
        char getPassword();
        void setNombre(char);
        void setPassword(char);
};
