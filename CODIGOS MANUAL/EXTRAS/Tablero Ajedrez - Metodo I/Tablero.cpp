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
#include "Tablero.h"

void Tablero::dibujarTablero(){
    initgraph(&gr,&gm,"C:\\TURBOC3\\BGI");
    printf("\t-------- TABLERO DE AJEDREZ --------n");

    for(row=0;row<8;row++){
        for(col=1;col<=8;col++){
            if(bandera==0){
                setcolor(BLUE);
                setfillstyle(SOLID_FILL,BLACK);
                rectangle(x,y,x+50,y+50);
                floodfill(x+1,y+1,BLUE);
                bandera=1;
            } else {
                setcolor(BLUE);
                setfillstyle(SOLID_FILL,WHITE);
                rectangle(x,y,x+50,y+50);
                floodfill(x+1,y+1,BLUE);
                bandera=0;
            }
            x=x+50; 
        }

        if(bandera==0)
        bandera=1;
        else
        bandera=0;
        delay(100);
        x=50;
        y=50+y;
    }

    getch();
    closegraph();
}