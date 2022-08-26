#include "gestor_autentificacion.h"
#include "menu.h"
#include "utils.h"
#include "md5.h"

void GestorAutentificacion::iniciar()
{
    Menu menu("Autentificacion");

    _callback_ingreso = [&]() {
        menu.stop();
    };

    menu.add_option(MenuOption("Ingresar", [&]() { autentificar(); }));
    menu.add_option(MenuOption("Registrar nuevo usuario", [this]() { registro(); }));
    menu.add_option(MenuOption("Salir", []() { exit(0); }));
    menu.display();
}

void GestorAutentificacion::alIngresar(std::function<void()> callback)
{
    _callback_ingreso = callback;
}

void GestorAutentificacion::autentificar()
{

    std::string nombre = Utils::leer_con_formato("Ingresa el usuario: ", "^[a-zA-Z0-9_]{4,}$");
    std::string contrasena = Utils::leer_password("Ingresa la contrasena: ");
    MD5 md5;

    auto usuarios = obtener_usuarios();
    auto encontrado = usuarios.find([&](Usuario u) {
        return u.getNombre() == nombre;
    });

    if (!encontrado.has_value()) {
        std::cout << "\n[Nombre de usuario incorrecto]" << std::endl;
        return;
    }

    Usuario usuario = encontrado.value();

    if (usuario.getPassword() != md5(contrasena)) {
        std::cout << "\n[Contrasena incorrecta]" << std::endl;
        return;
    }
    
    if (_callback_ingreso) {
        _callback_ingreso();
    }
}

void GestorAutentificacion::registro()
{
    std::string nombre = Utils::leer_con_formato("Ingresa el usuario: ", "^[a-zA-Z0-9_]{4,}$");
    std::string contrasena, contrasena2;

    do {
        contrasena = Utils::leer_password("Ingresa la contrasena: ");
        contrasena2 = Utils::leer_password("Confirma la contrasena: ");

        if (contrasena != contrasena2) {
            std::cout << "\n[Las contrasenas no coinciden]" << std::endl;
        }
    } while (contrasena != contrasena2);

    MD5 md5;

    auto usuarios = obtener_usuarios();
    auto encontrado = usuarios.find([&](Usuario u) {
        return u.getNombre() == nombre;
    });

    if (encontrado.has_value()) {
        std::cout << "\n[Nombre de usuario en uso]" << std::endl;
        return;
    }

    guardar_usuario(Usuario(nombre, md5(contrasena)));
    std::cout << "\n[Usuario registrado]" << std::endl;
}

CircularDoublyLinkedList<Usuario> GestorAutentificacion::obtener_usuarios()
{
    CircularDoublyLinkedList<Usuario> usuarios;
    auto csv = Utils::leer_archivo_datos("usuarios.txt");

    for (auto registro : csv) {
        std::string nombre = registro[0];
        std::string contrasena = registro[1];
        usuarios.push_back(Usuario(nombre, contrasena));
    }

    return usuarios;
}

void GestorAutentificacion::guardar_usuarios(CircularDoublyLinkedList<Usuario> usuarios)
{
    std::vector<std::string> csv;
    
    usuarios.for_each([&](Usuario usuario) {
        csv.push_back(usuario.toCSV());
    });
    
    Utils::guardar_archivo_datos("usuarios.txt", csv);
}

void GestorAutentificacion::guardar_usuario(Usuario usuario)
{
    auto usuarios = obtener_usuarios();
    usuarios.push_back(usuario);
    guardar_usuarios(usuarios);
}
