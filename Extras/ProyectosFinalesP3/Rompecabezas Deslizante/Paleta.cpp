/*Universidad de las Fuerzas Armadas - ESPE
PROYECTO - Parcial 3: 
Por medio de un algoritmo de busqueda exhaustiva, ordenar una matriz de colores en función de sus códigos RGB.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 20/08/2022
FECHA DE MODIFICACIÓN: 23/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/

#pragma once
#include "Paleta.h"


Paleta::Paleta(int _dim)
{
	ShowWindow(miConsola,SW_SHOWMAXIMIZED);
	this->dim=_dim;
	this->xIn=100;
	this->yIn=200;
	this->paleta= new RGBcode*[dim];
	this->desorden= new RGBcode*[dim];
	this->comprob= new bool*[dim];
	this->paletita= new RGBcode*[dim];
	srand(time(NULL));
	for(int i=0;i<dim;i++)
	{
		(*(this->paleta+i)) = new RGBcode[dim];
		(*(this->desorden+i)) = new RGBcode[dim];
		(*(this->comprob+i)) = new bool[dim];
		(*(this->paletita+i)) = new RGBcode[dim];
	}
	falsificar();
}

Paleta::Paleta(int _dim,int _x,int _y)
{
	ShowWindow(miConsola,SW_SHOWMAXIMIZED);
	this->dim=_dim;
	this->xIn=_x;
	this->yIn=_y;
	this->paleta= new RGBcode*[dim];
	this->desorden= new RGBcode*[dim];
	this->comprob= new bool*[dim];
	srand(time(NULL));
	for(int i=0;i<dim;i++)
	{
		(*(this->paleta+i)) = new RGBcode[dim];
		(*(this->desorden+i)) = new RGBcode[dim];
		(*(this->comprob+i)) = new bool[dim];
	}
	falsificar();
}

int Paleta::getXIn()
{
	return xIn;
}
int Paleta::getYIn()
{
	return yIn;
}
int Paleta::getDim()
{
	return dim;
}

void Paleta::setDim(int d)
{
	dim=d;
}
void Paleta::setXIn(int nx)
{
	xIn=nx;
}
void Paleta::setYIn(int ny)
{
	yIn=ny;
}

void Paleta::crearPaleta(int excluido)
{


	int xaux=xIn,yaux=yIn;
	for(int i=0;i<dim;i++)
	{
		for(int j=0;j<dim;j++)
		{
			(*(*(paleta+i)+j)).setX(xaux);
			(*(*(paleta+i)+j)).setY(yaux+300);
			(*(*(desorden+i)+j)).setX(xaux);
			(*(*(desorden+i)+j)).setY(yaux);
			(*(*(paletita+i)+j)).setX(xaux);
			(*(*(paletita+i)+j)).setY(yaux);
			(*(*(paleta+i)+j)).setRad(20);
			(*(*(paletita+i)+j)).setRad(20);
			(*(*(desorden+i)+j)).setRad(20);
			yaux+=40;
		}
		xaux+=40;
		yaux=yIn;
		

	}
}

void Paleta::mostrarPaleta()
{
	gotoxy(62,8);
	std::cout<<"\t\tBIENVENIDO AL PROGRAMA DE TAKEN NxN";
	gotoxy(62,9);
	std::cout<<"\t\tREGLAS: ";
	gotoxy(62,10);
	std::cout<<"\t\t-Utilizando las flechas del teclado, puede mover los cuadros hacia el espacio en blanco.";
	gotoxy(62,11);
	std::cout<<"\t\t-Complete la figura superior como se indica en la figura de referencia.";
	gotoxy(62,13);
	std::cout<<"\t\tCONTROLES: ";
	gotoxy(62,14);
	std::cout<<"\t\t-Flecha arriba: Si presionas esta flecha en el teclado, ";
	gotoxy(62,15);
	std::cout<<"\t\tla pieza debajo del cuadro vacio se movera hacia arriba.";
	
	gotoxy(62,16);
	std::cout<<"\t\t-Flecha abajo: Si presionas esta flecha en el teclado, ";
	gotoxy(62,17);
	std::cout<<"\t\tla pieza sobre el cuadro vacio se movera hacia abajo.";
	
	gotoxy(62,18);
	std::cout<<"\t\t-Flecha derecha: Si presionas esta flecha en el teclado, ";
	gotoxy(62,19);
	std::cout<<"\t\tla pieza a la izquierda del cuadro vacio se movera hacia la derecha.";
	
	gotoxy(62,20);
	std::cout<<"\t\t-Flecha izquierda: Si presionas esta flecha en el teclado, ";
	gotoxy(62,21);
	std::cout<<"\t\tla pieza a la derecha del cuadro del cuadro vacio se movera hacia la izquierda.";
	
	gotoxy(62,22);
	std::cout<<"\t\t-ENTER: Presiona la tecla Enter cuando quieras comprobar si tu resolucion es correcta.";
	gotoxy(62,23);
	std::cout<<"\t\t-ESC: La tecla ESC termina el juego y regresa a la opcion anterior,";
	gotoxy(62,24);
	std::cout<<"\t\t donde puedes elegir otro color.";
	
	gotoxy(62,25);
	std::cout<<"\t\t-p: Generar PDF.";
	gotoxy(62,26);
	std::cout<<"\t\t-t: Generar .txt.";
	gotoxy(62,27);
	std::cout<<"\t\t-r: Recargar cuadros";
	gotoxy(62,28);
	std::cout<<"\t\t-b: Generar BackUp";
	gotoxy(62,29);
	std::cout<<"\t\t-c: Cargar BackUp";
	
	gotoxy(62,39);
	std::cout<<"\t\tMOVIMIENTOS: "<<movimientos;
	
	for(int i=0;i<dim;i++)
	{
		for(int j=0;j<dim;j++)
		{
			(*(*(desorden+j)+i)).mostrar();
		}
	}
}
void Paleta::mostrarCompleto()
{
	for(int i=0;i<dim;i++)
	{
		for(int j=0;j<dim;j++)
		{
			(*(*(paleta+j)+i)).mostrar();
		}
	}
}


void Paleta::degradar(int col)
{
	int roj=0,ver=0,azu=0,rojc=0,verc=0,azuc=0;
	int rojaux=0,veraux=0,azuaux=0;
	if(col==1)
	{
		roj=255;
		azuc=255;
	}
	else if(col==2)
	{
		ver=255;
		rojc=255;
	}
	else if(col==3)
	{
		azu=255;
		verc=255;
	}
	
	(*(*(paleta))).setColor(roj,ver,azu);
	
	rojaux=roj;
	azuaux=azu;
	veraux=ver;
	
	for(int i=1;i<dim;i++)
	{
		if(i!=dim-1)
		{
			if(col==1)
			{
				rojaux-=(255/(2*(dim-1)));
				azuaux+=(255/(2*(dim-1)));
			}
			else if(col==2)
			{
				veraux-=(255/(2*(dim-1)));
				rojaux+=(255/(2*(dim-1)));
			}
			else if(col==3)
			{
				azuaux-=(255/(2*(dim-1)));
				veraux+=(255/(2*(dim-1)));
			}
		}
		else
		{
			rojaux=roj;
			azuaux=azu;
			veraux=ver;
			if(col==1)
			{
				rojaux-=(255/(2));
				azuaux+=(255/(2));
			}
			else if(col==2)
			{
				veraux-=(255/(2));
				rojaux+=(255/(2));
			}
			else if(col==3)
			{
				azuaux-=(255/(2));
				veraux+=(255/(2));
			}
		}
		
			
		(*(*(paleta)+i)).setColor(rojaux,veraux,azuaux);
		(*(*(paleta+i))).setColor(rojaux,veraux,azuaux);
	}
		
	rojaux=roj;
	azuaux=azu;
	veraux=ver;
	
	for(int j=1;j<dim;j++)
	{
		rojaux=(*(*(paleta+j))).getR();
		azuaux=(*(*(paleta+j))).getB();
		veraux=(*(*(paleta+j))).getG();
		for(int i=1;i<dim;i++)
		{
			if(col==1)
			{
				rojaux-=(255/(2*(dim-1)));
				azuaux+=(255/(2*(dim-1)));
			}
			else if(col==2)
			{
				veraux-=(255/(2*(dim-1)));
				rojaux+=(255/(2*(dim-1)));
			}
			else if(col==3)
			{
				azuaux-=(255/(2*(dim-1)));
				veraux+=(255/(2*(dim-1)));
			}
			
			(*(*(paleta+i)+j)).setColor(rojaux,veraux,azuaux);
			
		}
	}
	
	(*(*(paleta+dim-1)+dim-1)).setColor(255,255,255);
}

void Paleta::falsificar()
{
	for(int x=0;x<dim;x++)
	{
		for(int y=0;y<dim;y++)
		{
			(*(*(comprob+y)+x)) = false;
		}
	}
}

void Paleta::clonar()
{
	int contador=0;
	int x=0,y=0;
	int xaux,yaux;
	int rojo,azul,verde;
	bool alit;
	srand(time(NULL));
	while(contador<(dim*dim))
	{
		alit=false;
		xaux=rand()%dim;
		yaux=rand()%dim;
		
		if((*(*(comprob+yaux)+xaux))==false)
		{
			(*(*(desorden+yaux)+xaux)).setR((*(*(paleta+x)+y)).getR());
			(*(*(desorden+yaux)+xaux)).setG((*(*(paleta+x)+y)).getG());
			(*(*(desorden+yaux)+xaux)).setB((*(*(paleta+x)+y)).getB());
			(*(*(comprob+yaux)+xaux))=true;
			alit=true;
			if(x<dim-1)
			{
				x++;
			}
			else
			{
				x=0;
				if(y<dim-1)
				{
					y++;
				}
			}
			
		}
		
		if(alit)
			contador++;
	}
	xW=xaux;
	yW=yaux;
}

void Paleta::jugar()
{
	int xa,ya;
	int tecla;
	mostrarCompleto();
	ocultarCursor();
	while(tecla!=ESCAPE)
	{
		mostrarPaleta();
		xa=xW;
		ya=yW;
		do
		{
			tecla=getch();
		}while(tecla!=TECLA_ARRIBA && tecla!=TECLA_ABAJO && tecla!=TECLA_IZQUIERDA && tecla!=TECLA_DERECHA
		&& tecla!=ENTER && tecla !=ESCAPE && tecla !=T && tecla !=B && tecla !=P && tecla !=R && tecla !=C);
		
		switch(tecla)
		{
			case TECLA_ARRIBA:
			{
				if(xW+1<dim)
				{
					movimientos++;
					xW++;
				}
					
				break;
			}
			case TECLA_ABAJO:
			{
				if(xW-1>=0)
				{
					movimientos++;
					xW--;
				}
				break;
			}
			case TECLA_DERECHA:
			{
				if(yW-1>=0)
				{
					movimientos++;
					yW--;
				}				
				break;
			}
			case TECLA_IZQUIERDA:
			{
				if(yW+1<dim)
				{
					movimientos++;
					yW++;
				}
				break;
			}
			case ENTER:
			{
				if(comprobar())
				{
					gotoxy(62,30);
					std::cout<<"\t\tFelicidades!";
					gotoxy(62,31);
					std::cout<<"\t\tHa completado el puzzle exitosamente.";
					gotoxy(69,32);
					system("pause"); 
					system("cls");
					mostrarCompleto();
				}else{
					gotoxy(62,30);
					std::cout<<"\t\tLo sentimos!";
					gotoxy(62,31);
					std::cout<<"\t\tNo ha completado el puzzle exitosamente.";
					gotoxy(69,32);
					system("pause"); 
					system("cls");
					mostrarCompleto();
				}
				break;
			}
			case T:
			{
				generarArchivosTxT();
				gotoxy(62,32);
				system("pause"); 
				system("cls");
				mostrarCompleto();
				break;	
			}
			case P:
			{
				generarArchivosPDF("RGB.pdf");
				gotoxy(62,32);
				system("pause"); 
				system("cls");
				mostrarCompleto();
				break;	
			}
			case B:
			{
				generarBackup();
				gotoxy(62,32);
				system("pause"); 
				system("cls");
				mostrarCompleto();
				break;	
			}
			case C:
			{
				leerBackup();
				xW=xNueva;
				xa=xNueva;
				yW=yNueva;
				ya=yNueva;
				gotoxy(62,32);
				system("pause"); 
				system("cls");
				mostrarCompleto();
				break;	
			}
			case R:
			{ 
				system("cls");
				mostrarCompleto();
				break;	
			}
		}
		
		(*(*(desorden+ya)+xa)).setR((*(*(desorden+yW)+xW)).getR());
		(*(*(desorden+ya)+xa)).setG((*(*(desorden+yW)+xW)).getG());
		(*(*(desorden+ya)+xa)).setB((*(*(desorden+yW)+xW)).getB());
		
		(*(*(desorden+yW)+xW)).setColor(255,255,255);	
	}
}

bool Paleta::comprobar()
{
	for(int i=0;i<dim;i++)
	{
		for(int j=0;j<dim;j++)
		{
			if(((*(*(desorden+i)+j)).getR()!=(*(*(paleta+i)+j)).getR()) && ((*(*(desorden+i)+j)).getG()!=(*(*(paleta+i)+j)).getG()) && ((*(*(desorden+i)+j)).getB()!=(*(*(paleta+i)+j)).getB()))
			{
				return false;
				break;
			}
		}
	}
	return true;
}
void Paleta::solucionar()
{
	int x=0,y=0;
	for(int i=0;i<dim;i++)
	{
		for(int j=0;j<dim;j++)
		{
			if(((*(*(desorden+j)+i)).getR()==(*(*(paleta+y)+x)).getR()) && ((*(*(desorden+j)+i)).getG()==(*(*(paleta+y)+x)).getG()) && ((*(*(desorden+j)+i)).getB()==(*(*(paleta+y)+x)).getB()))
			{
				xB=i;
				yB=j;
				xL=x;
				yL=y;
				
				if(y<dim-1)
				{
					y++;
				}
				else
				{
					y=0;
					if(x<dim-1)
					{
						x++;
					}else
					{
						x=0;
						y=0;
					}
				}
				break;
			}
		}
	}
	//mover();
	if(comprobar())
	{
		return;
	}
	
}
void Paleta::mover()
{
	bool encima=false,derecha=false;
	int xa,ya;
	if(xB>=1)
	{
		while(!encima)
		{
			mostrarPaleta();
			xa=xW;
			ya=yW;
			if(xB==xL)
			{
				encima=true;
			}else if(xW==xB-1)
			{
				if(yW==yB)
				{
					xW++;
					xB--;
				}
				else if(yW>yB)
				{
					yW--;
				}else
				{
					yW++;
				}
			}else if(xW==xB)
			{
				xW--;
			}else if(xW>xB)
			{
				if(yW==yB)
				{
					if(yW==dim-1)
					{
						yW--;
					}else{
						yW++;
					}
				}else
				{
					xW--;	
				}
			}else{
				xW++;
			}
			(*(*(desorden+ya)+xa)).setR((*(*(desorden+yW)+xW)).getR());
			(*(*(desorden+ya)+xa)).setG((*(*(desorden+yW)+xW)).getG());
			(*(*(desorden+ya)+xa)).setB((*(*(desorden+yW)+xW)).getB());
		
			(*(*(desorden+yW)+xW)).setColor(255,255,255);
			cin.ignore();
		}
	}
	if(yB>=1)
	{
		while(!derecha)
		{
			mostrarPaleta();
			xa=xW;
			ya=yW;
			if(yB==yL)
			{
				derecha=true;
			}else if(yW==yB-1)
			{
				if(xW==xB)
				{
					yW++;
					yB--;
				}
				else if(xW>xB)
				{
					xW--;
				}else
				{
					xW++;
				}
			}else if(yW==yB)
			{
				yW--;
			}else if(yW>yB)
			{
				if(xW==xB)
				{
					if(xW==0)
					{
						xW++;
					}else{
						xW--;
					}
				}else
				{
					yW--;	
				}
			}else{
				yW++;
			}
			(*(*(desorden+ya)+xa)).setR((*(*(desorden+yW)+xW)).getR());
			(*(*(desorden+ya)+xa)).setG((*(*(desorden+yW)+xW)).getG());
			(*(*(desorden+ya)+xa)).setB((*(*(desorden+yW)+xW)).getB());
		
			(*(*(desorden+yW)+xW)).setColor(255,255,255);
			cin.ignore();
		}
	}
//	mostrarPaleta();
//	cin.ignore();
}


void Paleta::gotoxy(int x, int y)
{
   	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	
	SetConsoleCursorPosition(hCon, dwPos);
}
void Paleta::ocultarCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
void Paleta::generarArchivosTxT()
{
	ofstream archivo;
	string dirS;
	gotoxy(62,30);
	cout<<"Ingrese la direccion en la que desea que se genere el archivo: ";
	getline(cin,dirS);
	char *dir=new char[1000];
	memmove(dir,dirS.c_str(),dirS.length());
	int aux2=dirS.length()+1,j=0;
	char aux1[1000];
	for(int i=0;i<=aux2;i++)
	{
		if(dir[i]=='\\')
		{
			for(int k=i+1;k<=aux2;k++)
			{
				aux1[j]=dir[k];
				j++;
			}
			dir[i]='/';
			dir[i+1]='/';
			aux2++;
			j=0;
			for(int l=i+2;l<=aux2;l++)
			{
				dir[l]=aux1[j];
				j++;
			}
			j=0;
		}
	}	
	string dirSR(dir);
	dirSR+="//matriz.txt";
	escribirArchivo(archivo,dirSR);
	gotoxy(62,31);
	cout<<"Archivo de texto generado con exito en la direccion: "<<dirSR;
}
void Paleta::escribirArchivo(ofstream &archi, string dirSR)
{
	archi.open(dirSR,ios::out);
	if(archi.fail()){
		gotoxy(62,30);
        cout<<"Se ha producido un error al crear el archivo";
        return;
    }
	for(int i=0;i<dim;i++)
	{
		for(int j=0;j<dim;j++)
		{
			archi<<" Rojo: "<<(*(*(desorden+j)+i)).getR()<<"\t";
		}
		archi<<"\n";
		for(int j=0;j<dim;j++)
		{
			archi<<" Verde: "<<(*(*(desorden+j)+i)).getG()<<"\t";
		}
		archi<<"\n";
		for(int j=0;j<dim;j++)
		{
			archi<<" Azul: "<<(*(*(desorden+j)+i)).getB()<<"\t";
		}
		archi<<"\n\n";
	}
	archi.close();
}
void Paleta::generarBackup()
{
	time_t t;
    t=time(NULL);
    struct tm *f;
    f=localtime(&t);

    int dd,mm,aaaa,hora,min;
    dd=f->tm_mday;
    mm=f->tm_mon+1;
    aaaa=f->tm_year+1900;
    hora=f->tm_hour;
    min=f->tm_min;

    string linea;
    string txt;
    string fecha;
    string aaaa1=(to_string(aaaa));
    string mm1=(to_string(mm));
    string dd1=(to_string(dd));
    string h1=(to_string(hora));
    string m1=(to_string(min));
	fecha = "Respaldos\\"+dd1+"-"+mm1+"-"+aaaa1+"-"+h1+"h"+m1+"m"+"Backup"+".txt";

    ofstream backup;
    backup.open(fecha);
	for(int i=0;i<dim;i++)
	{
		for(int j=0;j<dim;j++)
		{
			backup<<(*(*(desorden+j)+i)).getR();
			backup<<"\n";
			backup<<(*(*(desorden+j)+i)).getG();
			backup<<"\n";
			backup<<(*(*(desorden+j)+i)).getB();
			backup<<"\n";
		}
	}
	
	for(int i=0;i<dim;i++)
	{
		for(int j=0;j<dim;j++)
		{
			backup<<(*(*(paleta+j)+i)).getR();
			backup<<"\n";
			backup<<(*(*(paleta+j)+i)).getG();
			backup<<"\n";
			backup<<(*(*(paleta+j)+i)).getB();
			backup<<"\n";
		}
	}
    backup.close();
    gotoxy(62,29);
	cout<<"Archivo de texto generado con exito en la direccion: "<<fecha;
}
void Paleta::leerBackup()
{
	ofstream archivo;
	string dirS;
	gotoxy(62,30);
	cout<<"Ingrese la direccion en la que desea que se genere el archivo: ";
	getline(cin,dirS);
	char *dir=new char[500];
	memmove(dir,dirS.c_str(),dirS.length());
	int aux2=dirS.length()+1,j=0;
	char aux1[500];
	for(int i=0;i<=aux2;i++)
	{
		if(dir[i]=='\\')
		{
			for(int k=i+1;k<=aux2;k++)
			{
				aux1[j]=dir[k];
				j++;
			}
			dir[i]='/';
			dir[i+1]='/';
			aux2++;
			j=0;
			for(int l=i+2;l<=aux2;l++)
			{
				dir[l]=aux1[j];
				j++;
			}
			j=0;
		}
	}	
	string dirSR(dir),linea;
	int o=0,apNum=0,roj,azu,ver,k=0,l=0,idk=0;
	
	ifstream archivo1(dirSR.c_str());
	gotoxy(0,31);
	while(getline(archivo1, linea))
	{
		char *cline=new char[10];
		memmove(cline,linea.c_str(),linea.length());
		if(o==0)
		{
			roj=atoi(cline);
			o++;
		}else if(o==1)
		{
			ver=atoi(cline);
			o++;
		}else if(o==2)
		{
			o=0;
			azu=atoi(cline);
			if(apNum<dim*dim)
			{
				(*(*(desorden+l)+k)).setColor(roj,ver,azu);
				if(roj==255 && ver==255 && azu==255)
				{
					xNueva=l;
					yNueva=k;
				}
			}else
			{
				(*(*(paleta+l)+k)).setColor(roj,ver,azu);
			}
			if(l<dim-1)
			{
				l++;
			}else
			{
				l=0;
				if(k<dim-1)
				{
					k++;
				}else
				{
					l=0;
					k=0;
				}
			}
			apNum++;
		}
	}
}
void Paleta::pintarBlanco(int xa, int ya, int _xW, int _yW){
	// xW=_xW;
	// yW=_yW;
	// de donde a donde
	(*(*(paletita+ya)+xa)).setR((*(*(paletita+_yW)+_xW)).getR());
	(*(*(paletita+ya)+xa)).setG((*(*(paletita+_yW)+_xW)).getG());
	(*(*(paletita+ya)+xa)).setB((*(*(paletita+_yW)+_xW)).getB());
	(*(*(paletita+_yW)+_xW)).setColor(255,255,255);
	for(int i=0;i<dim;i++)
	{
		for(int j=0;j<dim;j++)
		{
			(*(*(paletita+j)+i)).mostrar();
		}
	}
	cin.ignore();
}
void Paleta::escribir(int op)
{

	switch(op)
	{
		case 1:
		{ //azul
	
			(*(*(paletita+0)+0)).setColor(0,127,127);
			(*(*(paletita+1)+0)).setColor(255,255,255);
			(*(*(paletita+2)+0)).setColor(0,191,63);
			(*(*(paletita+0)+1)).setColor(0,63,191);
			(*(*(paletita+1)+1)).setColor(0,0,255);
			(*(*(paletita+2)+1)).setColor(0,127,127);
			(*(*(paletita+0)+2)).setColor(0,191,63);
			(*(*(paletita+1)+2)).setColor(0,63,191);
			(*(*(paletita+2)+2)).setColor(0,127,127);
			//(int _xa, int _ya, int _xW, int _yW)
			for(int i=0;i<dim;i++)
			{
				for(int j=0;j<dim;j++)
				{
					(*(*(paletita+j)+i)).mostrar();
				}
			}
			cin.ignore();
			pintarBlanco(0, 1, 1, 1);
			pintarBlanco(1,1,1,0);
			pintarBlanco(1,0,0,0);
			pintarBlanco(0,0,0,1);
			pintarBlanco(0,1,1,1);
			pintarBlanco(1,1,2,1);
			pintarBlanco(2,1,2,0);
			pintarBlanco(2,0,1,0);
			pintarBlanco(1,0,1,1);
			pintarBlanco(1,1,0,1);
			pintarBlanco(0,1,0,2);
			pintarBlanco(0,2,1,2);
			pintarBlanco(1,2,1,1);
			pintarBlanco(1,1,0,1);
			pintarBlanco(0,1,0,2);
			pintarBlanco(0,2,1,2);
			pintarBlanco(1,2,2,2);
			pintarBlanco(2,2,2,1);
			pintarBlanco(2,1,1,1);
			pintarBlanco(1,1,1,2);
			pintarBlanco(1,2,0,2);
			pintarBlanco(0,2,0,1);
			pintarBlanco(0,1,1,1);
			pintarBlanco(1,1,1,2);
			pintarBlanco(1,2,0,2);
			pintarBlanco(0,2,0,1);
			pintarBlanco(0,1,1,1);
			pintarBlanco(1,1,1,2);
			pintarBlanco(1,2,2,2);
			cin.ignore();
			break;
		}
		case 2:
		{//rojo
			(*(*(paletita+0)+0)).setColor(191,0,63);
			(*(*(paletita+1)+0)).setColor(127,0,127);
			(*(*(paletita+2)+0)).setColor(255,255,255);
			(*(*(paletita+0)+1)).setColor(127,0,127);
			(*(*(paletita+1)+1)).setColor(255,0,0);
			(*(*(paletita+2)+1)).setColor(63,0,191);
			(*(*(paletita+0)+2)).setColor(63,0,191);
			(*(*(paletita+1)+2)).setColor(127,0,127);
			(*(*(paletita+2)+2)).setColor(191,0,63);
			
			for(int i=0;i<dim;i++)
			{
				for(int j=0;j<dim;j++)
				{
					(*(*(paletita+j)+i)).mostrar();
				}
			}
			cin.ignore();
			pintarBlanco(0,2,0,1);
			pintarBlanco(0,1,1,1);
			pintarBlanco(1,1,1,0);
			pintarBlanco(1,0,0,0);
			pintarBlanco(0,0,0,1);
			pintarBlanco(0,1,1,1);
			pintarBlanco(1,1,2,1);
			pintarBlanco(2,1,2,2);
			pintarBlanco(2,2,1,2);
			pintarBlanco(1,2,1,1);
			pintarBlanco(1,1,2,1);
			pintarBlanco(2,1,2,2);
			pintarBlanco(2,2,1,2);
			pintarBlanco(1,2,0,2);
			pintarBlanco(0,2,0,1);
			pintarBlanco(0,1,1,1);
			pintarBlanco(1,1,1,2);
			pintarBlanco(1,2,2,2);
			pintarBlanco(2,2,2,1);
			pintarBlanco(2,1,1,1);
			pintarBlanco(1,1,1,2);
			pintarBlanco(1,2,2,2);
			pintarBlanco(2,2,2,1);
			pintarBlanco(2,1,2,0);
			pintarBlanco(2,0,1,0);
			pintarBlanco(1,0,1,1);
			pintarBlanco(1,1,2,1);
			pintarBlanco(2,1,2,2);
			pintarBlanco(2,2,1,2);
			pintarBlanco(1,2,1,1);
			pintarBlanco(1,1,1,0);
			pintarBlanco(1,0,2,0);
			pintarBlanco(2,0,2,1);
			pintarBlanco(2,1,2,2);

			cin.ignore();
			break;
		}
		case 3:
		{ //verde
			(*(*(paletita+0)+0)).setColor(127,127,0);
			(*(*(paletita+1)+0)).setColor(63,191,0);
			(*(*(paletita+2)+0)).setColor(63,191,0);
			(*(*(paletita+0)+1)).setColor(127,127,0);
			(*(*(paletita+1)+1)).setColor(191,63,0);
			(*(*(paletita+2)+1)).setColor(0,255,0);
			(*(*(paletita+0)+2)).setColor(255,255,255);
			(*(*(paletita+1)+2)).setColor(191,63,0);
			(*(*(paletita+2)+2)).setColor(127,127,0);
			
			for(int i=0;i<dim;i++)
			{
				for(int j=0;j<dim;j++)
				{
					(*(*(paletita+j)+i)).mostrar();
				}
			}
			cin.ignore();
			pintarBlanco(2,0,1,0);
			pintarBlanco(1,0,0,0);
			pintarBlanco(0,0,0,0);
			pintarBlanco(0,0,0,1);
			pintarBlanco(0,1,0,2);
			pintarBlanco(0,2,1,2);
			pintarBlanco(1,2,1,1);
			pintarBlanco(1,1,0,1);
			pintarBlanco(0,1,0,2);
			pintarBlanco(0,2,1,2);
			pintarBlanco(1,2,1,1);
			pintarBlanco(1,1,1,0);
			pintarBlanco(1,0,0,0);
			pintarBlanco(0,0,0,1);
			pintarBlanco(0,1,1,1);
			pintarBlanco(1,1,1,2);
			pintarBlanco(1,2,0,2);
			pintarBlanco(0,2,0,1);
			pintarBlanco(0,1,1,1);
			pintarBlanco(1,1,2,1);
			pintarBlanco(2,1,2,2);
			pintarBlanco(2,2,1,2);
			pintarBlanco(1,2,1,1);
			pintarBlanco(1,1,2,1);
			pintarBlanco(2,1,2,2);

			break;
		}
	}
	for(int i=0;i<dim;i++)
	{
		for(int j=0;j<dim;j++)
		{
			(*(*(paletita+j)+i)).mostrar();
		}
	}
	cin.ignore();
}
void Paleta::generarArchivosPDF(string nombre)
{
	PDF p;
    p.setFont(PDF::HELVETICA_BOLD,30);
	p.showTextXY("TAKEN",230,746);  
	p.setFont(PDF::HELVETICA,10);
	p.showTextXY("Grupo 5",50,699);
	p.showTextXY("David Guarderas, Mathias Guevara",50,679);
	p.showTextXY("Shared Tinoco, Sebastian Torres",50,659);
    p.showTextXY("Datos RGB:",50,546);
    string linea, texto;
    int y=516;
    int x=50;
    ifstream original("matriz.txt");
    while (getline(original, linea))
    {
        p.showTextXY(linea,x,y);
        y-=15;
    }
    original.close();
	string errMsg;
	 if (!p.writeToFile(nombre, errMsg))
    {
        cout << errMsg << endl;
    }
    else
    {
        cout << "(File Successfully Written)" << endl;
    }

    cout << endl;
	
	gotoxy(62,31);
    cout<<"Archivo PDF generado correctamente";
    cout << endl;
}