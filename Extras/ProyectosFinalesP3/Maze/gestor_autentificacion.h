#pragma once
#include <functional>
#include "circular_doubly_linked_list.h"
#include "usuario.h"

class GestorAutentificacion
{
public:
    GestorAutentificacion() = default;
    void iniciar();
    void alIngresar(std::function<void()> retrollamada);

    void autentificar();
    void registro();
    CircularDoublyLinkedList<Usuario> obtener_usuarios();
    void guardar_usuarios(CircularDoublyLinkedList<Usuario> usuarios);
    void guardar_usuario(Usuario usuario);
private:

    std::function<void()> _callback_ingreso;
};
