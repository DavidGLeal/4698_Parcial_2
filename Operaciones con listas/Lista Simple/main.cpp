/*UFA-ESPE
* Deber 5
* Autores: Iza Christopher- Rea Denise
* Fecha de creación 25/05/2022
* Fecha de modificación 30/05/2022
* Grupo 20
* github del grupo @dnrea@espe.edu.ec @cdiza5@espe.edu.ec
*/
#include <iostream>
#include "Lista.cpp"
#include <stdlib.h>
#include "bits/stdc++.h"
#include <cstring>
using namespace std;
int main(int argc, char** argv) {
	Lista lst;
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
	cout<<"\n 8) Finalizar programa "<<endl;
	cout<<"\n Seleccione una opcion"<<endl;
//esto se valida tambien
	op = lst.ingresoDatosEnteros();
	}while(op<1 || op >8);
	system("cls");
		if(op==1){	
			lst.insertarCabezaEnteros();
			cout<<"\nPresione Doble Enter  para continuar...";
			getchar();
			getchar();
		}
		else if(op==2){
			lst.insertarColaEnteros();
			cout<<"\nPresione Doble Enter para continuar...";
			getchar();
			getchar();
		}
		else if(op==3){
			lst.mostrarCabeza();
			cout<<"Presione Doble Enter  para continuar...";
			getchar();
			getchar();
			}
		else if(op==4){
			lst.mostrarCola();
			cout<<"Presione Doble Enter para continuar...";
			getchar();
			getchar();
			}
		else if(op==5){
			lst.buscar();
			cout<<"Presione Doble Enter para continuar...";
			getchar();
			getchar();
			}
		else if(op==6){
			lst.eliminarCabeza();
			cout<<"Presione Doble Enter para continuar...";
			getchar();
			getchar();
		}
		else if(op==7){
			lst.eliminarCola();
			cout<<"Presione Doble Enter para continuar...";
			getchar();
			getchar();
		}
		else{	
			lst.~Lista();
			exit(0);
		}
		}while(op!=8);
	return 0;
}
