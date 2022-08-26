/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
    INGENIERA DE SOFTWARE
                
	AUTORES:    Luca de Veintemilla
				Kevin Vargas 
                Cristopher Iza
                Denisse Rea
					
	FECHA DE CREACION:        20-05-2022 	
	FECHA DE MODIFICACION:    24-05-2022
	Grupo #6
*/
#include "Marquee.hpp"

void Marquee::gotoXY(int x,int y ){
    CursorPosition.X = x; 
	CursorPosition.Y = y; 
	SetConsoleCursorPosition(console,CursorPosition); 
}

void Marquee::displayMarquee(){
    int a=0,  c=1 ;
char t[25] ="Ajedrez";
do
{
for (a=27;a<=66;a++)
{
gotoXY(a+1,1);
std::cout<<" ";
gotoXY(a,1);
std::cout<<t;
gotoXY(a-1,1);
std::cout<<" ";
gotoXY(27,1);
std::cout<<"             ";
gotoXY(66,1);
std::cout<<"             ";
gotoXY(a-13,1);
Sleep (400);
    /* if (kbhit()) {
        if (getch () == 27) {
            return;
        }
    } */
}
}while ((c=1));
getch();
}
