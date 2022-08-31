/*Universidad de las Fuerzas Armadas - ESPE
TAREA #3 - Parcial 3: 
Graficar, en base a algoritmos, los distintos casos de la notación asintótica Big O.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 18/08/2022
FECHA DE MODIFICACIÓN: 19/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/

#pragma once
#include "BigO.h"
BigO::BigO(int _x,int _y)
{
	this->x=_x;
	this->y=_y;
	
	miConsola = GetConsoleWindow();
	mdc = GetDC(miConsola);
	ShowWindow(miConsola,SW_SHOWMAXIMIZED);
}

int BigO::getX()
{
	return x;
}
int BigO::getY()
{
	return y;
}

void BigO::setX(int nx)
{
	x=nx;
}
void BigO::setY(int ny)
{
	y=ny;
}

void BigO::grafiPlano(int n,int op)
{
	
	COLOR= RGB(255,255,255);
	for(int i=x; i<x+n*50; i++) {
		SetPixel(mdc,i,y,COLOR);
	}
	for(int j=y; j>y-n*50; j--) {
		SetPixel(mdc,x,j,COLOR);
	}
	int numx=0,numy=0;


	for(int z=0; z<5; z++) {
		SetPixel(mdc,x+n*50-z,y-z,COLOR);
		SetPixel(mdc,x+n*50-z,y+z,COLOR);
		SetPixel(mdc,x+z,y-n*50+z,COLOR);
		SetPixel(mdc,x-z,y-n*50+z,COLOR);
	}
	cin.ignore();
}

void BigO::o1(int n)
{
//	system("cls");
	grafiPlano(n,1);
	COLOR=RGB(0,100,255);
	for(double d=0; d<=n; d+=0.005) {
		//for(double k=0; k<300000; k++);
		SetPixel(mdc,x+50*d,y-50,COLOR);
		SetPixel(mdc,x+50*d,y-50+1,COLOR);
		SetPixel(mdc,x+50*d,y-50-1,COLOR);
			
	}
	cin.ignore();
}
void BigO::oN(int n)
{
//	system("cls");
	grafiPlano(n,1);
	COLOR=RGB(0,100,255);
	for(double d=0; d<=n; d+=0.005) {
		for(double k=0; k<300000; k++);
		SetPixel(mdc,x+50*d,y-50*d,COLOR);
		SetPixel(mdc,x+50*d+1,y-50*d+1,COLOR);
		SetPixel(mdc,x+50*d-1,y-50*d-1,COLOR);
	}
	cin.ignore();
}

void BigO::oCua(int n)
{
//	system("cls");
	grafiPlano(n,2);
	COLOR=RGB(0,100,255);
	for(double d=0; d<=n; d+=0.005) {
		for(double k=0; k<300000; k++);	
		if(y-50*pow(d,2)>=y-n*50)
		{
			SetPixel(mdc,x+50*d,y-50*pow(d,2),COLOR);
			SetPixel(mdc,x+50*d-1,y-50*pow(d,2)-1,COLOR);
			SetPixel(mdc,x+50*d+1,y-50*pow(d,2)+1,COLOR);
		
		}
		else
			break;
	}
	cin.ignore();
}

void BigO::oCub(int n)
{
//	system("cls");
	grafiPlano(n,3);
	COLOR=RGB(0,100,255);
	for(double d=0; d<=n; d+=0.005) {
		for(double k=0; k<300000; k++);
		if(y-50*pow(d,3)>=y-n*50)
		{
			SetPixel(mdc,x+50*d,y-50*pow(d,3),COLOR);
			SetPixel(mdc,x+50*d-1,y-50*pow(d,3)-1,COLOR);
			SetPixel(mdc,x+50*d+1,y-50*pow(d,3)+1,COLOR);
		}
		else
			break;
	}
	cin.ignore();
}

void BigO::oLog(int n)
{
//	system("cls");
	grafiPlano(n,4);
	COLOR=RGB(0,100,255);
	for(double d=0; d<=n; d+=0.005) {
		for(double k=0; k<300000; k++);
		if(log(d)>=0 && y-50*log(d)>=y-n*50){
		
			SetPixel(mdc,x+50*d,y-50*log(d),COLOR);
			SetPixel(mdc,x+50*d-1,y-50*log(d)-1,COLOR);
			SetPixel(mdc,x+50*d+1,y-50*log(d)+1,COLOR);
		}
		if(y-50*log(d)<y-n*50)
		{
			break;
		}
		
	}
	cin.ignore();
}

void BigO::oNLog(int n)
{
//	system("cls");
	grafiPlano(n,5);
	COLOR=RGB(0,100,255);
	for(double d=0; d<=n; d+=0.005) {
		for(double k=0; k<300000; k++);
		if(log(d)>=0 && y-50*n*log(d)>=y-n*50)
		{
			SetPixel(mdc,x+50*d,y-50*n*log(d),COLOR);
			SetPixel(mdc,x+50*d-1,y-50*n*log(d)-1,COLOR);
			SetPixel(mdc,x+50*d+1,y-50*n*log(d)+1,COLOR);
		}
		if(y-50*n*log(d)<y-n*50)
		{
			break;
		}
	}
	cin.ignore();
}

void BigO::o2N(int n)
{
//	system("cls");
	grafiPlano(n,6);
	COLOR=RGB(0,100,255);
	for(double d=0; d<=n; d+=0.005) {
		for(double k=0; k<300000; k++);
		if(y-50*pow(2,d)>=y-n*50  && y-50*pow(2,d)>=0)
		{
			SetPixel(mdc,x+50*d,y-50*pow(2,d),COLOR);
			SetPixel(mdc,x+50*d-1,y-50*pow(2,d)-1,COLOR);
			SetPixel(mdc,x+50*d+1,y-50*pow(2,d)+1,COLOR);
		}
		
		if(y-50*pow(2,d)<y-n*50)
		{
			break;
		}
	}
	
	cin.ignore();
}