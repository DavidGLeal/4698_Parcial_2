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
#include <cmath>
#include <iostream>
#include <windows.h>

using namespace std;

#define PI 3.141592653898

class Grafico
{
private:

    // Apartado del Espacio de Trabajo
    HWND consola;
    HDC gestorConsola;
    // Apartado Geométrico
    HFONT fuenteArial; 
    RECT rectangulo;
    
public:
    
    int radio = 7.5;
    int espacioIntraNodoY = radio/2;

    COLORREF BLANCO = RGB(255,255,255); 
    COLORREF NEGRO = RGB(0,0,0); 
    COLORREF CYAN = RGB(0,255,255); 
    COLORREF ROJO = RGB(255,0,0); 
    COLORREF AMARILLO = RGB(255,255,0);
    COLORREF LIMA = RGB(25,255,25);
    
    Grafico();
    ~Grafico();
    void SetRadio(int rad);
    void DibujarPacman(int pixelX,int pixelY, COLORREF color, int sentido);
    void DibujarFantasma(int pixelX,int pixelY, COLORREF color);
    void DibujarCirculo(int pixelX,int pixelY, COLORREF color, const char* letra);
    void DibujarCuadrado(int pixelX,int pixelY, int dim, COLORREF color);
    void EtiquetarHorizontal(int pixelX,int pixelY, int num, COLORREF color);
    void EtiquetarVertical(int pixelX,int pixelY, int num, COLORREF color);
    void DibujarRecubrimiento(int pixelX,int pixelY, COLORREF color);
    void DibujarRecubrimientoRectangular(int pixelX,int pixelY, int dimX, int dimY, int borde, COLORREF color);
    void ImprimirFlecha(int pixelY, int pixelX);
    void BorrarFlecha(int pixelY, int pixelX);
    void ImprimirFlechaPadres(int pixelX, int pixelX1, int pixelY, int pixelY1);
    void BorrarFlechaPadres(int pixelX, int pixelX1, int pixelY, int pixelY1);
};

Grafico::Grafico()
{
    consola = GetConsoleWindow();
    gestorConsola = GetDC(consola);
    //SetWindowPos(consola,0,0,0,1000,900,SWP_SHOWWINDOW);
    // Inicializar la Fuente
    fuenteArial = CreateFont(1.25*radio,0,0,0,FW_DONTCARE,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY,VARIABLE_PITCH,TEXT("Arial"));    
    GetClientRect(consola, &rectangulo);
    SelectObject(gestorConsola,fuenteArial);
    SetTextColor(gestorConsola, BLANCO);
    SetBkMode(gestorConsola,TRANSPARENT);
}

Grafico::~Grafico()
{
    ReleaseDC(consola, gestorConsola);
    cin.ignore();
}
void Grafico::SetRadio(int rad)
{
    radio = rad;
}
void Grafico::DibujarPacman(int pixelX,int pixelY, COLORREF color, int sentido)
{
    double inicio, inicioi;
    //for(double i = PI/4; i < 7*PI/4 ; i += 0.01)
    if(sentido == 0) inicio = 0;
    else if(sentido == 1) inicioi = 3*PI/4;
    else if(sentido == 2) inicio = PI/4;
    else if(sentido == 3) inicioi = -PI/4;
    else if(sentido == 4) inicio = PI/4;
    if (sentido == 0 || sentido == 2)
    {
        for(double i = inicio; i < inicio+2*PI ; i += 0.007)
        {       
            for (double j = 0; j < radio; j += 0.5)
            {
                SetPixel(gestorConsola,pixelX+j*cos(i),pixelY+j*sin(i),color);           
            }
        
        }
    }
    else if (sentido == 1 || sentido == 3)
    {
        for(double i = inicioi; i > 5*PI/4 ; i -= 0.007)
        {       
            for (double j = 0; j < radio; j += 0.5)
            {
                SetPixel(gestorConsola,pixelX+j*cos(i),pixelY+j*sin(i),color);           
            }
        
        }
    }
    else if (sentido == 4)
    {
        for(double i = PI/4; i < 7*PI/4 ; i += 0.007)
        {       
            for (double j = 0; j < radio; j += 0.5)
            {
                SetPixel(gestorConsola,pixelX+j*cos(i),pixelY+j*sin(i),color);           
            }
        
        }
    }
    //rectangulo.left = pixelX-0.25*radio;
    //rectangulo.top = pixelY-radio/2;      
    //DrawTextA(gestorConsola,(LPCSTR)letra, -1, &rectangulo, DT_SINGLELINE | DT_NOCLIP);  
}
void Grafico::DibujarFantasma(int pixelX,int pixelY, COLORREF color)
{
    for(double i = PI; i < 2*PI ; i += 0.007)
    {       
        for (double j = 0; j < radio; j += 0.5)
        {
            SetPixel(gestorConsola,pixelX+j*cos(i),pixelY+j*sin(i),color);           
        }
    }
    for(double i = -radio; i < radio ; i += 1)
    {       
        for (double j = 0; j < radio; j += 1)
        {
            SetPixel(gestorConsola,pixelX+i,pixelY+j,color);           
        }
    }
}
void Grafico::DibujarCirculo(int pixelX,int pixelY, COLORREF color, const char* letra)
{
    for(double i = 0; i < 2*PI ; i += 0.05)
    {       
        for (double j = 0; j < radio; j += 1)
        {
            SetPixel(gestorConsola,pixelX+j*cos(i),pixelY+j*sin(i),color);           
        }
       
    }
    //rectangulo.left = pixelX-0.25*radio;
    //rectangulo.top = pixelY-radio/2;      
    //DrawTextA(gestorConsola,(LPCSTR)letra, -1, &rectangulo, DT_SINGLELINE | DT_NOCLIP);  
}
void Grafico::DibujarCuadrado(int pixelX, int pixelY, int dim, COLORREF color)
{
    for(double i = 0; i < dim ; i += 0.5)
    {       
        for (double j = 0; j < dim; j += 0.5)
        {
            SetPixel(gestorConsola,pixelX+i,pixelY+j,color);           
        }
    }
}
void Grafico::EtiquetarHorizontal(int pixelX,int pixelY, int num, COLORREF color)
{
    char letra = 'A';
    string letraSt = "";
    for(double i = 0; i < num ; i ++)
    {       
        letraSt = letra + i;
        rectangulo.left = pixelX+20+50*i;
        rectangulo.top = pixelY;      
        DrawTextA(gestorConsola,(LPCSTR)letraSt.c_str(), -1, &rectangulo, DT_SINGLELINE | DT_NOCLIP);           
    }
}
void Grafico::EtiquetarVertical(int pixelX,int pixelY, int num, COLORREF color)
{
    char numero = '1';
    string numeroSt = "";
    for(double i = 0; i < num ; i ++)
    {       
        numeroSt = numero + i;
        rectangulo.left = pixelX-10;
        rectangulo.top = pixelY+20+50*i;      
        DrawTextA(gestorConsola,(LPCSTR)numeroSt.c_str(), -1, &rectangulo, DT_SINGLELINE | DT_NOCLIP);           
    }
}
void Grafico::DibujarRecubrimiento(int pixelX,int pixelY, COLORREF color)
{
    for(double i = 0; i < 2*PI ; i += 0.01)
    {       
        for (double j = radio; j < radio+6; j += 1)
        {
            SetPixel(gestorConsola,pixelX+j*cos(i),pixelY+j*sin(i),color);           
        }
       
    }
}
void Grafico::DibujarRecubrimientoRectangular(int pixelX,int pixelY, int dimX, int dimY, int borde, COLORREF color)
{
    for(double i = 0; i < borde ; i += 0.1)
    {       
        for (double j = 0; j < dimY+borde; j += 1)
        {
            SetPixel(gestorConsola,pixelX+i,pixelY+j,color);           
            SetPixel(gestorConsola,pixelX+dimX+borde+i,pixelY+borde+j,color);           
        }
        for (double j = 0; j < dimX+borde; j += 1)
        {
            SetPixel(gestorConsola,pixelX+borde+j,pixelY+i,color);           
            SetPixel(gestorConsola,pixelX+j,pixelY+dimY+borde+i,color);           
        }
    }     
}
void Grafico::ImprimirFlecha(int pixelY, int pixelX)
{
    for (int i = 0; i < espacioIntraNodoY; i++)
    {
        SetPixel(gestorConsola,pixelX-1,pixelY+radio+i,BLANCO);
        SetPixel(gestorConsola,pixelX,pixelY+radio+i,BLANCO);
        SetPixel(gestorConsola,pixelX+1,pixelY+radio+i,BLANCO);
    }
    for (double i = 1.25*PI; i < 1.75*PI; i+=0.01)
    {
        for (int j = 0; j < espacioIntraNodoY/2; j++)
        {
            SetPixel(gestorConsola,pixelX+j*cos(i),pixelY+espacioIntraNodoY+radio-j,BLANCO);
        }
        
    }
}

void Grafico::BorrarFlecha(int pixelY, int pixelX)
{
    for (int i = 0; i < espacioIntraNodoY; i++)
    {
        SetPixel(gestorConsola,pixelX-1,pixelY+radio+i,NEGRO);
        SetPixel(gestorConsola,pixelX,pixelY+radio+i,NEGRO);
        SetPixel(gestorConsola,pixelX+1,pixelY+radio+i,NEGRO);
    }
    for (double i = 1.25*PI; i < 1.75*PI; i+=0.01)
    {
        for (int j = 0; j < espacioIntraNodoY/2+2; j++)
        {
            SetPixel(gestorConsola,pixelX+j*cos(i),pixelY+espacioIntraNodoY+radio+j*sin(i),NEGRO);
        }
        
    }
}

void Grafico::ImprimirFlechaPadres(int pixelX, int pixelX1, int pixelY, int pixelY1)
{
    if (pixelX1<pixelX)
    {
        swap(pixelX,pixelX1);
        swap(pixelY,pixelY1);
    }
    double m = ((double)pixelY1-(double)pixelY)/((double)pixelX1-(double)pixelX);
    float angXY = atan(m);
    for (double i = 0; i < abs(pixelX1-pixelX-2*radio*cos(angXY)); i=i+0.1)
    {
        for (double j = - 2.5; j < 2.5; j++)
        {
            SetPixel(gestorConsola,pixelX+i+radio*cos(angXY),pixelY+radio*sin(angXY)+i*m+j,BLANCO);
        }
    }
}

void Grafico::BorrarFlechaPadres(int pixelX, int pixelX1, int pixelY, int pixelY1)
{
    if (pixelX1<pixelX)
    {
        swap(pixelX,pixelX1);
        swap(pixelY,pixelY1);
    }
    double m = ((double)pixelY1-(double)pixelY)/((double)pixelX1-(double)pixelX);
    float angXY = atan(m);
    for (double i = 0; i < abs(pixelX1-pixelX-2*radio*cos(angXY)); i=i+0.1)
    {
        for (double j = - 3; j < 3; j++)
        {
            SetPixel(gestorConsola,pixelX+i+radio*cos(angXY),pixelY+50*sin(angXY)+i*m+j,NEGRO);
        }
    }
}
