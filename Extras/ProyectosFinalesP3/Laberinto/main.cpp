#define _WIN32_WINNT 0x0500
#include "MazeGame.h"
#include "menu.h"
#include "imagenpixelada.h"
#include "marquesina.h"
#include "gestor_autentificacion.h"
#include <windows.h>

int main()
{
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_SHOW);
    SetConsoleOutputCP(65001);
    Marquesina marquesina("Universidad de las fuerzas armadas ESPE - Estructura de datos");
    marquesina.iniciar();

    GestorAutentificacion gestor_auth;
    gestor_auth.iniciar();

    Menu menu("Estructura de datos::Proyecto Final");
    
    menu.add_option(MenuOption("Iniciar Laberinto", []() {
        MazeGame game;
        game.initialize();
    }));

    menu.add_option(MenuOption("Pixelar Imagen", []() {
        ImagenPixelada ipx("espe.bmp");
        ipx.pixelar();
    }));

    menu.add_option(MenuOption("Ayuda", [&]() {
        ShellExecuteA(NULL, "open", "manual.chm", NULL, NULL, SW_SHOW);
    }));

    menu.add_option(MenuOption("Salir", [&]() {
        menu.stop();
    }, false));

    menu.display();

    return 0;
}
