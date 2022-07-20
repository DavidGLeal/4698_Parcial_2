#include <iostream>
#include "ListaDoble.cpp"
#include <stdlib.h>
#include "bits/stdc++.h"
#include <cstring>
using namespace std;
#include "movimiento.h"


 movimiento::movimiento(){
	
}
void movimiento::menu(){
    ListaDoble* lst = new ListaDoble();
	int op=0;
	do{
	do{
	system("cls");
	cout<<"Escoja: ";
	cout<<"\n 1) Insertar por Cabeza "<<endl;
	cout<<"\n 2) Insertar por Cola "<<endl;
	cout<<"\n 3) Mostrar por Cabeza "<<endl;
	cout<<"\n 4) Mostrar por Cola "<<endl;
	cout<<"\n 5) Buscar elemento "<<endl;
	cout<<"\n 6) Eliminar por Cabeza"<<endl;
	cout<<"\n 7) Eliminar por Cola "<<endl;
	cout<<"\n 8) Insertar entre "<<endl;
	cout<<"\n 9) Eliminar Entre "<<endl;
	cout<<"\n 10) Finalizar programa "<<endl;
	cout<<"\n Seleccione una opcion"<<endl;
//esto se valida tambien
	op = lst->ingresoDatosEnteros();
	}while(op<1 || op >10);
	system("cls");
		if(op==1){	
			lst->insertarCabezaEnteros();
			cout<<"\nPresione Doble Enter  para continuar...";
			getchar();
			getchar();
		}
		else if(op==2){
			lst->insertarColaEnteros();
			cout<<"\nPresione Doble Enter para continuar...";
			getchar();
			getchar();
		}
		else if(op==3){
			lst->mostrarCabeza(0);
			cout<<"Presione Doble Enter  para continuar...";
			getchar();
			getchar();
			}
		else if(op==4){
			lst->mostrarCabeza(1);
			cout<<"Presione Doble Enter para continuar...";
			getchar();
			getchar();
			}
		else if(op==5){
			lst->buscar();
			cout<<"Presione Doble Enter para continuar...";
			getchar();
			getchar();
			}
		else if(op==6){
			lst->eliminarCabeza();
			cout<<"Presione Doble Enter para continuar...";
			getchar();
			getchar();
		}
		else if(op==7){
			lst->eliminarCola();
			cout<<"Presione Doble Enter para continuar...";
			getchar();
			getchar();
		}
		else if(op==8){
			lst->insertarEntre();
			cout<<"Presione Doble Enter para continuar...";
			getchar();
			getchar();
		}
		else if(op==9){
			lst->eliminarEntre();
			cout<<"Presione Doble Enter para continuar...";
			getchar();
			getchar();
		}
		else{	
			lst->~ListaDoble();
			exit(0);
		}
		}while(op!=10);
	
}

