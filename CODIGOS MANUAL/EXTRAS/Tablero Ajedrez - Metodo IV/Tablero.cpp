/*Universidad de las Fuerzas Armadas - ESPE
EXTRA - Parcial 3: 
Graficar en la consola un tablero de ajedrez.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 07/08/2022
FECHA DE MODIFICACIÓN: 07/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/

#include "Tablero.h"



void Tablero::dibujarBordes()
{
	for(int f=y; f<=y+600;f+=75)
	{
		for(int i=x; i<x+600;i++)
		{	
			SetPixel(mdc,i,f,COLOR);
			
			
			//SetPixel(mdc,i,f+600,COLOR);
		}
		
	}
	for(int c=x; c<=x+600;c+=75)
	{
		for(int j=y;j<y+600;j++)
		{
			SetPixel(mdc,c,j,COLOR);
			//SetPixel(mdc,x+600,j,COLOR);
		}
	}
}

void Tablero::pintarCasillas(int z, int r)
{
	for(int p=r;p<r+75;p++)
	{
		for(int s=z;s<z+75;s++)
		{
			SetPixel(mdc,s,p,COLOR);
		}
	}
}

void Tablero::graficarTablero()
{
	ShowWindow(miConsola,SW_SHOWMAXIMIZED);
	system("cls");
	dibujarBordes();
	for(int z=x;z<x+600;z+=75)
	{
		for(int r=y;r<y+600;r+=75)
		{
			if(((r-y)/75)%2==0 && ((z-x)/75)%2==0)
			{
				pintarCasillas(z,r);
			}
			if(((r-y)/75)%2!=0 && ((z-x)/75)%2!=0)
			{
				pintarCasillas(z,r);
			}	
		}		
	}
	cin.ignore();
	ReleaseDC(miConsola,mdc);
}