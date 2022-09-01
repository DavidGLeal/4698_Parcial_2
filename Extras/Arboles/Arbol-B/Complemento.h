
#include <cstdlib>
#include <conio.h>
#include <windows.h> 
#include <iostream>
#pragma once 
using namespace std;
 
 class Complemento{
 public:
         Complemento();
        void gotoxy(int, int);
        int menu(const char *titulo, const char *opciones[], int n);
 };
 
     