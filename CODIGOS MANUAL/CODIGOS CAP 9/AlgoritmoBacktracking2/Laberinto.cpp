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
   FECHA DE CREACION:        Domingo, 07 de agosto de 2022 05:42 p.m. 	
   FECHA DE MODIFICACION:    Domingo, 07 de agosto de 2022 11:30 p.m.
 * --------------------------
 * Planteamiento: Resolver un laberinto utilizando Backtracking
 * --------------------------
 * Este programa implementa una solución al Problema de resolver un laberinto
 * utilizando el metodo de Backtracking
 */
 
#include "Laberinto.h"

Laberinto::Laberinto()
{
}

bool Laberinto::backtracking(int i, int j)
{
    if (m[i][j] == 3)
    {
        MuestraLaberinto();
        fp = i;
        cp = j;
        return true;
    }

    m[i][j] = 4; 

    if (pasoApaso)
    {
        fp = i;
        cp = j;
        MuestraLaberinto();
        printf("Movimientos %d, pasos reales %d. ", movs, pasosReales);
        system("pause");
    }
    movs++;
    pasosReales++;

    if (i - 1 >= 0 && i - 1 < f && (m[i - 1][j] == 0 || m[i - 1][j] == 3))
        if (backtracking(i - 1, j))
            return true; // 0

    if (j + 1 >= 0 && j + 1 < c && (m[i][j + 1] == 0 || m[i][j + 1] == 3))
        if (backtracking(i, j + 1))
            return true; // 1

    if (i + 1 >= 0 && i + 1 < f && (m[i + 1][j] == 0 || m[i + 1][j] == 3))
        if (backtracking(i + 1, j))
            return true; // 3

    if (j - 1 >= 0 && j - 1 < c && (m[i][j - 1] == 0 || m[i][j - 1] == 3))
        if (backtracking(i, j - 1))
            return true; // 2

    m[i][j] = 0;
    movs--;
    if (pasoApaso)
    {
        fp = i;
        cp = j;
        MuestraLaberinto();
        printf("Movimientos %d, pasos reales %d. ", movs, pasosReales);
        pasosReales++;
        system("pause");
    }
    return false;
}

void Laberinto::dimensionaMatriz()
{
    bool flag = true;  
    FILE *archivo;
    char caracter;
    int codigo;

    archivo = fopen(ruta, "rt");
    if (archivo == NULL)
    {
        printf("Error en lectura de archivo\n");
        system("pause");
        exit(EXIT_FAILURE);
    }
    f = 1;
    c = 1;
    while (!feof(archivo))
    { 
        caracter = fgetc(archivo);
        codigo = caracter;

        if (codigo == 10)
        {        
            f++;
            if (flag)
                flag = false;
        }
        else if (flag)
            c++; 
    }
    fclose(archivo);

    m = (int **)malloc(f * sizeof(int *));
    for (int j = 0; j < f; j++)
        m[j] = (int *)malloc(c * sizeof(int));
}

void Laberinto::leerArchivo()
{
    int ff, cc, codigo;
    FILE *archivo;
    char caracter;

    archivo = fopen(ruta, "rt"); 
    if (archivo == NULL)
    { 
        printf("Error en lectura de archivo\n");
        system("pause");
        exit(EXIT_FAILURE); 
    }

    for (int i = 0; i < f - 1; i++)
    {
        for (int ii = 0; ii < c; ii++)
        {
            caracter = fgetc(archivo);
            codigo = caracter; 
            if (codigo != 10)
            {
                m[i][ii] = codigo - 48; 
                if (m[i][ii] == 2)
                {
                    ifp = i;
                    icp = ii;
                }
                if (m[i][ii] == 3)
                {
                    fs = i;
                    cs = ii;
                }
                if (m[i][ii] == 0)
                    espacios++; 
            }
        }
    }
    fclose(archivo);
}

void Laberinto::MuestraLaberinto()
{
    system("cls");
    for (int i = 0; i < f; i++)
    {
        for (int ii = 0; ii < c; ii++)
        {
            if (m[i][ii] == 1)
                printf("%c", char(219)); // Bloque
            else if (i == fs && ii == cs)
                printf("M");
            else if (i == fp && ii == cp)
                printf("J");
            else if (m[i][ii] == 4)
                printf("."); // Es por donde ya paso el jugador
            else
                printf(" ");
        }
        printf("\n");
    }
}

void Laberinto::corre()
{
    char tcl;
    printf ("Ingresa el nombre de archivo: ");
    scanf ("%s",&ruta);
    dimensionaMatriz();
    while (tcl != 27)
    {

        leerArchivo();
        movs = 0;
        fp = ifp;
        cp = icp; 
                  

        while (fp != fs || cp != cs)
        { 
            printf("Calculando...");
            backtracking(fp, cp);
        }
        MuestraLaberinto();
        if (fp == fs && cp == cs)
        {
            printf("%d movimientos con el metodo de Backtracking.\n", movs);
        }
        printf("Persione ESC para salir");
        tcl = getch();
    }
}
