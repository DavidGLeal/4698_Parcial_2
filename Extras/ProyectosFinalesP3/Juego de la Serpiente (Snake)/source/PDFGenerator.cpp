#include "PDFGenerator.hpp"
#include "ScoreTextFileManager.hpp"
#include <iomanip>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <windows.h>

std::string PDFGenerator::scoreRecopilation(const std::string& user) {
    std::string scores{};

    std::ifstream scoreFile{ ScoreTextFileManager::scoreFileName, std::ios::in };

    if (scoreFile.fail())
        return scores;

    std::string userInFile{};
    std::string score{};
    while (!scoreFile.eof()) {
        std::getline(scoreFile, userInFile);
        std::getline(scoreFile, score);
        
        if (userInFile == user)
            scores += score + '\n';
    }

	scoreFile.close();

	return scores;
}

void PDFGenerator::generate(const std::string& user) {
	std::string archivoEntrada = "reporte.html";
	std::string archivoSalida = "Reporte.pdf";

	std::ofstream archivo(archivoEntrada, std::ios::trunc);
	std::stringstream html;

	html << "<!DOCTYPE html><html lang=\"en\">"
		"<head> <meta charset=\"UTF-8\"> <title>Reporte de SNAKE GAME</title>"
		"<style type=\"text/css\">"
		"body {font-family: sans-serif;}"
		"table {border-collapse:collapse; border: 1px solid #ececec; border-radius: 4px; border-bottom: 2px solid #ccc; padding: 8px; overflow: hidden;} "
		"table td {padding: 5px;} "
		"table > thead {background: #ececec; font-weight: bold;} "
		"table > thead td {border-bottom: 2px solid #ddd; margin: 0; padding: 12px 9px; text-align: center;} "
		"table > tbody tr:not(:last-child) {margin: 0; border-bottom: 1px solid #e4e4e4;} "
		"table > tbody td{text-align: center; padding: 10px 12px; border: none; margin: 0;} "
		"table > tbody tr:nth-child(even) {background: #f5f5f5;} "
		"table>tbody tr:nth-child(even) {background: #f5f5f5;}"
		"table>tfoot td {background: #ced6e0;color: #1f242e;font-weight: bold;}"
		"</style></head><body> "
		"<h1> Usuario " << user << "</h1> " <<
		"<br><br><br><strong>PUNTAJES </strong> ";

	html << "<pre>" << scoreRecopilation(user) << "</pre>";
	html <<
		"</body></html>";
	archivo << html.str();
	archivo.close();

	STARTUPINFOA si;
	PROCESS_INFORMATION pi[2];

	memset(&si, 0, sizeof(si));
	memset(&pi, 0, sizeof(pi));
	si.cb = sizeof(si);

	char args[200];
	sprintf(args, "wkhtmltopdf.exe %s %s", archivoEntrada.c_str(), archivoSalida.c_str());

	CreateProcessA(
		"wkhtmltopdf\\wkhtmltopdf.exe",
		args,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi[0]
	);
	WaitForSingleObject(pi->hProcess, INFINITE);

	ShellExecuteA(NULL, "open", archivoSalida.c_str(), NULL, NULL, SW_SHOW);
	DeleteFileA(archivoEntrada.c_str());
}