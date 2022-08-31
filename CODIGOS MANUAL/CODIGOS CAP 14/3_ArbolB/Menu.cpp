#include <windows.h>
#include "Menu.h"
#include "ArbolB.cpp" 
#include "Complemento.cpp"
#pragma once
#include <iostream>
#include <sstream>
#include <limits>
#include <vector>
using std::string; using std::vector;
using std::cout; using std::endl;
using std::cin; using std::numeric_limits;

void Menu::menuArbol(){


    Complemento s, n;
    bool repite = true;
	ArbolB A;
	int opc2=0;
   	const char *titulo5 = "****  A R B O L  B ****";
   	const char *opciones5[] = {"Establecer Orden","Regresar"};
   	int n5 = 2; // Número de opciones
	do{
		 opc2 = n.menu(titulo5, opciones5, n5);
         system("cls");
		    switch(opc2) 
			{
			
			 case 1:{
			 	 menuOrden();
				break;
			 }
			 case 2:{
			 	 repite = false;
				break;
			 }
			
		}// switch principal
		    
	
	}while(repite);

}
//*****************************************
int Menu::menu(){
	
	int eleccion;
	do{
		system("cls");
	    cout<<"\t>> ARBOL B <<"<<endl<<endl;
	    cout<<" 1. AGREGAR NUMERO POR TECLADO."<<endl;
	    cout<<" 2. MOSTRAR 'LISTA DE NUMEROS'."<<endl;
	    cout<<" 3. MOSTRAR 'GRAFICO'."<<endl;
		cout<<" 4. BORRAR NUMERO DEL ARBOL."<<endl;
	    cout<<" 5. REINICIAR PROGRAMA."<<endl;
	    cout<<" 6. SUMAR PRIMOS"<<endl;
		cout<<" 7. SALIR."<<endl<<endl;
		cout<<"\t>>Ingrese su eleccion: ";
	    cin>>eleccion;
	}while(eleccion<1 || eleccion>9);
	return eleccion;
}
//animacion de reinicio XD
void Menu::animarReinicio(){
	cout<<"Reiniciando..."<<endl<<endl;
	cout<<"\t";
	for(int i=0;i<=100;i+=2){
		cout<<char(178);
		if(i<10)cout<<i<<" %"<<"\b\b\b";
		else cout<<i<<" %"<<"\b\b\b\b";
		Sleep(20);
		/*cout<<"\t"<<i<<" %";
		system("cls");*/	
	}
}
///////////////////////////////// MENU ORDEN //////////////////////////////////////////////
void Menu::menuOrden(){
	int opc=0;
    Complemento s;
    bool repite = true;
	const char *titulo4 = "****  A R B O L  B ****";
   	const char *opciones4[] = {"Agregar por teclado","Imprimir elementos Inorden","Grafico","Borrar Numero","Reiniciar programa","Sumar Primos del arbol","Regresar"};
	int n4 = 7;
    int orden;
	int numero;//para agregar
	ArbolB A;
	

    do{
		
			while (true) {
			system("cls");
			cout<<"\t****  A R B O L  B ****"<<endl;
			cout<<"\t\n\n Ingrese el orden a partir del 3\n\n";
			  cout<<"ORDEN DEL ARBOL: ";
			//cin>>orden;
			 if (cin >> orden) {
                       break;
                      } else {
                        cout << "Ingrese solo numeros!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                        system("cls");
                            }
		}
		
		}while(orden<3 || orden>10);
		A.ponerOrden(orden);
		do{
			
			 opc=s.menu(titulo4,opciones4,n4);
         system("cls");


        switch(opc) {
            case 1:{
                
                    cout<<"\tAGREGAR POR TECLADO"<<endl<<endl;
				
					    while (true) {
                       	cout<<"Numero: "; 
                       if (	cin>>numero) {
                       	A.agregar(numero);
                       	A.ponerNivelArbol();
                       break;
                      } else {
                        cout << "Ingrese solo numeros!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                        system("cls");
                            }
                        
					//cout<<endl<<endl;
					system("pause");
                   }
				
				
                break;
            }
         
			case 2:{
				cout<<"\tPINTAR LISTA"<<endl<<endl;
					A.pintar();
					cout<<endl<<endl;
					system("pause");
				break;
			}
			case 3:{
					cout<<"\tFGrafico"<<endl<<endl;
					A.ponerNivelArbol();
					A.pintarArbol();
					cout<<"\n\n\t\t------------------- GRAFICO -------------------\n\n";
					A.graficarArbol();
					cout<<endl<<endl;
					system("pause");
				break;
			}
			case 4:{
			
			
					        while (true) {
					    cout<<"\tBORRAR NUMERO"<<endl<<endl;
                      	cout<<"Numero a borrar: ";
                       if (	cin>>numero) {
                       break;
                      } else {
                        cout << "Ingrese solo numeros!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                        system("cls");
                        }
                            	system("pause");
                   }
					 
					//ponerle a la de borrar que sea bool para poder usar esto
					if( A.borrar(numero) ) cout<<"Numero "<<numero<<" borrado!";
					else cout<<"Numero no encontrado...";
					cout<<endl<<endl;
					A.ponerNivelArbol();
				break;
			}

			case 5:{
					cout<<"\tREINICIAR PROGRAMA"<<endl<<endl;
					A.destructorCopia();
					animarReinicio();
					cout<<endl<<endl;
					system("pause");
					break;
				}
				
			case 6:{
				cout<<"\tIMPRIMIR SUMA"<<endl<<endl;
				A.sumarPrimos();
				cout<<endl<<endl;
				system("pause");
				break;
			}
            case 7:{
            	repite = false;
                   break;
                // menu ventas         
            }
  		 }
		}while(repite);
}
