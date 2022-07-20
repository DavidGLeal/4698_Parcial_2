/*
Autores: Shared Tinoco, Sebastian Torres.
Fecha de creacion: 26/06/2022
Fecha de modificacion: 29/06/2022
Grupo 10
Github del grupo: mstinoco@espe.edu.ec, sptorres1@espe.edu.ec
*/

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include "Hash.cpp"
#include "HashStr.cpp"
#include "IngresoDatosEntero.cpp"
using namespace std;

#define Tecla_Arriba 72
#define Tecla_Abajo 80
#define Enter 13

void menuPrincipal();
int menu(const char *titulo,const char *opciones[],int n);
void gotoxy(int x,int y);

void menuPrincipal(){
	bool repetir=true;
	bool repetir2=true;
	bool repetir3=true;
    int opc;
    int opc2;
    int opc3;
    int valor;
    string dato;
    Hash HashEnt;
    HashStr HashStr;
    IngresoDatos ingreso;
    
    const char *titulo="MENU PRINCIPAL TABLAS HASH ABIERTAS";
    const char *opciones[]={"ENTEROS","STRINGS","Salir"};
    int n=3;
    const char *titulo2="ENTEROS";
    const char *titulo3="STRINGS";
    const char *opciones2[]={"Insertar","Eliminar","Buscar","Mostrar","Regresar"};
    int n2=5;
    
    do{
    	opc = menu(titulo,opciones,n);
        switch (opc){
        	case 1:
        		{
        			system("cls");
					do{
						repetir2=true;
						opc2 = menu(titulo2,opciones2,n2);
	       				switch (opc2){
							case 1:
								//Insertar
								system("cls");
								cout<<"\n\tInsertar Entero"<<endl;
								cout<<"\n\tIngrese el valor a ingresar: "<<endl;
								cout<<"\t"; valor=ingreso.convertirEntero();
								HashEnt.insertarElemento(valor);
								cout<<"\n"; 
								cout<<"\t";	system("pause");
							break;
							case 2:
								//Eliminar
								system("cls");
								HashEnt.mostrarHash();					
								cout<<"\n\n";
								cout<<"\n\tEliminar"<<endl;
								cout<<"\n\tIngrese el valor a eliminar: "<<endl;
								cout<<"\t"; valor=ingreso.convertirEntero();
								HashEnt.eliminarElemento(valor);
								cout<<"\n";
								cout<<"\t"; system("pause");
							break;
							case 3:
								//Buscar
								system("cls");
								HashEnt.mostrarHash();					
								cout<<"\n\n";
								cout<<"\n\tBuscar"<<endl;
								cout<<"\n\tIngrese el valor a buscar: "<<endl;
								cout<<"\t"; valor=ingreso.convertirEntero();
								HashEnt.buscarElemento(valor); 
								cout<<"\n";
								cout<<"\t"; system("pause");
							break;
							case 4:
								//Mostrar
								system("cls");
								cout<<"\n\tMostrar"<<endl;
								HashEnt.mostrarHash();
								cout<<"\n";
								cout<<"\t"; system("pause");
							break;  
							case 5:	
								repetir2=false; 
							break; 
						}	
					}while(repetir2);
					
				}
        	break;
        	case 2:
        		{
        			system("cls");
					do{
						repetir3=true;
						opc3 = menu(titulo3,opciones2,n2);
	       				switch (opc3){
							case 1:
								//Insertar
								system("cls");
								cout<<"\n\tInsertar String"<<endl;
								cout<<"\n\tIngrese el string a ingresar: "<<endl;
								cout<<"\t";cin>>dato;
								HashStr.insertarElemento(dato);
								cout<<"\n";
								cout<<"\t"; system("pause");
							break;
							case 2:
								//Eliminar
								system("cls");
								HashStr.mostrarHash();
								cout<<"\n\n";
								cout<<"\n\tEliminar"<<endl;
								cout<<"\n\tIngrese el string a eliminar: "<<endl;
								cout<<"\t";cin>>dato;
								HashStr.eliminarElemento(dato);
								cout<<"\n";
								cout<<"\t"; system("pause");
							break;
							case 3:
								//Buscar
								system("cls");
								HashStr.mostrarHash();
								cout<<"\n\n";
								cout<<"\n\tBuscar"<<endl;
								cout<<"\n\tIngrese el string a buscar: "<<endl;
								cout<<"\t";cin>>dato;
								HashStr.buscarElemento(dato); 
								cout<<"\n";
								cout<<"\t"; system("pause");
							break;
							case 4:
								//Mostrar
								system("cls");
								cout<<"\n\tMostrar"<<endl;
								HashStr.mostrarHash();
								cout<<"\n";
								cout<<"\t"; system("pause");
							break;  
							case 5:
                   				repetir3=false; 
							break; 
						}	
					}while(repetir3);	
				}
        	break;
        	case 3:
        		system("cls");
				cout<<"\n\t  HASTA PRONTO";
				repetir=false;
			break;	
		}	
	}while(repetir);
}




int menu(const char *titulo,const char *opciones[],int n){
    int opcSeleccionada=1;
    int tecla;
    bool repetir=true;
    do{
        system("cls");
        gotoxy(5,3+opcSeleccionada); cout<<"-->";
        gotoxy(15,2); cout<<titulo;
        for(int i=0;i<n;i++){
            gotoxy(10,4+i); cout<<i+1<<"."<<opciones[i];
        }

        do{
            tecla=getch();
        }while(tecla!=Tecla_Arriba && tecla!=Tecla_Abajo && tecla!=Enter);
        
        switch (tecla)
        {
        case Tecla_Arriba:
            opcSeleccionada--;
            if(opcSeleccionada<1){
               opcSeleccionada=n;
            }
            break;
        case Tecla_Abajo:
            opcSeleccionada++;
            if(opcSeleccionada>n){
               opcSeleccionada=1;
            }
            break;
        case Enter:
            repetir=false;
            break;
        }
    }while(repetir);


    return opcSeleccionada;

}

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
