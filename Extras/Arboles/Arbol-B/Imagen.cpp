
#include "Imagen.h" 
#include <conio.h>
using namespace std;

void Imagen::Imagenes() {
    runIMG();
}

int Imagen::runIMG() {
    HWND console = GetConsoleWindow();
    HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
    HDC dc = GetDC(console);

    CONSOLE_FONT_INFOEX Font = { sizeof(Font) };
    GetCurrentConsoleFontEx(output, FALSE, &Font);

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 1;
    cfi.dwFontSize.Y = 1;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    ShowWindow(console, SW_SHOWMAXIMIZED);


    std::cout << std::endl;
    drawImage("Arbol_B_24.bmp", &dc);
    _getch();

    SetCurrentConsoleFontEx(output, FALSE, &Font);
    system("cls");
    return 0;
}

void Imagen::drawImage(std::string imagePath, HDC* console) {
    BMP image;
    image.ReadFromFile(imagePath.c_str());

    double original_width = image.TellWidth();
    double original_height = image.TellHeight();
    double ratio = ratio = original_width / original_height;

    double max_width = 500;
    double width = original_width;
    double height = original_height;

    if (original_width > max_width) {
        height = max_width / ratio;
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int RED = image.GetPixel(x, y).Red;
            int GREEN = image.GetPixel(x, y).Green;
            int BLUE = image.GetPixel(x, y).Blue;

            int ALPHA = image.GetPixel(x, y).Alpha;

            COLORREF COLOUR = RGB(RED, GREEN, BLUE);
            if (ALPHA == 0) {
                //SetPixel(*console, x, y, COLOUR);

                std::cout << "\033["
                    << 48
                    << ";2;"
                    << RED << ";"
                    << GREEN << ";"
                    << BLUE << "m"
                    << "##"
                    << "\033[0;00m";

                if (x == width - 1) {
                    std::cout << std::endl;
                }
            }
        }
    }
}