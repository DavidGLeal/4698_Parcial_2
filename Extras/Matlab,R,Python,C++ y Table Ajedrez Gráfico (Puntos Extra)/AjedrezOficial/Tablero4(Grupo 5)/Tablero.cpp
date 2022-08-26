/*Universidad de las Fuerzas Armadas - ESPE
EXTRA - Parcial 3: 
Graficar en la consola un tablero de ajedrez.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 07/08/2022
FECHA DE MODIFICACIÓN: 07/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/
//#pragma comment (lib, "gdi32.lib")
#include "Tablero.h"

Tablero::Tablero(int d)
{
	this->dim=d;
}

Tablero::Tablero()
{
	this->dim=8;
}


int Tablero::getDim()
{
	return dim;
}
void Tablero::setDim(int d)
{
	dim=d;
}

void Tablero::dibujarBordes()
{
	for(int f=y; f<=y+dim*75;f+=75)
	{
		
		for(int i=x; i<x+dim*75;i++)
		{	
			SetPixel(mdc,i,f,COLOR);
			
			
			//SetPixel(mdc,i,f+600,COLOR);
		}
		
	}
	for(int c=x; c<=x+dim*75;c+=75)
	{
		
		for(int j=y;j<y+dim*75;j++)
		{
			SetPixel(mdc,c,j,COLOR);
		}
	}
//	cin.ignore();
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
	for(int z=x;z<x+dim*75;z+=75)
	{
		for(int r=y;r<y+dim*75;r+=75)
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
//	cin.ignore();
}


void Tablero::jugarTorre()
{
	graficarTablero();
	srand(time(NULL));
	int px = rand()%dim;
	int py = rand()%dim;
	int x2= px;
	int y2=py;
	int inic[] = {x+(px)*75+37,y+(py)*75+37};
	int nuePosi[] = {(*(inic)),(*(inic+1))};
	string c = "T";
	
	COLOR = RGB(0,255,243);
	
	
	for(int i=x;i<x+dim*75;i+=75)
	{
		pintarCasillas(i,(*(inic+1))-37);
	}
	for(int j=y;j<y+dim*75;j+=75)
	{
		pintarCasillas((*(inic))-37,j);
	}
	
	COLOR = RGB(0,0,0);
	dibujarBordes();
	
	TextOut(mdc,(*(inic)),(*(inic+1)),c.c_str(),c.length());
	int tecla;
	
	do
	{
		TextOut(mdc,(*(inic)),(*(inic+1)),c.c_str(),c.length());
		do
		{
			tecla=getch();
		}while(tecla!=ARRIBA && tecla!=ABAJO && tecla!=IZQUIERDA && tecla!=DERECHA && tecla!= ESCAPE);
		
		switch(tecla)
		{
			case ARRIBA:
			{
				
				if((x2==px && y2==py)||(x2==px && y2!=py))
				{
					y2--;
					if(y2<dim && y2>=0)
						TextOut(mdc,(*(inic)),(y+(y2)*75+37),c.c_str(),c.length());
					else
						y2++;
				}
				else
				{
					COLOR = RGB(255,0,0);
					pintarCasillas((x+(x2)*75),(y+(y2)*75));
					std::this_thread::sleep_for(std::chrono::seconds(1));
					COLOR = RGB(0,255,243);
					pintarCasillas((x+(x2)*75),(y+(y2)*75));
					TextOut(mdc,(x+(x2)*75+37),(y+(y2)*75+37),c.c_str(),c.length());
					COLOR = RGB(0,0,0);
					dibujarBordes();
				}
				
				break;
			}
			case ABAJO:
			{
				if((x2==px && y2==py) ||(x2==px && y2!=py))
				{
					y2++;
					if(y2<dim && y2>=0)
						TextOut(mdc,(x+(x2)*75+37),(y+(y2)*75+37),c.c_str(),c.length());
					else
						y2--;
				}
				else
				{
					COLOR = RGB(255,0,0);
					pintarCasillas((x+(x2)*75),(y+(y2)*75));
					std::this_thread::sleep_for(std::chrono::seconds(1));
					COLOR = RGB(0,255,243);
					pintarCasillas((x+(x2)*75),(y+(y2)*75));
					TextOut(mdc,(x+(x2)*75+37),(y+(y2)*75+37),c.c_str(),c.length());
					COLOR = RGB(0,0,0);
					dibujarBordes();
				}
//				
				break;
			}
			case DERECHA:
			{
				if((x2==px && y2==py) || (x2!=px && y2==py))
				{
					x2++;
					if(x2<dim && x2>=0)
						TextOut(mdc,(x+(x2)*75+37),(*(inic+1)),c.c_str(),c.length());
					else
						x2--;
				}
				else
				{
					COLOR = RGB(255,0,0);
					pintarCasillas((x+(x2)*75),(y+(y2)*75));
					std::this_thread::sleep_for(std::chrono::seconds(1));
					COLOR = RGB(0,255,243);
					pintarCasillas((x+(x2)*75),(y+(y2)*75));
					TextOut(mdc,(x+(x2)*75+37),(y+(y2)*75+37),c.c_str(),c.length());
					COLOR = RGB(0,0,0);
					dibujarBordes();
				}
				break;
			}
			case IZQUIERDA:
			{
				if((x2==px && y2==py) || (x2!=px && y2==py))
				{
					x2--;
					
					if(x2<dim && x2>=0)
					{
						TextOut(mdc,(x+(x2)*75+37),(*(inic+1)),c.c_str(),c.length());
					}
					else
						x2++;
				}
				else
				{
					COLOR = RGB(255,0,0);
					pintarCasillas((x+(x2)*75),(y+(y2)*75));
					std::this_thread::sleep_for(std::chrono::seconds(1));
					COLOR = RGB(0,255,243);
					pintarCasillas((x+(x2)*75),(y+(y2)*75));
					TextOut(mdc,(x+(x2)*75+37),(y+(y2)*75+37),c.c_str(),c.length());
					COLOR = RGB(0,0,0);
					dibujarBordes();
				}
				break;
			}
			case ESCAPE:
			{
				HANDLE hcon;
				hcon = GetStdHandle(STD_OUTPUT_HANDLE);
				COORD pos;
				pos.X=2;
				pos.Y=40;
				SetConsoleCursorPosition(hcon,pos);
				cout<<"Gracias por jugar!\n";
				pos.X=2;
				pos.Y=41;
				SetConsoleCursorPosition(hcon,pos);
				cout<<"Presione cualquier tecla para salir.\n";
				break;
			}
		}
		
		
	}while(tecla!=ESCAPE);
	
	
}