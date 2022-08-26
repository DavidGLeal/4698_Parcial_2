#pragma once
#include <thread>
#include <chrono>
#include <functional>
#include <string>
#include <Windows.h>

class Marquesina {
public:
	Marquesina(std::string texto) {
		hilo = std::thread(std::bind(&Marquesina::procesarHilo, this, texto));
	}

	void procesarHilo(std::string mensaje) {
		HANDLE conhandler = GetStdHandle(STD_OUTPUT_HANDLE);
		std::string texto(std::move(mensaje));
		std::string marquesinaTexto = texto;

		// obtener tamaño consola
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		int columnas, filas;

		GetConsoleScreenBufferInfo(conhandler, &csbi);
		columnas = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		filas = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

		if (marquesinaTexto.length() < columnas) {
			while (marquesinaTexto.length() < columnas) {
				marquesinaTexto.append(" ");
			}
		}

		SetConsoleCursorPosition(conhandler, {0, 3});

		while (true) {
			CHAR_INFO* buff = (CHAR_INFO*)calloc(marquesinaTexto.length() * 2, sizeof(CHAR_INFO));
			int i = 0;

			for (int i = 0; i < marquesinaTexto.length(); i++) {
				buff[i].Char.AsciiChar = marquesinaTexto.at(i);
				buff[i].Attributes = 15;
			}

			SMALL_RECT pos = { 0, 0, columnas, 1 };
			WriteConsoleOutputA(conhandler, buff, {(SHORT)columnas, 1}, { 0, 0 }, &pos);
			free(buff);

			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			std::string temp = marquesinaTexto;
			marquesinaTexto.erase(0, 1);
			marquesinaTexto += temp[0];
			marquesinaTexto = marquesinaTexto.substr(0, columnas);
		}
	}

	void iniciar() {
		hilo.detach();
	}

private:
	std::thread hilo;
};