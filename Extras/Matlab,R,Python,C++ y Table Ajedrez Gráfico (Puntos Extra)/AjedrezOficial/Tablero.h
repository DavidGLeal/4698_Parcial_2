/*Universidad de las Fuerzas Armadas ESPE
  Enunciado: TABLERO DE AJEDREZ
  Autores: Adriana Diaz
           Camila Morales
           Johanna Pila
           Paola Moncayo
           Alexander Guacan
  Fecha de creación: 07/08/2022
  Fecha de modificación: 07/08/2022
  Github: https://github.com/Alexander-Guacan/Grupo5_Estructura_de_datos_4698
*/

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

class Tablero{
    private: 
    int gr=DETECT,gm;
    int fila,col,x=50,y=50,bandera=0;

    public:
    void dibujarTablero();
};