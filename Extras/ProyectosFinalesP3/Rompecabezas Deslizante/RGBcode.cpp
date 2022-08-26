/*Universidad de las Fuerzas Armadas - ESPE
PROYECTO - Parcial 3: 
Por medio de un algoritmo de busqueda exhaustiva, ordenar una matriz de colores en función de sus códigos RGB.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 20/08/2022
FECHA DE MODIFICACIÓN: 21/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/
#pragma once

#include "RGBcode.h"

RGBcode::RGBcode(int _x, int _y)
{
	
	this->x=_x;
	this->y=_y;
//	srand(time(NULL));
//	randRGB();
	
}
RGBcode::RGBcode()
{
	this->x=0;
	this->y=0;
//	srand(time(NULL));
//	randRGB();
	
}

RGBcode::RGBcode(int r,int g, int b)
{
	this->rojo=r;
	this->azul=b;
	this->verde=g;
	color=RGB(getR(),getG(),getB());
	this->x=0;
	this->y=0;
}

//int* RGBcode::getColor()
//{
//	int colin[] = {rojo,verde,azul};
//	return colin;
//}
void RGBcode::setColor(int r,int v, int b)
{
	rojo=r;
	verde=v;
	azul=b;
	color=RGB(rojo,verde,azul);
}

int RGBcode::getX()
{
	return x;
}
int RGBcode::getY()
{
	return y;
}
int RGBcode::getR()
{
	return rojo;
}
int RGBcode::getG()
{
	return verde;
}
int RGBcode::getB()
{
	return azul;
}

void RGBcode::setX(int nx)
{
	x=nx;
}
void RGBcode::setY(int ny)
{
	y=ny;
}
void RGBcode::setR(int r)
{
	rojo=r;
	color=RGB(getR(),getG(),getB());
}
void RGBcode::setG(int g)
{
	verde=g;
	color=RGB(getR(),getG(),getB());
}
void RGBcode::setB(int b)
{
	azul=b;
	color=RGB(getR(),getG(),getB());
}

int RGBcode::getRad()
{
	return rad;
}
void RGBcode::setRad(int ra)
{
	rad =ra;
}

void RGBcode::randRGB(int anulado)
{
	
	switch(anulado)
	{
		case 1://rojo
		{
			
			rojo=0;
			verde=rand()%256;
			azul=rand()%256;
			break;
		}
		case 2://verde
		{
			rojo= rand()%256;
			verde = 0;
			azul=rand()%256;
			break;
		}
		case 3://azul
		{
			verde = rand()%256;
			rojo=rand()%256;
			azul=0;
		}
		default:
			break;
		
	}
	
	color = RGB(rojo,verde,azul);
	//verde=rand()%256;
	
}

void RGBcode::mostrar()
{
	//color=RGB(getR(),getG(),getB());
	for(int l=getX()-20;l<=getX()+20;l++)
	{
		for(int a=getY()-20;a<=getY()+20;a++)
		{
			SetPixel(mdc,l,a,color);
		}
		
	}
}
