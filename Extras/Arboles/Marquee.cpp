/**
 * @file Node.hpp
 * @author Grupo 1 y Grupo 20
 * @brief Node class
 * @brief Github: https://github.com/ChristopherIza/Arboles_AVL.git
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Marquee.hpp"

void Marquee::gotoXY(int x,int y ){
    CursorPosition.X = x; 
	CursorPosition.Y = y; 
	SetConsoleCursorPosition(console,CursorPosition); 
}

void Marquee::displayMarquee(){
    int a=0,  c=1 ;
char t[25] ="Arbol AVL";
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