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
	cout<<"\n 1) Insertar  "<<endl;
	cout<<"\n 2) Eliminar "<<endl;
	cout<<"\n 3) Mostrar  "<<endl;
	cout<<"\n 4) Buscar  "<<endl;
	cout<<"\n 5) Finalizar programa "<<endl;
	cout<<"\n Seleccione una opcion"<<endl;
//esto se valida tambien
	op = lst.ingresoDatosEnteros();
	}while(op<1 || op >5);
	system("cls");
		if(op==1){	
			lst.insertarColaEnteros();
			cout<<"\nPresione Doble Enter  para continuar...";
			getchar();
			getchar();
		}
		else if(op==2){
			lst.eliminar();
			cout<<"\nPresione Doble Enter para continuar...";
			getchar();
			getchar();
		}
		else if(op==3){
			lst.mostrar();
			cout<<"\nPresione Doble Enter  para continuar...";
			getchar();
			getchar();
			}
		else if(op==4){
			lst.buscar();
			cout<<"\nPresione Doble Enter para continuar...";
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